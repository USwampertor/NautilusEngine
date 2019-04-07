/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTextureDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/28 2018
 * @brief Texture implementation for DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauTexture.h>

namespace nauEngineSDK {
  class NAU_DIRECTX_EXPORT TextureDX : public Texture
  {
   public:

    /**
     * Default constructor
     */
    TextureDX() = default;

    /**
     * Default destructor
     */
    ~TextureDX() = default;

    bool
    loadFromFile(String path, void* pDevice, void* pDeviceContext);

    bool
    createShaderResourceView(void* pDevice);

    void
    setShaderResourceView(void* pDevice);

    bool
    createRenderTargetView(void* pDevice, void* pDeviceContext);

    bool
    createDepthStencilView(void* pDevice, void* pDeviceContext);

    bool
    createDepthstencil(void* pDevice,
                       void* pDeviceContext,
                       uint32 width,
                       uint32 height);

    bool
    createShaderSampler(void* pDevice);

    bool
    setShaderSampler(void* pDevice);



    /**
     * Member declaration
     */
   public:
    
    /**
     * ID3D11 texture
     */
    ID3D11Texture2D* m_pd3dTexture2D = nullptr;
    
    /**
     * Depth stencil view
     */
    ID3D11DepthStencilView* m_DepthStencilView = nullptr;

    /**
     * Shader Resource View
     */
    ID3D11ShaderResourceView* m_shaderResource = nullptr;

    /**
     * Render target view
     */
    ID3D11RenderTargetView* m_pRenderTargetView = nullptr;

    
  };
}

