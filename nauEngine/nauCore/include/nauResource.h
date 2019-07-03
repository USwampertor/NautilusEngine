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

  namespace RESOURCET
  {
    enum E
    {
      AUDIO         = 1<<0,
      TEXTURE       = 1<<1,
      CUBEMAP       = 1<<2,
      MATERIAL      = 1<<3,
      MODEL         = 1<<4
    };
  }


struct Resource
{
  
};

}
