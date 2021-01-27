/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauAudio.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/02 2019
 * @brief Audio object for 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauResource.h"

namespace nauEngineSDK {
class NAU_CORE_EXPORT AudioClip : public Resource
{
  public:
  /**
   * Default constructor
   */
  AudioClip() = default;

  /**
   * Default destructor
   */
  ~AudioClip() = default;

  virtual bool
  load(String path) override;
  
  virtual RESOURCETYPE::E
  getType() override { return RESOURCETYPE::AUDIO; }

};
}


