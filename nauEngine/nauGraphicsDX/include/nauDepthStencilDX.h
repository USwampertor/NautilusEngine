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
    ~DepthStencilDX() {}
  
  };
  
}


