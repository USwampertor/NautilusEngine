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
  Animachine::load(String path) {
    FileStream mat;
    mat.open(path,STREAMACCESS::READ);
    mat.m_data.data();

    return true;
  }

  bool
  Animachine::addAnimation(Sptr<Animation> anim) {
    m_animations.push_back(anim);

    return true;
  }

  void
  Animachine::play(String name) {
    setAnimation(name);
    m_active = true;
  }

  void
  Animachine::play() {
    m_active = true;
  }

  void
  Animachine::pause() {
    m_active = false;
  }

  void
  Animachine::stop() {
    m_active = false;
    m_frame = 0.0f;
  }

  void
  Animachine::setAnimation(String name) {
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
  Animachine::setAnimation(uint32 animation) {
    if (animation < m_animations.size()) {
      m_current = m_animations[animation];
    }
    else {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Integer is higher than number of animations in the machine",
        LOGGER_LEVEL::ERRORED);
#endif
      Logger::instance().toConsole("Integer is higher than number of animations in the machine",
        LOGGER_LEVEL::ERRORED);
    }
  }

  Vector<String>
  Animachine::getAnimationNames() {
    Vector<String> animations;
    for (auto animation : m_animations) {
      animations.push_back(animation->m_name);
    }
    return animations;
  }

  Vector<Sptr<Animation>>
  Animachine::getAnimations() {
    return m_animations;
  }

  Sptr<Animation>
  Animachine::getCurrentAnimation() {
    return m_current;
  }

  void
  Animachine::crossFade() {

  }

  void
  Animachine::update(float deltaTime) {
    m_current->update(deltaTime);
  }

  void
  Animachine::reset() {
    m_frame = 0.0f;
  }

  void
  Animachine::setSpeed(float newSpeed) {
    m_speed = newSpeed;
  }

  bool
  Animachine::isPlaying() {
    return m_active;
  }

}