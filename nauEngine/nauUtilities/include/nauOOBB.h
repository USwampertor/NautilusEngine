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
  class NAU_UTILITY_EXPORT nauOOBB {
   public:
    
    /**
     * Default Constructor
     */
    nauOOBB() = default;

    /**
     * Default destructor
     */
    ~nauOOBB() = default;

    /**
     * Member declaration
     */

   public:
    
    /**
     * nauVector3 center component
     */
    nauVector3 center;

    /**
     * width X component
     */
    float widthX;

    /**
     * Height Y component
     */
    float heightY;

    /**
     * Length Z component
     */
    float lengthZ;
  };
}


