/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBox2d.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief 2D Box primitive object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauMath.h"
#include "nauPrerequisitesUtil.h"
#include "nauVector2.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   A 2d Box Primitive Object
  * Sample usage:
  * 	2dBox for a sprite
  */
  class nauBox2d
  {
   public:

    /**
     * Default constructor
     */
    nauBox2d() = default;

    /**
     * Default Destructor
     */
    ~nauBox2d() = default;

    /**
     * Member declaration
     */
   public:

    /**
     * lower corner component
     */
    nauVector2 m_min;

    /**
     * higher corner component
     */
    nauVector2 m_max;
  };
}


