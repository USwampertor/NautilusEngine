/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDepthStencilDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesDX.h"

#include <nauDepthStencil.h>


namespace nauEngineSDK {

  class NAU_DIRECTX_EXPORT DepthStencilDX : public DepthStencil
  {
   public:

    /**
     * default constructor
     */
    DepthStencilDX() = default;

    /**
     * default destructor
     */
    ~DepthStencilDX() = default;

    bool
    createDepthStencil(void* pDevice,
                       void* pDeviceContext,
                       uint32 height,
                       uint32 width,
                       Texture* texture);
  
  };
  
}


