/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauAnimator.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/29 2019
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauAnimation.h"
#include "nauLogger.h"
#include "nauResource.h"

#include <nauDataStream.h>


namespace nauEngineSDK {

 /**
  * Animator
  * Description:
  *   Animator controller that has several animations from an object.
  *   It serves as a state machine for animations
  * Sample usage:
  *   Animator.Play("foo") will play the animation with the given name
  */
class NAU_CORE_EXPORT Animachine : public Resource
{
public:
  /**
   * Default constructor
   */
  Animachine() = default;

  /**
   * Default destructor
   */
  ~Animachine() = default;

  void
  play(String name);

  void
  play();

  Vector<String>
  getAnimationNames();

  Vector<Sptr<Animation>>
  getAnimations();
  
  Sptr<Animation>
  getCurrentAnimation();

  void
  setAnimation(String name);

  void
  setAnimation(uint32 animation);

  void
  crossFade();

  void
  update(float deltaTime);

  void
  reset();

  void
  stop();

  void
  pause();

  void
  setSpeed(float newSpeed);

  virtual bool
  load(String path) override;

  bool
  addAnimation(Sptr<Animation> anim);

  virtual RESOURCETYPE::E
  getType() override { return RESOURCETYPE::ANIMATOR; }

  bool
  isPlaying();

 private:

  float m_speed;
  
  Sptr<Animation> m_current;

  Vector<Sptr<Animation>> m_animations;

  bool m_active;

  float m_frame;
};
}