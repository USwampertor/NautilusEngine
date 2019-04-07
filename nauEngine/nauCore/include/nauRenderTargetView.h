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

namespace nauEngineSDK {

   /**
    * nauRenderTargetView
    * Description:
    * 	
    * Sample usage:
    * 	
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
    set(Device* pDevice, DepthStencil* depthStencil) = 0;

  };
  
}

