/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauSkeleton.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/06 2019
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

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

  Bone*
  Skeleton::getRoot() {
    return m_root;
  }

  int
  Skeleton::getID() {
    return m_ID;
  }



}