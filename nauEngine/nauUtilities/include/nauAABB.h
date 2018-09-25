/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAABB.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/25 2018
 * @brief An Axis Aligned Boundary Box (AABB) wich has two tips that define the 
 * whole space the cube is in
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  class nauAABB
  {
   public:
    nauAABB() = default;
    nauAABB(const nauVector3& minTip, const nauVector3& maxTip);
    nauAABB(const nauVector3& origin, float height, float width, float lenght);
    bool
    collidingAABB(const nauAABB& other);
    bool
    insideBox(const nauVector3& other);
   public:
     nauVector3 m_minCorner;
     nauVector3 m_maxCorner;

  };
}


