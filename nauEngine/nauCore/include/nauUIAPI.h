/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauUIAPI.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief API implementation interface object for Nautilus Engine
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
class NAU_CORE_EXPORT UIAPI 
{
public:
  UIAPI() = default;
  virtual ~UIAPI() = default;

  virtual bool
  init() = 0;

  virtual void
  newFrame() = 0;

  virtual void
  endFrame() = 0;

  virtual void
  render() = 0;
};

}


