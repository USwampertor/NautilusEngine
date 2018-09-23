#include "nauPlatformMath.h"

namespace nauEngineSDK {
  const float nauPlatformMath::PI = nauPlatformMath::atan(1)*4;
  const float nauPlatformMath::DEGREE = 180.0f/nauPlatformMath::PI;
  const float nauPlatformMath::RADIAN = nauPlatformMath::PI/180.0f;
  const float nauPlatformMath::EULER = nauPlatformMath::pow((1/10000),10000);
}
