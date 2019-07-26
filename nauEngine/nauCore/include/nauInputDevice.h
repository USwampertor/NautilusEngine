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
  class NAU_CORE_EXPORT InputDevice
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

  private:
    /**
     * The type of this device
     */
    DEVICE::TYPE m_device;

    /**
     * The horizontal axis value the device has right now
     */
    float m_horizontalAxis;

    /**
     * The vertical value the device has right now
     */
    float m_verticalAxis;

    /**
     * Device ID
     */
    uint32 m_ID;
  };
}