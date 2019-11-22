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

#include "nauGAPrerequisites.h"

#include "nauGAInputDevice.h"

#include <nauInputManager.h>
#include <nauLogger.h>

namespace nauEngineSDK {

  class NAU_GAINPUT_EXPORT GAInputManager : public InputManager
  {
  public:
    /**
     * Default constructor
     */
    GAInputManager() = default;

    /**
     * Default destructor
     */
    ~GAInputManager() = default;

    virtual void
    init() override;

    virtual void
    update() override;

    virtual void
    handleMessage(void* message) override;

    virtual void
    removeDevice(InputDevice* device) override;

    virtual void
    mapButton(uint32 ID, 
              DEVICE::TYPE deviceType, 
              KEY::CODE toMap, 
              bool isFloat = false) override;

    virtual void
    mapButton(InputDevice* device, 
              KEY::CODE newKey, 
              bool isFloat = false) override;

    virtual void*
    getManager() override;

    virtual bool
    isMousePresent() override;

    virtual bool
    isKeyBoardPresent() override;

    virtual bool
    isJoyStickPresent(uint32 keycode) override;

    virtual bool
    getKeyDown(KEY::CODE keycode) override;

    virtual bool
    getKeyUp(KEY::CODE keycode) override;

    virtual bool
    getKey(KEY::CODE keycode) override;

    virtual bool
    getButtonDown(KEY::CODE keycode) override;

    virtual bool
    getButtonUp(KEY::CODE keycode) override;

    virtual bool
    getButton(KEY::CODE keycode) override;

    virtual bool
    getMouseButtonDown(KEY::CODE keycode) override;

    virtual bool
    getMouseButtonUp(KEY::CODE keycode) override;

    virtual bool
    getMouseButton(KEY::CODE keycode) override;

    virtual Vector2
    getMousePosition() override;

    virtual bool
    mouseMoved() override;

    virtual Vector2
    getMouseDelta() override;

    virtual float
    getScrollDelta() override;

    virtual Vector3
    acceleration() override;

    virtual bool
    anyKey() override;

    virtual float
    getAxis(uint32 ID, AXIS::E axis, JOYSTICK::E joystick) override;

    gainput::InputManager m_manager;

    gainput::InputMap* m_inputMap = nullptr;

    Map<KEY::CODE, gainput::DeviceButtonId> m_keyMap;
    
  };


  MS_ALIGN(16)
  extern "C" NAU_GAINPUT_EXPORT InputManager*
    createPluginAPI() {
    return new GAInputManager();
  }
  GCC_ALIGN(16)
}


