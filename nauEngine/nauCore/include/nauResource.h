/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauResource.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/25 2019
 * @brief Resource Object wrapper for audio, texture, files and other objects
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  class Resource
  {
  public:
    /**
     * Default constructor
     */
    Resource() = default;
  
    /**
     * Default destructor
     */
    ~Resource() = default;
  };

  class TextureResource : Resource
  {

  };

  class SoundResource : Resource
  {

  };
}
