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
    m_minCorner (minTip),
    m_maxCorner (maxTip)
    {}
  AABB::AABB(const Vector3& origin, float height, float width, float lenght) 
    :
    m_minCorner (origin),
    m_maxCorner (origin.x + width, origin.y + height,origin.z + lenght)
    {}
  
  /**
   * Collisions
   */
  bool
  AABB::collidingAABB(const AABB& other) {
    return  insideBox(other.m_minCorner) && insideBox(other.m_maxCorner);
  }
  bool
  AABB::insideBox(const Vector3& other) {
    return  
      (other.x > m_minCorner.x) && (other.x < m_maxCorner.x) &&
      (other.y > m_minCorner.y) && (other.y < m_maxCorner.y) &&
      (other.z > m_minCorner.z) && (other.z < m_maxCorner.z);
  }


}
