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
#include "nauDevice.h"

namespace nauEngineSDK {
  
   /**
    * nauDepthStencilView
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT DepthStencilView
  {
   public:

    /*
     * Default constructor
     */
    DepthStencilView() = default;

    /*
     * virtual destructor
     */
    virtual ~DepthStencilView() {}

    /**
     * @brief gets the depth stencil vew
     * @param 
     * @return 
     *
     */
    virtual void
    createDepthStencilViewDescriptor(Device* pDevice) = 0;
  };
  
}

