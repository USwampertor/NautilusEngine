/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauPlane.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauPlane member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "nauPlane.h"

namespace nauEngineSDK {
  
  bool
  nauPlane::collisingPlane(const nauPlane& other) {
    return x == other.x && y == other.y && z == other.z;
  }
}
