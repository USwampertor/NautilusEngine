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

namespace nauEngineSDK {
class Skeleton
{
public:

  /**
   * Default constructor
   */
  Skeleton() = default;

  /**
   * Constructor with a const skeleton as parameter
   */
  Skeleton(const Skeleton& other);

  /**
   * Default destructor
   */
  ~Skeleton() = default;

  /**
   * @brief Initializes the skeleton with a series of bones and 
   * @param the bones to make the tree
   * @return 
   *
   */
  void
  init(Vector<Bone*> bones);

private:

  /**
   * ID of the Skeleton
   */
  int m_ID;

  /**
   * Root of the Bone
   */
  Bone* m_root;

};
}
