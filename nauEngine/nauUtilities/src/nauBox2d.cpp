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

  nauBox2d::nauBox2d(const nauVector2& min, const nauVector2& max)
    : m_min (min),
      m_max (max) {}
  
  nauBox2d::nauBox2d(const nauVector2& origin, float height, float width)
    : m_min (origin),
      m_max (nauVector2(origin.x+width,origin.y+height)){}

  bool
  nauBox2d::collidingBox2d(const nauBox2d& other) {
    return insideBox2d(other.m_min) && insideBox2d(other.m_max);
  } 

  bool
  nauBox2d::insideBox2d(const nauVector2& other) {
    return
      (other.x > m_min.x) && (other.x < m_max.x) &&
      (other.y > m_min.y) && (other.y < m_max.y);
  }
}
