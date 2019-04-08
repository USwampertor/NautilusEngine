/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauSamplerStateDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief sampler implemented in DirectX
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

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
    createShaderSampler(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;
    
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


