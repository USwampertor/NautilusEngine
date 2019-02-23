/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauModelDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/12/07 2018
 * @brief Model implementation in DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauModel.h>

#include "nauMeshDX.h"

namespace nauEngineSDK {
   /**
    * nauModelDX
    * Description:
    * 	model implementation in DirectX
    * Sample usage:
    * 	model myScene
    */
  class NAU_DIRECTX_EXPORT ModelDX : public Model
  {
  public:
    /**
     * Default constructor
     */
    ModelDX() = default;

    /**
     * Default destructor
     */
    ~ModelDX() {}

    void
    setDevice(void* pDevice);

    void
    render();

    void
    loadFromFile(String filePath);

    void
    processNode(aiNode* node, const aiScene* scene);

    Mesh*
    processMesh(aiMesh* mesh, const aiScene* scene);

  public:

    ID3D11Device* m_pDevice = nullptr;
  };
  
}

