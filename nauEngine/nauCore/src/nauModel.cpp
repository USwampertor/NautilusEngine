/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauModel.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief Model member definition
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#include "nauModel.h"

namespace nauEngineSDK {
  void
  Model::render() {
    for (auto& mesh : m_meshes) {
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
    const aiScene* scene = modelImport.ReadFile(filePath, aiProcess_Triangulate);
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {

      String errorMessage = modelImport.GetErrorString();
      std::cout << "Error loading model... Loading default Error Model" << std::endl;

      scene = modelImport.ReadFile("errorModel.stl", aiProcess_Triangulate);

      if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Couldn't Load Error model..." << std::endl;
      }
      return;
    }
    processNode(scene->mRootNode, scene);
  }

  void
  Model::processNode(aiNode* node, const aiScene* scene) {

    for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
      aiMesh* aimesh = scene->mMeshes[node->mMeshes[i]];
      m_meshes.push_back(processMesh(aimesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; ++i) {
      processNode(node->mChildren[i], scene);
    }
  }

  Mesh*
  Model::processMesh(aiMesh* mesh, const aiScene* scene) {
    Mesh* m = new Mesh();
    m->m_vertexBuffer = m_device->createVertexBuffer();
    m->m_indexBuffer = m_device->createIndexBuffer();

    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
      Vertex pvertex;

      pvertex.m_position.x = mesh->mVertices[i].x;
      pvertex.m_position.y = mesh->mVertices[i].y;
      pvertex.m_position.z = mesh->mVertices[i].z;

      pvertex.m_normal.x = mesh->mNormals[i].x;
      pvertex.m_normal.y = mesh->mNormals[i].y;
      pvertex.m_normal.z = mesh->mNormals[i].z;

      if (mesh->mTextureCoords[0]) {
        pvertex.m_u = mesh->mTextureCoords[0][i].x;
        pvertex.m_v = mesh->mTextureCoords[0][i].y;
      }
      else {
        pvertex.m_u = 0.0f; pvertex.m_v = 0.0f;
      }

      m->m_vertexBuffer->add(pvertex);
    }

    for (unsigned int f = 0; f < mesh->mNumFaces; ++f) {
      aiFace face = mesh->mFaces[f];
      for (unsigned int j = 0; j < face.mNumIndices; ++j) {
        m->m_indexBuffer->add(face.mIndices[j]);
      }
    }

    if (mesh->mMaterialIndex >= 0) {
      //aiMaterial *material = s->mMaterials[aimesh->mMaterialIndex];
      //m_textures = loadMaterials(material, aiTextureType_SPECULAR, "texture_diffuse");
      //
      //aiMaterial *material = s->mMaterials[aimesh->mMaterialIndex];
      //m_textures = loadMaterials(material, aiTextureType_SPECULAR, "texture_diffuse");
    }
    m->m_vertexBuffer->createHardware(m_device->get(),0);
    m->m_indexBuffer->createHardware(m_device->get(),0);

    return m;
  }
}

