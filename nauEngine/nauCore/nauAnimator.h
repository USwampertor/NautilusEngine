/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimator.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/29 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

 /**
  * Animator
  * Description:
  *   Animator controller that has several animations from an object.
  *   It serves as a state machine for animations
  * Sample usage:
  *   Animator.Play("foo") will play the animation with the given name
  */
class Animator
{
public:
  /**
   * Default constructor
   */
  Animator() = default;

  /**
   * Default destructor
   */
  ~Animator() = default;

  void
    Play(String name);



};
}