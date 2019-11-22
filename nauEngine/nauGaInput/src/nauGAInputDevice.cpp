#include "nauGAInputDevice.h"

namespace nauEngineSDK {
  void
  GAInputDevice::init(DEVICE::TYPE type, void* data) {
    m_device = type;
    m_inputDevice = reinterpret_cast<gainput::InputDevice*>(data);
    m_ID = m_inputDevice->GetDeviceId();
    clean();
  }
  
  void*
  GAInputDevice::get() {
    return reinterpret_cast<void*>(m_inputDevice);
  }
  
  void
  GAInputDevice::clean() {
    InputDevice::clean();
  }
}