/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSkeleton.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/06 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauSkeleton.h"

namespace nauEngineSDK {
  
  Skeleton::Skeleton(const Skeleton& other) {

  }

  void
  Skeleton::init(Vector<Bone*> bones) {

  }

  void
  Skeleton::init(Map<String, Bone *> bones) {


  }

  void
  Skeleton::init(Map<String, Bone *> bones, Vector<aiNode*> nodes) {
    for (auto node : nodes) {
      std::cout << "Node " << node->mName.C_Str() << std::endl;
      if (node->mParent == nullptr) {
        
      }
      node->mChildren;
      node->mName;
    }
  }

  Bone*
  Skeleton::getRoot() {
    return m_root;
  }

  int
  Skeleton::getID() {
    return m_ID;
  }



}