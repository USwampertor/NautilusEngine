/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDepthStencilView.h
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
    * nauDepthStencilView
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT nauDepthStencilView
  {
   public:

    /*
     * Default constructor
     */
    nauDepthStencilView() = default;

    /*
     * virtual destructor
     */
    virtual ~nauDepthStencilView() {}

    /**
     * @brief gets the depth stencil vew
     * @param 
     * @return 
     *
     */
    virtual void
    createDepthStencilViewDescriptor(void* pDevice,
                                     void* pDeviceContext) = 0;
  };
  
}

