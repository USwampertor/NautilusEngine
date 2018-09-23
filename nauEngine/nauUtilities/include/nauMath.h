/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file naumath.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief File defines if we gonna be using the specific library or the general
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/


#pragma once
namespace nauEngineSDK{

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
#include "nauWindowsMath.h"
using nauMath = nauWindowsMath;
#else
#  include "nauPlatformMath.h"
using nauMath = nauPlatformMath;
#endif

}