/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauModel.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief model object to render
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesCore.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "nauMesh.h"


namespace nauEngineSDK {
  /**
   * nauModel
   * Description:
   * 	Its an object made from a set of meshes, textures and whatnot
   * Sample usage:
   *
   */
  class NAU_CORE_EXPORT Model
  {
   public:

    /**
     * Default constructor
     */
    Model() = default;

    /**
     * virtual destructor
     */
    virtual ~Model() {}

    /**
     * @brief sets the device in the object
     * @param Device
     * @return 
     *
     */
    virtual void
    setDevice(void* pDevice) = 0;

    /**
     * @brief renders the object in world space
     * @param 
     * @return 
     *
     */
    virtual void
    render() = 0;

    /**
     * @brief Loads a model from given path 
     * @param String filePath
     * @return 
     *
     */
    virtual void
    loadFromFile(String filePath) = 0;

    /**
     * @brief Processes a node from the model
     * @param 
     * @return 
     *
     */
    virtual void
    processNode(aiNode* node, const aiScene* scene) = 0;

    /**
     * @brief Processes a mesh from the model
     * @param 
     * @return 
     *
     */
    virtual Mesh*
    processMesh(aiMesh* mesh, const aiScene* scene) = 0;

  public:

    Vector<Mesh*> m_meshes;

  };

}
