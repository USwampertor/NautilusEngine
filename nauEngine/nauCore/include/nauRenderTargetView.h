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

namespace nauEngineSDK {

   /**
    * nauRenderTargetView
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT RenderTargetView
  {
   public:

    /**
     * default constructor
     */
    RenderTargetView() = default;

    /**
     * virtual destructor
     */
    virtual ~RenderTargetView() {}

    /**
     * @brief Creates a shader resource view
     * @param void* device and void* swapChain 
     * @return 
     *
     */
    virtual bool
    createRenderTargetView(void* pDevice, void* pSwapChain) = 0;

  };
  
}

