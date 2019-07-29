/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGAPrerequisites.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/25 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include <nauPrerequisitesCore.h>

#include <gainput/gainput.h>

namespace nauEngineSDK {
#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# if NAU_COMPILER == NAU_COMPILER_MSVC
#   if defined( NAU_STATIC_LIB )
#     define NAU_GAINPUT_EXPORT
#   else
#     if defined( NAU_GAINPUT_EXPORTS )
#       define NAU_GAINPUT_EXPORT __declspec( dllexport )
#     else
#       define NAU_GAINPUT_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( NAU_STATIC_LIB )
#     define NAU_GAINPUT_EXPORT
#   else
#     if defined( NAU_GAINPUT_EXPORTS )
#       define NAU_GAINPUT_EXPORT __attribute__ ((dllexport))
#     else
#       define NAU_GAINPUT_EXPORT __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define NAU_GAINPUT_HIDDEN
#else //Linux/Mac Settings
# define NAU_GAINPUT_EXPORT __attribute__ ((visibility ("default")))
# define NAU_GAINPUT_HIDDEN __attribute__ ((visibility ("hidden")))
#endif
}