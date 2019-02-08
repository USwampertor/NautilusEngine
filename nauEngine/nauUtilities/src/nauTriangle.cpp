/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTriangle.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauTriangle member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauTriangle.h"

namespace nauEngineSDK {

  Triangle::Triangle(const Triangle& b) 
    : m_vert0(b.m_vert0),
      m_vert1(b.m_vert1),
      m_vert2(b.m_vert2) {}
}
