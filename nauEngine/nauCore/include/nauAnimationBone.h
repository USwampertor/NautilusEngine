/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauAnimationBone.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/28 2019
 * @brief A Bone that exists in an animation context. It transforms the bones of
          a model to match the animation
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include "nauPrerequisitesCore.h"
#include <nauVector3.h>
#include <nauQuaternion.h>

namespace nauEngineSDK {
/**
 * AnimationBone
 * Description:
 *   A Bone transformation to be applied to a bone to match an animation 
 * Sample usage:
 * 
 */
struct AnimationBone {
  /**
   * Name of the Animation node. Matches a bone of the model
   */
  String m_name;

  /**
   * ID of the bone
   */
  uint32 ID;

  /**
   * The positions it will have in the animation
   */
  Vector<std::pair<float, Vector3>> m_positions;

  /**
   * The scales it will have in the animation
   */
  Vector<std::pair<float, Vector3>> m_scale;

  /**
   * The rotations it will have in the animation
   */
  Vector<std::pair<float, Quaternion>> m_rotations;
};
}
