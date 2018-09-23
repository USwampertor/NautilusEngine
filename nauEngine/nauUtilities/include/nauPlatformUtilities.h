#pragma once
#include "nauPlatformTypes.h"
#include "nauPlatformDefines.h"

namespace nauEngineSDK {
  struct MACAddress {
    uint8 value[6];
  };
  
  struct GPUInfo {
    uint32 nGPUs;
  };

  struct SystemInfo {
    bool isx64OS;

    GPUInfo gpuInfo;
  };

  class NAU_UTILITY_EXPORT PlatformUtility {
   private:
    static GPUInfo m_gpuInfo;
  };
}
