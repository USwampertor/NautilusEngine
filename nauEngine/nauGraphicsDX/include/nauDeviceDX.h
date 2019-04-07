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
    
    bool 
    initializeDevice(void* scrHandler) override;
  
    void
    onRender() override;

    void
    draw(int size, int topology = 0, int startIndex = 0, int BaseVertex = 0) override;

    bool
    createBuffer() override;

    bool
    createDepthStencilView() override;

    ///GETTERS///

    void*
    get() override;

    void*
    getContext() override;

    void*
    getSwapChain() override;
    ///EVENTS///

    ///CONSTRUCTORS///
    /**
     * @brief Creates a Vertex Shader
     * @param
     * @return a pointer Vertex Shader
     *
     */
    Shader*
    createVertexShader() override;

    /**
     * @brief Creates a pixel shader
     * @param
     * @return a pointer to Pixel Shader
     *
     */
    Shader*
    createPixelShader() override;

    /**
     * @brief Creates a texture
     * @param
     * @return a Texture
     *
     */
    Texture*
    createTexture() override;

    /**
     * Creates an Input Layout
     */
    virtual InputLayout*
    createInputLayout() override;

    /**
     * Creates a ViewPort
     */
    ViewPort*
    createViewPort() override;

    /**
     * @brief Creates a Sampler State
     * @param
     * @return a Sampler State
     *
     */
    SamplerState*
    createSamplerState() override;

    /**
     * @brief Creates a Depth Stencil
     * @param
     * @return a Depth Stencil
     *
     */
    DepthStencil*
    createDepthStencil() override;

    /**
     * @brief Creates a Vertex Buffer
     * @param
     * @return a vertex Buffer
     *
     */
    VertexBuffer*
    createVertexBuffer() override;

    /**
     * @brief Creates an Index Buffer
     * @param
     * @return an Index Buffer
     *
     */
    IndexBuffer*
    createIndexBuffer() override;

    /**
     * @brief Creates a Constant Buffer
     * @param
     * @return a Constant Buffer
     *
     */
    ConstantBuffer*
    createConstantBuffer() override;

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

