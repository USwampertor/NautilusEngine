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

#include "nauMesh.h"
#include "nauSkeleton.h"
#include "nauResourceManager.h"

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
  ~Model() = default;

  /**
   * Returns true if there is any bone in the model
   */
  bool
  hasBones();

  /**
   * Sets the device
   */
  void
  setDevice(Device* dev);

  /**
   * @brief renders the object in world space
   * @param 
   * @return 
   *
   */
  void
  drawMesh();

  /**
   * @brief Loads a model from given path 
   * @param String filePath 
   * @return 
   *
   */
  void
  loadFromFile(String filePath);

  /**
   * @brief Processes a node from the model
   * @param 
   * @return 
   *
   */
  void
  processNode(aiNode* node, const aiScene* scene);

  /**
   * @brief Processes a mesh from the model
   * @param 
   * @return 
   *
   */
  Mesh*
  processMesh(aiMesh* mesh, const aiScene* scene);

public:

  /**
   * Mesh vector with the information of the model
   */
  Vector<Mesh*> m_meshes;

  /**
   * Device reference 
   */
  Device* m_device = nullptr;

  /**
   * Skeleton shared resource
   */
  Sptr<Skeleton> m_skeleton;

private:
  /**
   * 
   */
  bool
  m_hasBones = false;


};
}
