#pragma once
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauPrerequisitesUtilh.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief All needed files to run the Utilities part with no problem
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauPlatformDefines.h"
#if NAU_COMPILER == NAU_COMPILER_CLANG
  /** @ref scriptBindingMacro */
# define NAU_SCRIPT_EXPORT(...) __attribute__((annotate("se," #__VA_ARGS__)))
#else
  /** @ref scriptBindingMacro */
# define NAU_SCRIPT_EXPORT(...)
#endif

#include "nauPlatformTypes.h"                             //Platform types
#include "nauPlatformUtilities.h"                         //Platform Utilities
