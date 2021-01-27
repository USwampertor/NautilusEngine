/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauPlane.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauPlane member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauPlane.h"

namespace nauEngineSDK {
  
  bool
  Plane::collidingPlane(const Plane& other) {
    return x == other.x && y == other.y && z == other.z && d == other.d;
  }
}
