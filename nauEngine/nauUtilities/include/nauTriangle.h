/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTriangle.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief a Triangle Primitive object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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
  class NAU_UTILITY_EXPORT nauTriangle {
   public:
    
    /**
     * Default constructor
     */
    nauTriangle() = default;
    
    /**
     * @brief Copy constructor
     * @param b the other triangle you gonna get the info from
     * @return 
     * 
     */
    nauTriangle(const nauTriangle& b);

    /**
     * Default Destructor
     */
    ~nauTriangle() = default;

    /**
     * Member declaration
     */
   
   public:

    /**
     * 1st vertex
     */
    nauVector3 m_vert0;

    /**
     * 2nd vertex
     */
    nauVector3 m_vert1;

    /**
     * 3rd vertex
     */
    nauVector3 m_vert2;
  };
}

