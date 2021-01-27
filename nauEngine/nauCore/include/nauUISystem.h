/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauUISystem.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief UI System all wrapped up tight and nicely in a single object. This way
 *        the code doesn't look like shit in the long way
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauUIAPI.h"

#include <nauModule.h>

#include "imgui.h"

namespace nauEngineSDK {

class GraphicsAPI;
class MeshComponent;
class Logger;
class SceneManager;
class InputManager;
class GameObject;
class CameraManager;

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

  /**
   * Default constructor
   */
  UISystem() = default;

  /**
   * Default destructor
   */
  virtual ~UISystem() = default;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  init(ImGuiIO& io, void* hwnd);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual void
  render();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual void
  endRender();

  /**
   * @brief This to wrap the initialization process for the ImGui frame renderings
   * @param 
   * @return 
   *
   */
  virtual void
  newFrame();

  /**
   * @brief This to wrap the finalization process for the ImGui frame rendering
   * @param 
   * @return 
   *
   */
  virtual void
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

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  renderBaseUI();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual void
  finishUI();


  /**
   * This object should exist and be initialized only once. This is the constant
   * reference for ImGui to exist.
   */
  ImGuiIO* m_ui;

  /**
   * Testing accumulated delta
   */
  float m_accumulatedDelta = 0.0f;
  
  /**
   * if true, it will render the inspector of the game object
   */
  bool m_inspector = false;

  /**
   * Game Object being visualized in the inspector
   */
  GameObject* m_gameObjectPtr = nullptr;

  virtual bool
  updateInput() { return true; }
};

}

