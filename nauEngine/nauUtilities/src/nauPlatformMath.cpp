/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauPlatformMath.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Platform cpp to runtime define some variables
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/


/**
 * #include
 */
#include "nauPlatformMath.h"

namespace nauEngineSDK {
  const float nauPlatformMath::PI = nauPlatformMath::atan(1.0f) * 4.0f;
  const float nauPlatformMath::DEGREE = 180.0f/nauPlatformMath::PI;
  const float nauPlatformMath::RADIAN = nauPlatformMath::PI/180.0f;
  const float nauPlatformMath::EULER = nauPlatformMath::pow((1.0f / 10000.0f), 10000.0f);
}
