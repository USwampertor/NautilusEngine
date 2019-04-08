/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDeviceDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X Device class
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesDX.h"

#include <nauDevice.h>



namespace nauEngineSDK {

  class NAU_DIRECTX_EXPORT DeviceDX : public Device
  {
   public:
    /**
     * Default constructor
     */
    DeviceDX() = default;
    
    /**
     * Default destructor
     */
    ~DeviceDX() = default;
    
    virtual bool 
    initializeDevice(void* scrHandler) override;
  
    virtual void
    onRender() override;

    virtual void
    draw(int size, int topology = 0, int startIndex = 0, int BaseVertex = 0) override;

    virtual bool
    createBuffer() override;

    virtual bool
    createDepthStencilView() override;

    virtual void
    setShader(void* shader, SHADERFLAGS::E flags) override;


    ///GETTERS///

    virtual void*
    get() override;

    virtual void*
    getContext() override;

    virtual void*
    getSwapChain() override;

    virtual Texture*
    getBackBuffer() override;
    ///EVENTS///

    ///CONSTRUCTORS///

    virtual Shader*
    createVertexShader() override;

    virtual Shader*
    createPixelShader() override;

    virtual Texture*
    createTexture() override;

    virtual InputLayout*
    createInputLayout() override;

    virtual ViewPort*
    createViewPort() override;

    virtual SamplerState*
    createSamplerState() override;

    virtual DepthStencil*
    createDepthStencil() override;

    virtual VertexBuffer*
    createVertexBuffer() override;

    virtual IndexBuffer*
    createIndexBuffer() override;

    virtual ConstantBuffer*
    createConstantBuffer() override;

    virtual ShaderResourceView*
    createShaderResourceView() override;

    virtual SwapChain*
    createSwapChain() override;

    virtual RenderTargetView*
    createRenderTargetView() override;

    virtual RasterizerState*
    createRasterizer() override;

  public:

    /**
     * window handler
     */
    HWND m_handler;

    /**
     * DirectX device pointer
     */
    ID3D11Device* m_pd3dDevice = nullptr;

    /**
     * DirectX immediate context pointer
     */
    ID3D11DeviceContext* m_pImmediateContext = nullptr;

  };
  
}

