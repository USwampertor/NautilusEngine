/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRay.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief a ray casted in space, formed by position and direction
 * Thanks to SIGGRAPH for this one
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"
namespace nauEngineSDK {
  class NAU_UTILITY_EXPORT nauRay
  {
   public:
    nauRay() = default;
    ~nauRay() = default;
   public:
    nauVector3 m_position;
    nauVector3 m_direction;
    
  };
  
}

