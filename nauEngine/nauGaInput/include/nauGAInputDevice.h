/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGAInputDevice.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/25 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauGAPrerequisites.h"

#include <nauInputDevice.h>

namespace nauEngineSDK {
class NAU_GAINPUT_EXPORT GAInputDevice : public InputDevice
{
public:
  GAInputDevice() = default;

  ~GAInputDevice() = default;

  virtual void
  init(DEVICE::TYPE type, void* data) override;
  
  virtual void*
  get() override;
  
  virtual void
  clean() override;

private:
  gainput::InputDevice* m_inputDevice;
};

}

