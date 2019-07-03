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
  struct Skeleton
  {
    Vector<Bone> m;
  };
}
