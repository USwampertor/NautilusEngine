/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauDepthStencilDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesDX.h"

#include <nauDepthStencil.h>

#include "nauTextureDX.h"

namespace nauEngineSDK {

  class nauDepthStencilDX : public nauDepthStencil
  {
  public:

    /**
     * default constructor
     */
    nauDepthStencilDX() = default;

    /**
     * default destructor
     */
    ~nauDepthStencilDX() {}
  

    bool
    createDepthStencil(void* pDevice,
                       void* pDeviceContext,
                       uint32 height,
                       uint32 width,
                       nauTexture* texture);
  };
  
}


