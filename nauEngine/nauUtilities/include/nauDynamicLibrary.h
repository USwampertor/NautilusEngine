/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDynamicLibrary.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/28 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauModule.h"

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# include "windows.h"
#elif NAU_PLATFORM == NAU_PLATFORM_LINUX

#endif

namespace nauEngineSDK {
class DynamicLibrary : public Module<DynamicLibrary>
{
public:
  DynamicLibrary() = default;

  ~DynamicLibrary() = default;

  void*
  LoadLibrary(String path, String functionName = "createFactory");

};
}

