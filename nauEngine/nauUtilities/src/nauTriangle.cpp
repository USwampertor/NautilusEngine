/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauTriangle.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauTriangle member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauTriangle.h"

namespace nauEngineSDK {

  Triangle::Triangle(const Triangle& b) 
    : m_a(b.m_a),
      m_b(b.m_b),
      m_c(b.m_c) {}
}
