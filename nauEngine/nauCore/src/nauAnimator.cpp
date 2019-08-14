/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimator.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/06/29 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauAnimator.h"

namespace nauEngineSDK {

  bool
  Animator::load(String path) {
    FileStream mat;
    mat.open(path);
    mat.m_data.data();

    return true;
  }

  void
  Animator::play(String name) {
    for (auto animation : m_animations) {
      if (animation->m_name == name) {
        m_current = animation;
        m_active = true;
        return;
      }
    }
#if NAU_DEBUG_MODE
    Logger::instance().toIDE("Couldn't find an animation with that name", 
                             LOGGER_LEVEL::ERRORED);
#endif
    Logger::instance().toConsole("Couldn't find an animation with that name",
                                 LOGGER_LEVEL::ERRORED);
  }

  void
  Animator::play() {
    m_active = true;
  }

  void
  Animator::pause() {
    m_active = false;
  }

  void
  Animator::stop() {
    m_active = false;
    m_frame = 0.0f;
  }

  Vector<String>
  Animator::getAnimationNames() {
    Vector<String> animations;
    for (auto animation : m_animations) {
      animations.push_back(animation->m_name);
    }
    return animations;
  }

  Vector<Animation*>
  Animator::getAnimations() {
    return m_animations;
  }

  void
  Animator::crossFade() {

  }

  void
  Animator::update() {
    
  }

  void
  Animator::reset() {
    m_frame = 0.0f;
  }

  void
  Animator::setSpeed(float newSpeed) {
    m_speed = newSpeed;
  }

}