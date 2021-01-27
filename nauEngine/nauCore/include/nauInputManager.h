/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauInputManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/23 2019
 * @brief Input Manager
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauModule.h"
#include "nauInputDevice.h"

#include <nauVector3.h>
#include <nauVector2.h>

namespace nauEngineSDK {

  class GraphicsAPI;

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
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual void
  update() = 0;

  /**
   * @brief Handles messages given to the input system
   * @param void* data (normally a message object or structure)
   * @return -
   */
  virtual void
  handleMessage(void* message) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  addDevice(InputDevice* device) { m_devices[device->getType()].push_back(device); }

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual void
  removeDevice(InputDevice* device) = 0;

  /**
   * @brief Maps (Or lets you remap, a button to a specific Key or action)
   * @param 
   * @return 
   *
   */
  virtual void
  mapButton(uint32 ID, 
            DEVICE::TYPE deviceType, 
            KEY::CODE toMap, 
            bool isFloat = false) = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual void
  mapButton(InputDevice* device, 
            KEY::CODE newKey, 
            bool isFloat = false) = 0;

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
  isJoyStickPresent(uint32 id) = 0;

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
   * @brief returns true if there was any mouse movement between the last frame and this one
   * @param 
   * @return 
   *
   */
  virtual bool
  mouseMoved() = 0;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  virtual Vector2
  getMouseDelta() = 0;

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
  getAxis(uint32 ID, AXIS::E axis, JOYSTICK::E joystick) = 0;

protected:

  /**
   * Devices registered in the Manager
   */
  Vector<Vector<InputDevice*>> m_devices;

  /**
   * Position of the mouse on screen
   */
  Vector2 m_mousePosition;

  /**
   * Delta position between last frame and this one
   */
  float m_mousePositionDelta;

  /**
   * Mouse scroll delta between last frame and this one
   */
  float m_mouseScrollDelta;

};

extern NAU_CORE_EXPORT InputManager*
g_inputManager;
  
}


