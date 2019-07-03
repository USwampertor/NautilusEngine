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
#include "nauAnimation.h"
#include "nauComponent.h"

namespace nauEngineSDK {

 /**
  * Animator
  * Description:
  *   Animator controller that has several animations from an object.
  *   It serves as a state machine for animations
  * Sample usage:
  *   Animator.Play("foo") will play the animation with the given name
  */
class Animator : Component
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
  play(String name);

  Vector<String>
  getList();
  
  void
  crossFade();

  void
  update();

  void
  reset();

  float speed;
  
  Animation* m_active;

  Vector<Animation> m_animations;

};
}