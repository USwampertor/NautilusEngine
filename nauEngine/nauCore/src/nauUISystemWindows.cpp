/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauUISystemWindows.cpp
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief Windows Defined System implementation
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauUISystemWindows.h"


namespace  nauEngineSDK {

  bool
  UISystemWindows::init() {
    if (!init()) return false;
  }

  void
  UISystemWindows::newFrame() {
    UISystem::newFrame();
  }

  void
  UISystemWindows::endFrame() {
    UISystem::endFrame();
  }
}
