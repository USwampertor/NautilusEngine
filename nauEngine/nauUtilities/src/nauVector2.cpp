/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauVector2.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief the cpp from the vector object
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

/**
 * #include
 */

#include "nauVector2.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  const nauVector2 nauVector2::ZERO = nauVector2(0.0f, 0.0f);
  
  const nauVector2 nauVector2::ONES = nauVector2(1.0f, 1.0f);
  
  const nauVector2 nauVector2::ONEX = nauVector2(1.0f, 0.0f);

  const nauVector2 nauVector2::ONEY = nauVector2(0.0f, 1.0f);
  
  inline nauVector2::nauVector2(const nauVector3& v): x(v.x),y(v.y) {}


}
