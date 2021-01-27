/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauUI.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief Definition of which UI is being used, based on platform
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once


#include "nauPrerequisitesCore.h"
#include "nauUISystem.h"

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# include "nauUISystemWindows.h"
#endif


namespace nauEngineSDK {
  using UI = UISystem;
}
