/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauDepthStencilView.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
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
    createDepthStencilViewDescriptor(void* pDevice,
                                     void* pDeviceContext) = 0;
  };
  
}

