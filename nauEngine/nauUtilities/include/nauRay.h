/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauRay.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief a ray casted in space, formed by position and direction
 * Thanks to SIGGRAPH for this one
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   A ray object that has an origin point and a direction that casts a line
  * Sample usage:
  * 	We can use the ray to create a raycasting
  */
  class NAU_UTILITY_EXPORT Ray {
   public:
    
    /**
     * Default constructor
     */
    Ray() = default;

    /**
     * @brief Constructor with parameters
     * @param position, direction
     * @return
     * 
     */
     Ray(const Vector3& origin, const Vector3& direction);

    /**
     * Default destructor
     */
    ~Ray() = default;
   
    /**
     * Collisions
     */
    //bool
    //collidingRay(const nauRay& other);

    /**
     * Member declaration
     */
   public:

    /**
     * position component
     */
    Vector3 m_position;

    /**
     * direction component
     */
    Vector3 m_direction;
    
  };
  
}
