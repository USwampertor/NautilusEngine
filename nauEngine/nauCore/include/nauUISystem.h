/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauUISystem.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief UI System all wrapped up tight and nicely in a single object. This way
 *        the code doesn't look like shit in the long way
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"


#include <nauModule.h>

namespace nauEngineSDK {

namespace UISTARTFLAGS
{
  enum E
  {
    NONE = 0 << 0

  };
}

namespace UIWINDOWFLAGS 
{
  enum E
  {
    NONE = 0 << 0
  };
}

namespace UIRENDERFLAGS
{
  enum E
  {
    NONE
  };
}


class UISystem : public Module<UISystem>
{
public:
  UISystem() = default;

  ~UISystem() = default;




};

}

