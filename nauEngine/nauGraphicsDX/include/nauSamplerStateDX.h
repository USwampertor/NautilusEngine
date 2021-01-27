/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauSamplerStateDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief sampler implemented in DirectX
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once
#include "nauPrerequisitesDX.h"

#include <nauSamplerState.h>

namespace nauEngineSDK {

  class NAU_DIRECTX_EXPORT SamplerStateDX : public SamplerState
  {
   public:

    /**
     * Default constructor
     */
    SamplerStateDX() = default;

    /**
     * default destructor
     */
    ~SamplerStateDX() = default;

    virtual bool
    createSampler(Device* pDevice) override;

    virtual void
    setSampler(Device* pDevice, uint32 registration = 0, uint32 times = 1) override;
    
    /**
     * Member declaration
     */
   public:

    /**
     * Sampler state
     */
    ID3D11SamplerState* m_sampleState = nullptr;
  };
}


