/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputDevice.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/25 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauInput.h"

namespace nauEngineSDK {
  class InputDevice
  {
  public:
    /**
     * Default constructor
     */
    InputDevice() = default;

    /**
     * Default destructor
     */
    virtual
    ~InputDevice() = default;

    /**
     * @brief Creates a new Input Device managed by the plugin, and *SHOULD*
     *        register the default buttons that the device has.
     * @param DEVICE::TYPE enum type of the device to register
     * @param void* data. It is reserved for the plugin to send plugin info
     * @return 
     *
     */
    virtual void
    init(DEVICE::TYPE type, void* data) = 0;

    /**
     * @brief Returns Plugin specific data stored inside the InputDevice
     * @param 
     * @return void* to plugin specific info inside the device 
     *
     */
    virtual void*
    get() = 0;

    /**
     * @brief Cleans the device input information. This function only cleans base properties
     * @param 
     * @return 
     *
     */
    virtual void
    clean() {
      m_isActive = false;
      m_leftHorizontalAxis = 0.0f;
      m_leftVerticalAxis = 0.0f;
      m_rightHorizontalAxis = 0.0f;
      m_rightVerticalAxis = 0.0f;
    }

    /**
     * @brief Returns the type this device is
     * @param 
     * @return DEVICE::TYPE enum type of device
     *
     */
    DEVICE::TYPE
    getType() { return m_device; }

    /**
     * @brief Returns the ID of this device
     * @param 
     * @return uint32 ID
     *
     */
    uint32
    getID() { return m_ID; }

    void
    setActive(bool activeState) { m_isActive = activeState; }

    bool
    isActive() { return m_isActive; }

    float
    getAxis(JOYSTICK::E side, AXIS::E axis) {
      return (JOYSTICK::LEFT == side) ? 
        (AXIS::HORIZONTAL == axis) ? m_leftHorizontalAxis  : m_leftVerticalAxis : 
        (AXIS::HORIZONTAL == axis) ? m_rightHorizontalAxis : m_rightVerticalAxis;
    }

  protected:
    /**
     * The type of this device
     */
    DEVICE::TYPE m_device;

    /**
     * The horizontal left axis value the device has right now
     */
    float m_leftHorizontalAxis;

    /**
     * The vertical left axis value the device has right now
     */
    float m_leftVerticalAxis;

    /**
     * The horizontal right axis value the device has right now
     */
    float m_rightHorizontalAxis;

    /**
     * The vertical right axis value the device has right now
     */
    float m_rightVerticalAxis;

    /**
     * Device ID
     */
    uint32 m_ID;

    /**
     * Is the device active? Should the Manager receive inputs from it?
     */
    bool m_isActive;
  };
}