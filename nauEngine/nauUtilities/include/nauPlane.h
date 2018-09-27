/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauPlane.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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
