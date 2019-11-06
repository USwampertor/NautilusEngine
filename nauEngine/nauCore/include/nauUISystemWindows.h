/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauUISystemWindows.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauUISystem.h"

namespace nauEngineSDK {
class NAU_CORE_EXPORT UISystemWindows : public UISystem
{
public:
  UISystemWindows() = default;
  ~UISystemWindows() = default;

  bool
  init();

  void
  newFrame();

  void
  endFrame();

};

}

