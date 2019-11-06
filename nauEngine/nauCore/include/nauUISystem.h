/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauUISystem.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief UI System all wrapped up tight and nicely in a single object. This way
 *        the code doesn't look like shit in the long way
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauUIAPI.h"

#include <nauModule.h>

#include "imgui.h"
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


class NAU_CORE_EXPORT UISystem : public Module<UISystem>
{
public:
  UISystem() = default;

  ~UISystem() = default;

  bool
  init();

  void
  render();

  /**
   * @brief This to wrap the initialization process for the imgui frame renderings
   * @param 
   * @return 
   *
   */
  void
  newFrame();

  /**
   * @brief This to wrap the finalization process for the imgui frame rendering
   * @param 
   * @return 
   *
   */
  void
  endFrame();

  /**
   * @brief Renders the basic UI information that should always exist in the engine
   * @param 
   * @return 
   *
   */
  void
  renderProjectMenu();

  /**
   * @brief Renders an inspector in the engine.
   * @param 
   * @return 
   *
   */
  void
  renderInspector();

  void
  renderBaseUI();

  /**
   * This object should exist and be initialized only once. This is the constant
   * reference for ImGui to exist.
   */
  ImGuiIO& m_ui;
};

}

