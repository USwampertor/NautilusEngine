/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGaInputManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/25 2019
 * @brief GAINPUT Input Manager implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauGaInputManager.h"

namespace nauEngineSDK {
  void
  GAInputManager::init() {

    //Default Devices
    GAInputDevice* device = new GAInputDevice();
    device->init(DEVICE::KEYBOARD, 
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceKeyboard>()));
    addDevice(device);
    
    device = new GAInputDevice();
    device->init(DEVICE::MOUSE,
      reinterpret_cast<void*>(m_manager.CreateDevice<gainput::InputDeviceMouse>()));
    addDevice(device);
  }

  void
  GAInputManager::update() {

  }

  void*
  GAInputManager::getManager() {
  
  }

  bool
  GAInputManager::isMousePresent() {
  
  }

  bool
  GAInputManager::isKeyBoardPresent() {
  
  }

  bool
  GAInputManager::isJoyStickPresent(uint32 keycode) {
  
  }

  bool
  GAInputManager::getKeyDown(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getKeyUp(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getKey(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getButtonDown(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getButtonUp(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getButton(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getMouseButtonDown(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getMouseButtonUp(KEY::CODE keycode) {
  
  }

  bool
  GAInputManager::getMouseButton(KEY::CODE keycode) {
  
  }

  Vector2
  GAInputManager::getMousePosition() {
  
  }

  float
  GAInputManager::getScrollDelta() {
  
  }

  Vector3
  GAInputManager::acceleration() {
  
  }

  bool
  GAInputManager::anyKey() {
  
  }

  float
  GAInputManager::getAxis(AXIS::E axis) {
  
  }

  void
  GAInputManager::registerKey(KEY::CODE key, DEVICE::TYPE type) {

  }
}
