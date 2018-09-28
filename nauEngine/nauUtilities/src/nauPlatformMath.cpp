/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauPlatformMath.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Platform cpp to runtime define some variables
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauPlatformMath.h"

#include "nauSphere.h"
#include "nauBox2d.h"

namespace nauEngineSDK {
  const float nauPlatformMath::PI = std::atan(1.0f) * 4.0f;

  const float nauPlatformMath::DEGREE = 180.0f/nauPlatformMath::PI;

  const float nauPlatformMath::RADIAN = nauPlatformMath::PI/180.0f;

  const float nauPlatformMath::EULER = 2.71828182f;
    //nauPlatformMath::pow((1.0f + (1.0f / 10000000000000.0f)), 10000000000000.0f);
}
