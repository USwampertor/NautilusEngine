/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauRenderTargetViewDX.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/07 2019
 * @brief Render target view implementation in DX
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauRenderTargetView.h>

namespace nauEngineSDK {
  
  class NAU_DIRECTX_EXPORT RenderTargetViewDX : public RenderTargetView
  {
   public:

    /**
     * Default constructor
     */
    RenderTargetViewDX() = default;

    /**
     * Default destructor
     */
    ~RenderTargetViewDX() = default;

    virtual bool
    createRenderTargetView(Device* pDevice, void* pSwapChain) override;

    virtual void
    set(Device* pDevice, DepthStencil* depthStencil) override;

    ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
  };
}

