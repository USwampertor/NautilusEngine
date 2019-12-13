/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimationManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/09/12 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauAnimationManager.h"

#include "nauBone.h"

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
      if (animator->m->isPlaying()) {
        //auto mesh =
        //  reinterpret_cast<MeshComponent*>(puppet->getComponent(COMPONENT::MESH));
      }
    }
  }

  void
  AnimationManager::depthAnimator(Bone* bone) {

    
    for (auto boneChild : bone->m_children) {
      depthAnimator(boneChild);
    }
  }

  void
  AnimationManager::breathAnimator(Bone* bone) {

  }

  void
  AnimationManager::computeAnimation(Bone* bone) {

  }

}