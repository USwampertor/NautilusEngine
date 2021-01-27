/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauRenderTargetView.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauDepthStencil.h"
#include "nauDevice.h"
#include "nauTexture.h"
#include "nauVector4.h"

namespace nauEngineSDK {

   /**
    * nauRenderTargetView
    * Description:
    * 	Render Target View Object
    * Sample usage:
    * 	Outputs in the passes
    */
  class RenderTargetView
  {
   public:

    /**
     * default constructor
     */
    RenderTargetView() = default;

    /**
     * virtual destructor
     */
    virtual ~RenderTargetView() = default;

    /**
     * @brief Creates a shader resource view
     * @param void* device and Texture*
     * @return 
     *
     */
    virtual bool
    createRenderTargetView(Device* pDevice, Texture* texture) = 0;

    virtual void
    set(Device& pDevice, DepthStencil& depthStencil, int32 position = 1) = 0;

    virtual void
    clearView(Device* pDevice, Vector4 color) = 0;

    virtual void*
    getRendereableTexture(Device* pDevice) = 0;

    virtual void*
    getRenderTarget() = 0;

    uint32 m_width;

    uint32 m_height;

  };
  
}

