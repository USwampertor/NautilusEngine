/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauOOBB.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Object Oriented Boundary Box (OOBB for short) class used for object
 * boundaries
 * SIGGRAPH definition also helped here, thanks
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  class NAU_UTILITY_EXPORT nauOOBB {
   public:
    nauOOBB() = default;
    ~nauOOBB() = default;

   public:
    nauVector3 center;
    float widthX;
    float heightY;
    float lenghtZ;
  };
}


