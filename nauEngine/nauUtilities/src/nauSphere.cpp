/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauSphere.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauSphere member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauSphere.h"

namespace nauEngineSDK {
  
  Sphere::Sphere(const Vector3& position, float size) 
  : m_center (position),
    m_radius (size) {}

  bool
  Sphere::isEqual(const Sphere& sphere, float threshold) const {
    return Math::abs(m_radius-sphere.m_radius) <= threshold;
  }
  /**
   * Collisions
   */
  bool
  Sphere::collidingSphere(const Sphere& other) {
    return Math::sqr(m_radius + other.m_radius) >
           Vector3::sqrDistance(m_center , other.m_center);
  }
}