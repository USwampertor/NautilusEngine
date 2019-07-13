/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAudioSource.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/02 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauAudioClip.h"

namespace nauEngineSDK {
class AudioSource
{
public:
  /**
   * Default constructor
   */
  AudioSource() = default;

  /**
   * Default destructor
   */
  ~AudioSource() = default;

  /**
   * @brief Starts the audio Object
   * @param 
   * @return 
   *
   */
  void
  play();

  /**
   * Stops the audio Object
   */
  void
  stop();

  /**
   * Starts only once the audio Object
   */
  void
  playOneShot();

  /**
   * Audio clip object stored inside
   */
  Sptr<AudioClip> m_clip;

};
}

