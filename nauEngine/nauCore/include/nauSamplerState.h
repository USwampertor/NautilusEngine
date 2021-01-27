/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauSamplerState.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauDevice.h"

namespace nauEngineSDK {


  class Device;
  /**
   * nauSamplerState
   * Description:
   *    Sampler state for API implementation
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
    virtual
      ~SamplerState() = default;

    /**
     * @brief creates a shader sampler
     * @param void* device
     * @return true if created
     *
     */
    virtual bool
    createSampler(Device* pDevice) = 0;

    /**
     * @brief sets the shader into a device
     * @param the device
     * @return
     *
     */
    virtual void
    setSampler(Device* pDevice, uint32 registration = 0, uint32 times = 1) = 0;
  };

}

