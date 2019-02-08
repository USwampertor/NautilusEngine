/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauOOBB.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauOOBB member definition
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#include "nauOOBB.h"

namespace nauEngineSDK {
  bool
  OOBB::collidingOOBB(const OOBB& other) {
    
    

    return other.center.x && this->center.x;
  }
}