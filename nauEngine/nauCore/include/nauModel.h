/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauModel.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief model object to render
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesCore.h"

#include "nauMesh.h"
#include "nauSkeleton.h"

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

  Vector<Mesh*> m_meshes;
  Device* m_device = nullptr;

  Sptr<Skeleton> m_skeleton;

};
}
