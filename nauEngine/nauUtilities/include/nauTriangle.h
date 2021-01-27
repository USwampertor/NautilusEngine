/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauTriangle.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief a Triangle Primitive object
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   Triangle Primitive with 3 Vectors
  * Sample usage:
  * 	You could make some nice little quads with it, or a mesh, or a model
  */
  class NAU_UTILITY_EXPORT Triangle {
   public:
    
    /**
     * Default constructor
     */
    Triangle() = default;
    
    /**
     * @brief Copy constructor
     * @param b the other triangle you gonna get the info from
     * @return 
     * 
     */
    Triangle(const Triangle& b);

    /**
     * Default Destructor
     */
    ~Triangle() = default;

    /**
     * Member declaration
     */
   
   public:

    /**
     * 1st vertex
     */
    Vector3 m_a;

    /**
     * 2nd vertex
     */
    Vector3 m_b;

    /**
     * 3rd vertex
     */
    Vector3 m_c;
  };
}

