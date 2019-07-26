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
#include "nauInputDevice.h"

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
  virtual
  ~InputManager() = default;
  
  /**
   * @brief initializes the input manager and all default inputs available
   * @param 
   * @return 
   *
   */
  virtual void
  init() = 0;

  /**
   * @brief returns the plugin-managed object in charge of the management of objects
   * @param 
   * @return 
   *
   */
  virtual void*
  getManager() = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  addDevice(InputDevice* device) { m_devices.push_back(device); }

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  isMousePresent() = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  isKeyBoardPresent() = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  isJoyStickPresent(KEY::CODE keycode) = 0;

  /**
   * @brief returns if any key or button is being pressed
   * @param 
   * @return 
   *
   */
  virtual bool
  getKeyDown(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  getKeyUp(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  getKey(KEY::CODE keycode) = 0;

  /**
   * @brief returns if any key or button is being pressed
   * @param 
   * @return 
   *
   */
  virtual bool
  getButtonDown(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  getButtonUp(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  getButton(KEY::CODE keycode) = 0;

  /**
   * @brief returns if any key or button is being pressed
   * @param 
   * @return 
   *
   */
  virtual bool
  getMouseButtonDown(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  getMouseButtonUp(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual bool
  getMouseButton(KEY::CODE keycode) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual Vector2
  getMousePosition() = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual float
  getScrollDelta() = 0;

  /**
   * @brief returns the acceleration given at the last frame
   * @param 
   * @return 
   *
   */
  virtual Vector3
  acceleration() = 0;

  /**
   * @brief Returns true if any key is being pressed
   * @param 
   * @return true if theres any key being pressed
   *
   */
  virtual bool
  anyKey() = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual float
  getAxis(AXIS::E axis) = 0;

  virtual void
  setState(KEY::CODE) = 0;

  virtual void
  registerKey(KEY::CODE key, DEVICE::TYPE type) = 0;

private:

  Vector<InputDevice*> m_devices;
};
}


