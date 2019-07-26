/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauGAInputDevice.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/25 2019
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#pragma once

#include "nauGAPrerequisites.h"
#include <nauInputDevice.h>

namespace nauEngineSDK {
class GAInputDevice : public InputDevice
{
public:
  GAInputDevice() = default;

  ~GAInputDevice() = default;

  virtual void
  init(DEVICE::TYPE type, void* data) override;

  virtual void*
  get() override;

private:

  gainput::DeviceId m_ID;
};

}

