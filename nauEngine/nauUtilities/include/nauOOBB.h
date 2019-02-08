/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauOOBB.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief Object Oriented Boundary Box (OOBB for short) class used for object
 * boundaries
 * SIGGRAPH definition also helped here, thanks
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   Object Oriented Bounding Box is a bounding box that fits the size of the object
  * Sample usage:
  * 	OOBB
  */
  class NAU_UTILITY_EXPORT OOBB {
   public:
    
    /**
     * Default Constructor
     */
    OOBB() = default;

    /**
     * Default destructor
     */
    ~OOBB() = default;

    /**
     * Collisions
     */

    /**
     * @brief Calculates if a OOB is intersecting another
     * @param other the other OOBB to compute
     * @return true if colliding
     * 
     */
    bool
    collidingOOBB(const OOBB& other);

    /**
     * Member declaration
     */

   public:
    
    /**
     * nauVector3 center component
     */
    Vector3 center;

    /**
     * local x rotation component
     */
    Vector3 m_xAxis;

    /**
     * local y rotation component
     */
    Vector3 m_yAxis;

    /**
     * local z rotation component
     */
    Vector3 m_zAxis;

    /**
     * half width X component
     */
    float widthX;

    /**
     * half Height Y component
     */
    float heightY;

    /**
     * half Length Z component
     */
    float lengthZ;
  };
}


