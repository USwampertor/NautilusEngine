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

  }

  void
  GAInputDevice::clean() {
    InputDevice::clean();
  }
}