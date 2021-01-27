/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauPrerequisitesCore.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief definition of the dll and static library export for the core part
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once

#include <nauPrerequisitesUtil.h>        //Here we add the utilities export

/**
* Library export specifics
*/
#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# if NAU_COMPILER == NAU_COMPILER_MSVC
#   if defined( NAU_STATIC_LIB )
#     define NAU_CORE_EXPORT
#   else
#     if defined( NAU_CORE_EXPORTS )
#       define NAU_CORE_EXPORT __declspec( dllexport )
#     else
#       define NAU_CORE_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( NAU_STATIC_LIB )
#     define NAU_CORE_EXPORT
#   else
#     if defined( NAU_CORE_EXPORTS )
#       define NAU_CORE_EXPORT __attribute__ ((dllexport))
#     else
#       define NAU_CORE_EXPORT __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define NAU_CORE_HIDDEN
#else //Linux/Mac Settings
# define NAU_CORE_EXPORT __attribute__ ((visibility ("default")))
# define NAU_CORE_HIDDEN __attribute__ ((visibility ("hidden")))
#endif

#if NAU_COMPILER == NAU_COMPILER_MSVC
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commdlg.h>
#endif
