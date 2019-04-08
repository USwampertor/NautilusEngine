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

    ///GETTERS///

    virtual void*
    get() override;

    virtual void*
    getContext() override;

    virtual void*
    getSwapChain() override;
    ///EVENTS///

    ///CONSTRUCTORS///
    /**
     * @brief Creates a Vertex Shader
     * @param
     * @return a pointer Vertex Shader
     *
     */
    virtual Shader*
    createVertexShader() override;

    /**
     * @brief Creates a pixel shader
     * @param
     * @return a pointer to Pixel Shader
     *
     */
    virtual Shader*
    createPixelShader() override;

    /**
     * @brief Creates a texture
     * @param
     * @return a Texture
     *
     */
    virtual Texture*
    createTexture() override;

    /**
     * Creates an Input Layout
     */
    virtual InputLayout*
    createInputLayout() override;

    /**
     * Creates a ViewPort
     */
    virtual ViewPort*
    createViewPort() override;

    /**
     * @brief Creates a Sampler State
     * @param
     * @return a Sampler State
     *
     */
    virtual SamplerState*
    createSamplerState() override;

    /**
     * @brief Creates a Depth Stencil
     * @param
     * @return a Depth Stencil
     *
     */
    virtual DepthStencil*
    createDepthStencil() override;

    /**
     * @brief Creates a Vertex Buffer
     * @param
     * @return a vertex Buffer
     *
     */
    virtual VertexBuffer*
    createVertexBuffer() override;

    /**
     * @brief Creates an Index Buffer
     * @param
     * @return an Index Buffer
     *
     */
    virtual IndexBuffer*
    createIndexBuffer() override;

    /**
     * @brief Creates a Constant Buffer
     * @param
     * @return a Constant Buffer
     *
     */
    virtual ConstantBuffer*
    createConstantBuffer() override;

    virtual ShaderResourceView*
    createShaderResourceView() override;
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

    /**
     * DirectX swap chain
     */
    IDXGISwapChain* m_pSwapChain = nullptr;


  };
  
}

