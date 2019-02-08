/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauPlatformMath.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Platform cpp to runtime define some variables
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "nauPlatformMath.h"

#include "nauSphere.h"
#include "nauBox2d.h"

namespace nauEngineSDK {
  const float PlatformMath::PI = std::atan(1.0f) * 4.0f;

  const float PlatformMath::DEGREE = 180.0f/PlatformMath::PI;

  const float PlatformMath::RADIAN = PlatformMath::PI/180.0f;

  const float PlatformMath::EULER = 2.71828182f;
    //nauPlatformMath::pow((1.0f + (1.0f / 10000000000000.0f)), 10000000000000.0f);
}
