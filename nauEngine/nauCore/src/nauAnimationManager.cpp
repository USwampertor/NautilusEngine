#include "nauAnimationManager.h"


namespace nauEngineSDK {
  void
  AnimationManager::animate(Vector<GameObject*> gameobjects) {
    for (auto puppet : gameobjects) {
      puppet->getComponent(COMPONENT::ANIMATOR);

    }
  }

  void
  AnimationManager::depthAnimator(GameObject* gameObjects) {



  }

  void
  AnimationManager::breathAnimator(GameObject* gameObjects) {

  }

  void
  AnimationManager::computeAnimation(GameObject* gameObject) {

  }

}