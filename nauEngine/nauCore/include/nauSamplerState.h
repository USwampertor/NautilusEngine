/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauSamplerState.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauDevice.h"

namespace nauEngineSDK {
  
  /**
   * nauSamplerState
   * Description:
   * 	
   * Sample usage:
   * 	
   */
  class NAU_CORE_EXPORT SamplerState
  {
  public:

    /**
     * default constructor
     */
    SamplerState() = default;

    /**
     * virtual destructor
     */
    virtual ~SamplerState() {}

    /**
     * @brief creates a shader sampler
     * @param void* device
     * @return true if created
     *
     */
    virtual bool
    createShaderSampler(void* pDevice) = 0;

    /**
     * @brief sets the shader into a device
     * @param the device
     * @return 
     *
     */
    virtual void
    setShaderSampler(void* pDevice) = 0;
  };
  
}

