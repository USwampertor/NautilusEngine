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
  void
  Animator::play(String name) {

  }

  Vector<String>
  Animator::getList() {
    Vector<String> animations;
    for (auto animation : m_animations) {
      animations.push_back(animation.m_name);
    }
    return animations;
  }

  void
  Animator::crossFade() {

  }

  void
  Animator::update() {
  
  }

  void
  Animator::reset() {

  }
}