/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauPlane.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief Plane Primitive Object
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  /**
  * Description: 
  *   Simple 3d plane primitive
  * Sample usage:
  * 	
  */
  class NAU_UTILITY_EXPORT Plane : public Vector3
  {
   public:

    /**
     * Default Constructor
     */
    Plane() = default;

    /**
     * Default Destructor
     */
    ~Plane() = default;

    /**
     * Collisions
     */
    
    /**
     * @brief Collision with another plane
     * @param the other plane to check the collision
     * @return true if colliding
     * 
     */
    bool
    collidingPlane(const Plane& other);

    /**
     * Member declaration
     */

   public:

    /**
     * W component distance towards origin
     */
    float d;
  };

}
