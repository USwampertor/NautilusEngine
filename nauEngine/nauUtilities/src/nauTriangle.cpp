/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauTriangle.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauTriangle member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "nauTriangle.h"

namespace nauEngineSDK {

  nauTriangle::nauTriangle(const nauTriangle& b) 
    : m_vert0(b.m_vert0),
      m_vert1(b.m_vert1),
      m_vert2(b.m_vert2) {}
}