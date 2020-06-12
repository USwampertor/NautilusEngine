/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAABB.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauAABB member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauAABB.h"

namespace nauEngineSDK {
  AABB::AABB(const Vector3& minTip, const Vector3& maxTip) 
    :
    m_min (minTip),
    m_max (maxTip)
    {}
  AABB::AABB(const Vector3& origin, float height, float width, float lenght) 
    :
    m_min (origin),
    m_max (origin.x + width, origin.y + height,origin.z + lenght)
    {}
  
  /**
   * Collisions
   */
  bool
  AABB::collidingAABB(const AABB& other) {
    return  insideBox(other.m_min) && insideBox(other.m_max);
  }
  bool
  AABB::insideBox(const Vector3& other) {
    return  
      (other.x > m_min.x) && (other.x < m_max.x) &&
      (other.y > m_min.y) && (other.y < m_max.y) &&
      (other.z > m_min.z) && (other.z < m_max.z);
  }


}
