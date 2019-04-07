/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRenderTargetView.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauDevice.h"
#include "nauDepthStencil.h"
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
     * @param void* device and void* swapChain 
     * @return 
     *
     */
    virtual bool
    createRenderTargetView(Device* pDevice, void* pSwapChain) = 0;

    virtual void
    set(Device& pDevice, DepthStencil& depthStencil) = 0;

    virtual void
    clearView(Device* pDevice, Vector4 color) = 0;

  };
  
}

