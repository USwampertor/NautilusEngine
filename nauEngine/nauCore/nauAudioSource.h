/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauAudioSource.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/02 2019
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauAudioClip.h"

namespace nauEngineSDK {
class AudioEmitter
{
public:
  AudioEmitter() = default;

  ~AudioEmitter() = default;

  void
  play();

  void
  stop();

  void
  playOneShot();

  AudioClip m_clip;

};
}

