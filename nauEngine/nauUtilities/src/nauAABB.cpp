#include "nauAABB.h"
namespace nauEngineSDK {
  nauAABB::nauAABB(const nauVector3& minTip, const nauVector3& maxTip) 
    :
    m_minCorner (minTip),
    m_maxCorner (maxTip)
    {}
  nauAABB::nauAABB(const nauVector3& origin, float height, float width, float lenght) 
    :
    m_minCorner (origin),
    m_maxCorner (origin.x + width, origin.y + height,origin.z + lenght)
    {}
  bool
  nauAABB::collidingAABB(const nauAABB& other) {
    return  insideBox(other.m_minCorner) && insideBox(other.m_maxCorner);
  }
  bool
  nauAABB::insideBox(const nauVector3& other) {
    return  
      (other.x > m_minCorner.x) && (other.x < m_maxCorner.x) &&
      (other.y > m_minCorner.y) && (other.y < m_maxCorner.y) &&
      (other.z > m_minCorner.z) && (other.z < m_maxCorner.z);
  }

  /**
   * Collisions
   */

}