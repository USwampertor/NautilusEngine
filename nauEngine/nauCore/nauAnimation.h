/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimation.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/27 2019
 * @brief Animation object for matrix transformation control of models
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  class nauAnimation
  {
  public:
  
    /**
     * Default constructor
     */
    nauAnimation() = default;
  
    /**
     * Default destructor
     */
    ~nauAnimation() = default;


    /**
     * Duration of the animation
     */
    double m_duration;

    /**
     * how many ticks per second is this animation made
     */
    double m_ticksPerSecond;

    /**
     * The channels
     */

  };
}


