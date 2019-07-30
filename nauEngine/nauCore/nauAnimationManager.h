/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimationManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/29 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauModule.h"

#include "nauGameObject.h"

namespace nauEngineSDK {
class AnimationManager : public Module<AnimationManager>
{
public:
  /**
   * Default constructor
   */
  AnimationManager() = default;

  /**
   * Default destructor
   */
  ~AnimationManager() = default;

  /**
   * @brief Gathers all objects with an animator component and animates them
   * @param Vector<GameObjects*> gameObjects all prefiltered animatable objects
   * @return 
   *
   */
  void
  animate(Vector<GameObject*> gameobjects);

  /**
   * @brief Depth search animator
   * @param GameObjec* object to animate
   * @return 
   *
   */
  void
  depthAnimator(GameObject* gameObjects);

  /**
   * @brief Breath search animator
   * @param GameObjec* object to animate
   * @return 
   *
   */
  void
  breathAnimator(GameObject* gameObjects);

  /**
   * @brief Calculates animations with a compute pass
   * @param GameObjec* object to animate
   * @return 
   *
   */
  void
  computeAnimation(GameObject* gameObject);



};
}


