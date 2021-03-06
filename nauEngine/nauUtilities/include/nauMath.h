/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file naumath.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief File defines if we gonna be using the specific library or the general
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauPlatformMath.h"

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# include "nauWindowsMath.h"
#endif

namespace nauEngineSDK {
#if NAU_PLATFORM == NAU_PLATFORM_WIN32
  using nauMath = nauWindowsMath;
#else
  using nauMath = nauPlatformMath;
#endif

}