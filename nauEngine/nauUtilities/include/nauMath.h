/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file naumath.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief File defines if we gonna be using the specific library or the general
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauPlatformMath.h"

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# include "nauWindowsMath.h"
#endif

namespace nauEngineSDK {
#if NAU_PLATFORM == NAU_PLATFORM_WIN32
  using Math = WindowsMath;
#else
  using Math = PlatformMath;
#endif

}