#include "nauRay.h"

namespace nauEngineSDK {
  nauRay::nauRay(const nauVector3& origin, const nauVector3& direction) 
    : m_position  (origin),
      m_direction (direction) {}

}