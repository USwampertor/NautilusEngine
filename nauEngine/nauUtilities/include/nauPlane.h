/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauPlane.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  class nauPlane
  {
   public:
    nauPlane() = default;
    ~nauPlane() = default;
   public:
    float w;
    nauVector3 m_normal;
  
  };

}
