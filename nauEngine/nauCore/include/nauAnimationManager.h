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
#include "nauComponent.h"
#include "nauAnimator.h"

//Forward class
class Bone;

namespace nauEngineSDK {
class NAU_CORE_EXPORT AnimationManager : public Module<AnimationManager>
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
   * @brief Initializes the Animation Manager 
   * @param 
   * @return true if able to initialize 
   *
   */
  bool
  init();

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
  depthAnimator(Bone* bone);

  /**
   * @brief Breath search animator
   * @param GameObjec* object to animate
   * @return 
   *
   */
  void
  breathAnimator(Bone* bone);

  /**
   * @brief Calculates animations with a compute pass
   * @param GameObjec* object to animate
   * @return 
   *
   */
  void
  computeAnimation(Bone* bone);

};
}


