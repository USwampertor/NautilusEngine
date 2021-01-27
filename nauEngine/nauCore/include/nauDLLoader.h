/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauDLLoader.h
 * @author Marco "Swampy" Millan
 * @date 11/12/2019
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauLogger.h"

#include <nauModule.h>

namespace nauEngineSDK {

class NAU_CORE_EXPORT DLLoader : public Module<DLLoader>
{
public:
  /**
   * Default constructor
   */
  DLLoader() = default;

  /**
   * Default destructor
   */
  ~DLLoader() = default;

  void
  init();

  void*
  load(String path, String functionName);
};

}

