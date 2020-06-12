/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBox2d.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauBox2d member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauBox2d.h"

namespace nauEngineSDK {

  /**
   * Member definition
   */

  Box2D::Box2D(const Vector2& min, const Vector2& max)
    : m_min (min),
      m_max (max) {}
  
  Box2D::Box2D(const Vector2& origin, float height, float width)
    : m_min (origin),
      m_max (Vector2(origin.x+width,origin.y+height)){}

  bool
  Box2D::collidingBox2d(const Box2D& other) {
    return insideBox2d(other.m_min) && insideBox2d(other.m_max);
  } 

  bool
  Box2D::insideBox2d(const Vector2& other) {
    return
      (other.x > m_min.x) && (other.x < m_max.x) &&
      (other.y > m_min.y) && (other.y < m_max.y);
  }
}
