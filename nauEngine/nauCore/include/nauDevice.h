/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDevice.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesCore.h"


namespace nauEngineSDK {

  ///FORWARD DECLARATIONS
  class ConstantBuffer;
  class DepthStencil;
  class IndexBuffer;
  class InputLayout;
  class RasterizerState;
  class RenderTargetView;
  class SamplerState;
  class Shader;
  class ShaderResourceView;
  class SwapChain;
  class Texture;
  class VertexBuffer;
  class ViewPort;
  ///

  namespace SHADERFLAGS {
    enum E {
      NONE = 0,
      PIXEL,
      VERTEX,
      COMPUTE,
      GEOMETRY,
      TEXTURE
    };

  }


  /**
   * nauDevice
   * Description:
   * 	The responsible for making the managing of the device to draw on screen
   * Sample usage:
   * 	
   */
  class NAU_CORE_EXPORT Device
  {
   public:
    /**
     * Default constructor
     */
    Device() = default;

    /**
     * Virtual constructor
     */
    virtual ~Device() = default;

    /**
     * @brief initializes device with the handler given
     * @param 
     * @return 
     *
     */
    virtual bool 
    initializeDevice(void* scrHandler) = 0;

    /**
     * @brief renders
     * @param 
     * @return 
     *
     */
    virtual void
    onRender() = 0;

    /**
     * @brief draws the information given
     * @param 
     * @return 
     *
     */
    virtual void
    draw(int size, int topology = 0, int startIndex = 0, int BaseVertex = 0) = 0;

    /**
     * @brief creates a buffer of specific type
     * @param 
     * @return 
     *
     */
    virtual bool
    createBuffer() = 0;

    /**
     * @brief creates a depth stencil view
     * @param 
     * @return 
     *
     */
    virtual bool
    createDepthStencilView() = 0;

    /**
     * Set Shader into the component
     */
    virtual void
    setShader(void* shader, SHADERFLAGS::E flags) = 0;

    /**
     * @brief Gets the device encapsulated in the Device object
     * @param
     * @return the device
     *
     */
    virtual void*
    get() = 0;


    /**
     * @brief Gets the device Context from the device
     * @param 
     * @return the device context
     *
     */
    virtual void*
    getContext() = 0;

    /**
     * @brief Creates a texture based up on the backbuffer
     * @param 
     * @return 
     *
     */
    virtual void*
    getSwapChain() = 0;

    /**
     * @brief gets the backBuffer from the swapChain
     * @param 
     * @return 
     *
     */
    virtual Texture*
    getBackBuffer() = 0;

    /**
     * @brief Creates a Vertex Shader
     * @param
     * @return a pointer Vertex Shader
     *
     */
    virtual Shader*
    createVertexShader() = 0;

    /**
     * @brief Creates a pixel shader
     * @param
     * @return a pointer to Pixel Shader
     *
     */
    virtual Shader*
    createPixelShader() = 0;

    /**
     * @brief Creates a texture
     * @param
     * @return a Texture
     *
     */
    virtual Texture*
    createTexture() = 0;

    /**
     * Creates an Input Layout
     */
    virtual InputLayout*
    createInputLayout() = 0;

    /**
     * Creates a ViewPort
     */
    virtual ViewPort*
    createViewPort() = 0;

    /**
     * @brief Creates a Sampler State
     * @param
     * @return a Sampler State
     *
     */
    virtual SamplerState*
    createSamplerState() = 0;

    /**
     * @brief Creates a Depth Stencil
     * @param
     * @return a Depth Stencil
     *
     */
    virtual DepthStencil*
    createDepthStencil() = 0;

    /**
     * @brief Creates a Vertex Buffer
     * @param
     * @return a vertex Buffer
     *
     */
    virtual VertexBuffer*
    createVertexBuffer() = 0;

    /**
     * @brief Creates an Index Buffer
     * @param
     * @return an Index Buffer
     *
     */
    virtual IndexBuffer*
    createIndexBuffer() = 0;

    /**
     * @brief Creates a Constant Buffer
     * @param
     * @return a Constant Buffer
     *
     */
    virtual ConstantBuffer*
    createConstantBuffer() = 0;

    /**
     * @brief Creates a shader resource view
     * @param 
     * @return a shader resource view in the given API
     *
     */
    virtual ShaderResourceView*
    createShaderResourceView() = 0;

    /**
     * @brief Creates a SwapChain object
     * @param 
     * @return a swap Chain based up on the given API
     *
     */
    virtual SwapChain*
    createSwapChain() = 0;

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual RenderTargetView*
    createRenderTargetView() = 0;
    
    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual RasterizerState*
    createRasterizer() = 0;




    /**
     * Member declaration
     */
   public:
    /**
     * the width of the window
     */
    uint32 m_width;

    /**
     * the height of the window
     */
    uint32 m_height;

    /**
     * SwapChain
     */
    SwapChain* m_swapChain = nullptr;
  };
  

}

