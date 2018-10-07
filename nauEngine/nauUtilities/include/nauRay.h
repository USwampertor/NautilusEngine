/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRay.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief a ray casted in space, formed by position and direction
 * Thanks to SIGGRAPH for this one
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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
  class NAU_UTILITY_EXPORT nauRay {
   public:
    
    /**
     * Default constructor
     */
    nauRay() = default;

    /**
     * @brief Constructor with parameters
     * @param position, direction
     * @return
     * 
     */
     nauRay(const nauVector3& origin, const nauVector3& direction);

    /**
     * Default destructor
     */
    ~nauRay() = default;
   
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
    nauVector3 m_position;

    /**
     * direction component
     */
    nauVector3 m_direction;
    
  };
  
}
