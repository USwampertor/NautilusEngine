/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/23 2019
 * @brief Input Manager
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauModule.h"
#include "nauInput.h"

#include <nauVector3.h>
#include <nauVector2.h>

namespace nauEngineSDK {
class InputManager : public Module<InputManager>
{
public:
  /**
   * Default constructor
   */
  InputManager() = default;

  /**
   * Default destructor
   */
  ~InputManager() = default;
  
  /**
   * @brief initializes the input manager and all default inputs available
   * @param 
   * @return 
   *
   */
  void
  init();

  /**
   * @brief returns the plugin-managed object in charge of the management of objects
   * @param 
   * @return 
   *
   */
  void*
  getManager();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  registerDevice(KEY::CODE newkey);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  isMousePresent();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  isKeyBoardPresent();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  isJoyStickPresent(KEY::CODE keycode);

  /**
   * @brief returns if any key or button is being pressed
   * @param 
   * @return 
   *
   */
  bool
  getKeyDown(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  getKeyUp(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  getKey(KEY::CODE keycode);

  /**
   * @brief returns if any key or button is being pressed
   * @param 
   * @return 
   *
   */
  bool
  getButtonDown(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  getButtonUp(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  getButton(KEY::CODE keycode);

  /**
   * @brief returns if any key or button is being pressed
   * @param 
   * @return 
   *
   */
  bool
  getMouseButtonDown(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  getMouseButtonUp(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  bool
  getMouseButton(KEY::CODE keycode);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  Vector2
  getMousePosition();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  float
  getScrollDelta();

  /**
   * @brief returns the acceleration given at the last frame
   * @param 
   * @return 
   *
   */
  Vector3
  acceleration();

  /**
   * @brief Returns true if any key is being pressed
   * @param 
   * @return true if theres any key being pressed
   *
   */
  bool
  anyKey();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  float
  getAxis(AXIS::E axis);

private:

  void
  setState(KEY::CODE);

};
}


