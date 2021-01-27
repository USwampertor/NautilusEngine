/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauShaderResourceView.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauDevice.h"
#include "nauTexture.h"
#include "nauTextureDescriptor.h"

namespace nauEngineSDK {

   /**
    * nauShaderResourceView
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class ShaderResourceView
  {
   public:

    /**
     * Default constructor
     */
    ShaderResourceView() = default;
    
    /**
     * virtual destructor
     */
    virtual 
    ~ShaderResourceView() = default;

    /**
     * @brief Creates a shader resource view
     * @param void* device
     * @return true if able to create
     *
     */
    virtual bool
    createShaderResourceView(Device* pDevice, void* texture, NAUTEXTUREDESCRIPTOR desc) = 0;

    /**
     * @brief Creates a shader resource view
     * @param void* device
     * @return
     *
     */
    virtual void
    setShaderResourceView(Device* pDevice, 
                          uint32 start = 0, 
                          uint32 views = 1) = 0;

  };
  
}

