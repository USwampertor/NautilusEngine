/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauAnimation.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/27 2019
 * @brief Animation object for matrix transformation control of models
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauAnimationBone.h"

namespace nauEngineSDK {
struct Animation
{
public:

  /**
   * Default constructor
   */
  Animation() = default;

  /**
   * Default destructor
   */
  ~Animation() = default;

  /**
   * String name of the animation
   */
  String m_name;

  /**
   * Duration of the animation in ticks
   */
  double m_duration;

  /**
   * how many ticks per second is this animation made
   */
  double m_ticksPerSecond;

  /**
   * The channels
   */
  Vector<AnimationBone> m_channels;
};
}
