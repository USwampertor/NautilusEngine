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
    InputDevice() = default;

    virtual
    ~InputDevice() = default;

    virtual void
    init(DEVICE::TYPE type, void* data) = 0;

    virtual void*
    get() = 0;

    virtual DEVICE::TYPE
    getType() = 0;

  private:
    DEVICE::TYPE m_device;
  };
}