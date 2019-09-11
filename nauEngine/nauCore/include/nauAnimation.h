/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAnimation.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/27 2019
 * @brief Animation object for matrix transformation control of models
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauAnimationBone.h"
#include "nauBone.h"
#include "nauResource.h"

#include <assimp/config.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace nauEngineSDK {
class Animation : public Resource
{
public:
  /**
   * Default constructor
   */
  Animation() = default;

  /**
   * Default destructor
   */
  ~Animation() = default;

  /**
   * @brief Initializes the animation given an aiAnimation and a Map of bones
   * @param aiAnimation* animation set
   * @param Map<String, Bone*> sceneBones the bones of the animation
   * @return 
   *
   */
  void
  init(aiAnimation* animation, Map<String, Bone*> sceneBones);

  /**
   * String name of the animation
   */
  String m_name;

  /**
   * Duration of the animation in ticks
   */
  double m_duration;

  /**
   * how many ticks per second is this animation made
   */
  double m_ticksPerSecond;

  /**
   * The channels
   */
  Vector<AnimationBone*> m_channels;

  /**
   * the actual frame
   */
  double m_frame;

  /**
   * is it looping?
   */
  bool m_loop;

  
  virtual bool
  load(String path) override;

  virtual RESOURCETYPE::E
  getType() override { return RESOURCETYPE::ANIMATION; }

};
}
