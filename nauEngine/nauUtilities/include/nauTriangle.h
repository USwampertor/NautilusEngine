/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauTriangle.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"

namespace nauEngineSDK {

  class NAU_UTILITY_EXPORT nauTriangle
  {
  public:
    
    nauTriangle() = default;
    
    nauTriangle(const nauTriangle& b);

    ~nauTriangle() = default;


    nauVector3 m_vert0;
    nauVector3 m_vert1;
    nauVector3 m_vert2;
  };
}

