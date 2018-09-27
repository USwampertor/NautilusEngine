/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBox2d.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauMath.h"
#include "nauPrerequisitesUtil.h"
#include "nauVector2.h"

namespace nauEngineSDK {
  class nauBox2d
  {
  public:
    nauBox2d() = default;
    ~nauBox2d() = default;

    nauVector2 m_min;
    nauVector2 m_max;
  };
}


