/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSkeleton.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/02 2019
 * @brief Skeleton object for meshes and animations
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauBone.h"
#include "nauModelNode.h"
#include "nauLogger.h"
#include "nauResource.h"

namespace nauEngineSDK {
class Skeleton : public Resource
{
public:

  /**
   * Default constructor
   */
  Skeleton() = default;

  /**
   * Default destructor
   */
  ~Skeleton() = default;

  /**
   * Constructor with reference copy
   */
  Skeleton(const Skeleton& other);

  /**
   * @brief Initializes the skeleton with a series of bones
   * @param the bones to make the tree
   * @return 
   *
   */
  void
  init(Vector<Bone*> bones);

  virtual RESOURCETYPE::E
  getType() override { return RESOURCETYPE::SKELETON; }

  virtual bool
  load(String path) override;

  void
  init(Map<String, Bone*> bones);

  /**
   * @brief Initializes the skeleton with a map of bones and the nodes of the model scene
   * @param Map<String, Bone*> the bones of the model
   * @param Vector<ModelNode*> The nodes in the model scene controlling the hierarchy
   * @return 
   *
   */
  void
  init(Map<String, Bone *> bones, Vector<aiNode*> nodes);

  /**
   * @brief Processes the children of the nodes of Assimp and puts them on the final
   *        skeleton
   * @param Map<String, Bone*> the bones of the model
   * @param Vector<ModelNode*> The nodes in the model scene controlling the hierarchy
   * @param Bone* the actual bone the processor is right now
   * @return
   *
   */
  void
  processBone(Map<String, Bone *> bones, aiNode* node, Bone* actualBone);

  /**
   * @brief returns the Bone* that is the root of the skeleton
   * @param 
   * @return the Bone* root of the skeleton
   *
   */
  Bone*
  getRoot();

  /**
   * @brief Returns a map with all the bones from this Skeleton
   * @param 
   * @return Map<name, Bone*>
   *
   */
  Map<String, Bone*>*
  getAllBones();

  /**
   * @brief returns the ID of the skeleton inside a model
   * @param 
   * @return the int ID of the skeleton 
   *
   */
  uint32
  getID();

  /**
   * @brief This function processes muscles if the model has integrated them in it
   * @param 
   * @return 
   *
   */
  void
  processMuscles(Vector<Bone*> muscles);

private:

  /**
   * ID of the Skeleton
   */
  uint32 m_ID;

  /**
   * Root of the Bone
   */
  Bone* m_root = nullptr;

  /**
   * Reference to all bones in the skeleton 
   */
  Map<String, Bone*> m_set;

  /**
   * List of muscles in the model
   */
  Vector<Bone*> m_muscles;

};
}
