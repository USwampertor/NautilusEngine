/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauCapsule.cpp
 * @author Marco "Swampy" Millan
 * @date 6/11/2020
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/


#include "nauCapsule.h"
#include "nauPhysics.h"

namespace nauEngineSDK {
  Capsule::Capsule(const Vector3& pointA, const Vector3& pointB, const float& radius)
    : m_A(pointA),
      m_B(pointB),
      m_radius(radius) {}

  Capsule::Capsule(const Capsule& other) {
    m_A = other.m_A;
    m_B = other.m_B;
    m_radius = other.m_radius;
  }

  bool
  Capsule::collidingCapsule(const Capsule& other) {

    float sqDistance = Physics::closestPointSegmentSegment(m_A, m_B, other.m_A, other.m_B);
    float radius = m_radius + other.m_radius;
    return sqDistance <= radius * radius;
  }


}
