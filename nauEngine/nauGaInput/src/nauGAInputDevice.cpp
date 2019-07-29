#include "nauGAInputDevice.h"

namespace nauEngineSDK {
  void
  GAInputDevice::init(DEVICE::TYPE type, void* data) {
    m_device = type;
    m_ID = reinterpret_cast<uint32>(data);
    clean();
  }
  
  void*
  GAInputDevice::get() {
    return reinterpret_cast<void*>(m_ID);
  }
  
  void
  GAInputDevice::clean() {
    InputDevice::clean();
  }
}