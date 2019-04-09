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

namespace nauEngineSDK {
  void
  Model::drawMesh() {
    for (auto& mesh : m_meshes) {



      SamplerState* sampler = m_device->createSamplerState();
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

    //char dirPath[MAX_PATH];
    //GetCurrentDirectoryA(MAX_PATH, dirPath);
    //String folderPath(dirPath);
    //std::cout << folderPath;

    Assimp::Importer modelImport;
    const aiScene* scene = modelImport.ReadFile(filePath, 
                                                aiProcessPreset_TargetRealtime_MaxQuality |
                                                aiProcess_ConvertToLeftHanded);
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {

      String errorMessage = modelImport.GetErrorString();
      std::cout << "Error loading model... Loading default Error Model" << std::endl;

      scene = modelImport.ReadFile("resources/errorModel.stl", 
                                   aiProcessPreset_TargetRealtime_MaxQuality |
                                   aiProcess_ConvertToLeftHanded);

      if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Couldn't Load Error model..." << std::endl;
      }
      return;
    }
    processNode(scene->mRootNode, scene);
  }

  void
  Model::processNode(aiNode* node, const aiScene* scene) {

    for (uint32 i = 0; i < node->mNumMeshes; ++i) {
      aiMesh* aimesh = scene->mMeshes[node->mMeshes[i]];
      m_meshes.push_back(processMesh(aimesh, scene));
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

    
    for (uint32 l = 0; l < mesh->mMaterialIndex; ++l) {

      m->m_material = new Material();
      aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
      Texture* texture = m_device->createTexture();
      //texture->loadFromFile() = loadMaterials(material, aiTextureType_SPECULAR, "texture_diffuse");
      //
      //aiMaterial *material = mesh->mMaterials[aimesh->mMaterialIndex];
      //m_textures = loadMaterials(material, aiTextureType_SPECULAR, "texture_diffuse");
    }
    m->m_vertexBuffer->createHardware(m_device->get(),0);
    m->m_indexBuffer->createHardware(m_device->get(),0);

    return m;
  }
}

