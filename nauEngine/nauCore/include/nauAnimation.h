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
#include "nauAnimationBone.h"

namespace nauEngineSDK {
struct Animation
{
public:
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
  Vector<AnimationBone*> m_channels;

  /**
   * the actual frame
   */
  double m_frame;

  /**
   * is it looping?
   */
  bool m_loop;

};
}
