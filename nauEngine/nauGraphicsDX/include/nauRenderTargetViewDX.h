/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRenderTargetViewDX.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/07 2019
 * @brief Render target view implementation in DX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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
    createRenderTargetView(Device* pDevice, Texture* texture) override;

    virtual void
    set(Device& pDevice, DepthStencil& depthStencil, int32 position = 1) override;

    virtual void
    clearView(Device* pDevice, Vector4 color) override;

    virtual void*
    getRendereableTexture(Device* pDevice) override;

    virtual void*
    getRenderTarget() override;

    ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
  };
}

