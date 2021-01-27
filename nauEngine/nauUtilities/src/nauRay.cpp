/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauRay.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauRay member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauRay.h"

namespace nauEngineSDK {
  Ray::Ray(const Vector3& origin, const Vector3& direction) 
    : m_position  (origin),
      m_direction (direction) {}

}