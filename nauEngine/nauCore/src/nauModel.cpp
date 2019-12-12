/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauModel.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief Model member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauModel.h"

#include "nauComponent.h"
#include "nauAnimator.h"

namespace nauEngineSDK {

  bool
  Model::hasBones() {
    return m_hasBones;
  }

  void
  Model::drawMesh() {
    for (auto& mesh : m_meshes) {

      SamplerState* sampler = g_graphicsAPI->getDevice()->createSamplerState();
      sampler->createSampler(m_device);
      sampler->setSampler(m_device);
      (mesh->m_material)->getMaterial(MATERIAL_FLAG::BASECOLOR)->m_shaderResourceView->setShaderResourceView(m_device); 
      if (mesh->m_material->m_metal && (mesh->m_material)->getMaterial(MATERIAL_FLAG::EMISSIVE) != nullptr) {
        (mesh->m_material)->getMaterial(MATERIAL_FLAG::METAL)->m_shaderResourceView->setShaderResourceView(m_device, 1);
      }
      if (mesh->m_material->m_roughness && (mesh->m_material)->getMaterial(MATERIAL_FLAG::EMISSIVE) != nullptr) {
        (mesh->m_material)->getMaterial(MATERIAL_FLAG::NORMAL)->m_shaderResourceView->setShaderResourceView(m_device, 2);
      }
      if (mesh->m_material->m_roughness && (mesh->m_material)->getMaterial(MATERIAL_FLAG::EMISSIVE) != nullptr) {
        (mesh->m_material)->getMaterial(MATERIAL_FLAG::EMISSIVE)->m_shaderResourceView->setShaderResourceView(m_device, 3);
      }
      mesh->draw(m_device);
    }
  } 

  void
  Model::setDevice(Device* dev) {
    m_device = dev;
  }

  void
  Model::loadFromFile(String filePath) {

    Assimp::Importer modelImport;
    uint32 assimpFlags = aiProcessPreset_TargetRealtime_MaxQuality |
                         aiProcess_ConvertToLeftHanded;

    const aiScene* scene = modelImport.ReadFile(filePath, assimpFlags);
    
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {

      String errorMessage = modelImport.GetErrorString();
#if NAU_DEBUG_MODE
      Logger::instance().toIDE(String("Error loading model at path") + 
                               filePath + 
                               ", loading default Error Model");
#endif
      Logger::instance().toConsole(String("Error loading model at path") + 
                                   filePath + 
                                   ", loading default Error Model");

      scene = modelImport.ReadFile("./resources/errorModel.stl", assimpFlags);

      if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Couldn't Load Error model..." << std::endl;
      }
      return;
    }


    processNode(scene->mRootNode, scene);
/************************************************************************/
/* Bones                                                                */
/************************************************************************/
    Map<String, Bone*> sceneBones;
    Vector<aiNode*> modelNodes;

    if (m_hasBones) {
      uint32 index = 0;
      for (uint32 i = 0; i < scene->mNumMeshes; ++i) {
        if (scene->mMeshes[i]->HasBones()) {
          for (uint32 j = 0; j < scene->mMeshes[i]->mNumBones; ++j) {
            Bone* newBone = new Bone(*scene->mMeshes[i]->mBones[j]);
            newBone->m_ID = index;
            if (sceneBones.find(newBone->m_name) == sceneBones.end()) {
              sceneBones.insert(std::make_pair(newBone->m_name, newBone));
              ++index;
            }
          }
        }
      }
      for (auto bone : sceneBones) {
        auto node = scene->mRootNode->FindNode(bone.second->m_name.c_str());
        modelNodes.push_back(node);
      }
      String newExtension = filePath.substr(0, filePath.find_last_of('.'));
      m_skeleton = 
        std::static_pointer_cast<Skeleton>(ResourceManager::instance().create(newExtension,
                                                                              RESOURCETYPE::SKELETON));
      m_skeleton->init(sceneBones, modelNodes);
    }

/************************************************************************/
/* Bone assignment                                                      */
/************************************************************************/
    ///*
    Vector<Vector<uint32>> bCounter;
    uint32 maxVertexSize = 0;
    for (auto mesh : m_meshes) {
      Vector<uint32> vertexInMesh;
      vertexInMesh.resize(mesh->m_vertexBuffer->m_vertexData.size(), 0);
      maxVertexSize += mesh->m_vertexBuffer->m_vertexData.size();
      bCounter.push_back(vertexInMesh);
    }

    Map<String, Bone*>* set = m_skeleton->getAllBones();
    String log = "";
    uint32 bonesLoaded = 0;
    uint32 id = 0;
    float weight = 0.0f;

    uint32 w = 0;
    uint32 i = 0;
    uint32 j = 0;

    for (i = 0; i < scene->mNumMeshes; ++i) {
      if (scene->mMeshes[i]->HasBones()) {
        for (j = 0; j < scene->mMeshes[i]->mNumBones; ++j) {
          String name = scene->mMeshes[i]->mBones[j]->mName.C_Str();
          if (set->find(name) != set->end()) {
            
            auto bone = set->find(name)->second;
            for (w = 0; w < bone->m_weights.size(); ++w) {

              id = bone->m_weights[w].m_ID;
              bonesLoaded = 4;

              if (id < m_meshes[i]->m_vertexBuffer->m_vertexData.size() && (aiProcess_OptimizeMeshes & assimpFlags)) {
                weight = bone->m_weights[w].m_weight;
                bonesLoaded = bCounter[i][id];
              }
              
              
              if (bonesLoaded < 4) {
                m_meshes[i]->m_vertexBuffer->m_vertexData[id].m_IDs[bCounter[i][id]] = id;
                m_meshes[i]->m_vertexBuffer->m_vertexData[id].m_weights[bCounter[i][id]] = weight;
                ++bCounter[i][id];
              }
            }
          }
        }
      }
    }

    //*/

/************************************************************************/
/* Animations                                                           */
/************************************************************************/
    if (scene->mNumAnimations > 0) {
      //If it has animations, we will through each one

      String newExtension = filePath.substr(0, filePath.find_last_of('.'));

      Sptr<Animachine> animator = 
        std::static_pointer_cast<Animachine>(ResourceManager::instance().create(newExtension,
                                                                              RESOURCETYPE::ANIMATOR));

      animator->getAnimations().reserve(scene->mNumAnimations);

      for (uint32 i = 0; i < scene->mNumAnimations; ++i) {

        String newExtension = filePath.substr(0, filePath.find_last_of('.'));

        newExtension.append(scene->mAnimations[i]->mName.C_Str());

        Sptr<Animation> animation =
        std::static_pointer_cast<Animation>(ResourceManager::instance().create(newExtension,
                                                                               RESOURCETYPE::ANIMATION));
        animation->init(scene->mAnimations[i], sceneBones);
        animator->addAnimation(animation);
      }

    }

  }

  void
  Model::processNode(aiNode* node, const aiScene* scene) {

    for (uint32 i = 0; i < node->mNumMeshes; ++i) {
      aiMesh* aimesh = scene->mMeshes[node->mMeshes[i]];
      m_meshes.push_back(processMesh(aimesh, scene));
      if (aimesh->HasBones()) { m_hasBones = true; }
    }

    for (uint32 i = 0; i < node->mNumChildren; ++i) {
      processNode(node->mChildren[i], scene);
    }

  }

  Mesh*
  Model::processMesh(aiMesh* mesh, const aiScene* scene) {

    Mesh* m = new Mesh();
    m->m_vertexBuffer = m_device->createVertexBuffer();
    m->m_indexBuffer = m_device->createIndexBuffer();

    for (uint32 i = 0; i < mesh->mNumVertices; ++i) {
      Vertex pvertex;

      pvertex.m_position.x = mesh->mVertices[i].x;
      pvertex.m_position.y = mesh->mVertices[i].y;
      pvertex.m_position.z = mesh->mVertices[i].z;


      if (mesh->HasTextureCoords(0)) {
        pvertex.m_uv.x = mesh->mTextureCoords[0][i].x;
        pvertex.m_uv.y = mesh->mTextureCoords[0][i].y;
      }
      else {
        pvertex.m_uv.x = 0.0f; pvertex.m_uv.y = 0.0f;
      }
      
      if (mesh->HasNormals()) {

        pvertex.m_normal.x = mesh->mNormals->x;
        pvertex.m_normal.y = mesh->mNormals->y;
        pvertex.m_normal.z = mesh->mNormals->z;
      }
     
      if (mesh->HasTangentsAndBitangents()) {
        pvertex.m_tangent.y = mesh->mTangents->y;
        pvertex.m_tangent.x = mesh->mTangents->x;
        pvertex.m_tangent.z = mesh->mTangents->z;

        pvertex.m_binormal.x = mesh->mBitangents->x;
        pvertex.m_binormal.y = mesh->mBitangents->y;
        pvertex.m_binormal.z = mesh->mBitangents->z;
      }

      //If it didn't have normals, but did have tangent and bi normals, we calculate normals
      if (!mesh->HasNormals() && mesh->HasTangentsAndBitangents()) {
        pvertex.m_normal = Vector4(pvertex.m_tangent ^ pvertex.m_binormal, 1.0f);
      }


      m->m_vertexBuffer->add(pvertex);
    }

    for (uint32 f = 0; f < mesh->mNumFaces; ++f) {
      aiFace face = mesh->mFaces[f];
      for (uint32 j = 0; j < face.mNumIndices; ++j) {
        m->m_indexBuffer->add(face.mIndices[j]);
      }
    }


    m->m_vertexBuffer->createHardware(m_device->get(),0);
    m->m_indexBuffer->createHardware(m_device->get(),0);

    return m;
  }
}

