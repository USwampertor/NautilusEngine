#include "nauAnimationManager.h"

namespace nauEngineSDK {

  bool
  AnimationManager::init() {

    return true;
  }

  void
  AnimationManager::animate(Vector<GameObject*> gameobjects) {
    for (auto puppet : gameobjects) {
      auto animator = 
        reinterpret_cast<AnimatorComponent*>(puppet->getComponent(COMPONENT::ANIMATOR));

    }
  }

  void
  AnimationManager::depthAnimator(GameObject* gameObject) {



  }

  void
  AnimationManager::breathAnimator(GameObject* gameObject) {

  }

  void
  AnimationManager::computeAnimation(GameObject* gameObject) {

  }

}