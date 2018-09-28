/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSphere.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauSphere member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauSphere.h"

namespace nauEngineSDK {
  
  nauSphere::nauSphere(const nauVector3& position, float size) 
  : m_center (position),
    m_radius (size) {}

  bool
  nauSphere::isEqual(const nauSphere& sphere, float threshold) const {
    return nauMath::abs(m_radius-sphere.m_radius) <= threshold;
  }
  /**
   * Collisions
   */
  bool
  nauSphere::collidingSphere(const nauSphere& other) {
    return nauMath::sqr(m_radius + other.m_radius) == 
           nauVector3::sqrDistance(m_center,other.m_center);
  }
}