/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSamplerState.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  
  /**
   * nauSamplerState
   * Description:
   * 	
   * Sample usage:
   * 	
   */
  class NAU_CORE_EXPORT nauSamplerState
  {
  public:

    /**
     * default constructor
     */
    nauSamplerState() = default;

    /**
     * virtual destructor
     */
    virtual ~nauSamplerState() {}

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
    virtual bool
    setShaderSampler(void* pd3dDevice) = 0;
  };
  
}

