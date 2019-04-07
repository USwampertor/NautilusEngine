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
  class Shader;
  class DepthStencil;
  class Texture;
  class InputLayout;
  class ViewPort;
  class IndexBuffer;
  class VertexBuffer;
  class ConstantBuffer;
  class SamplerState;
  ///

  /**
   * nauDevice
   * Description:
   * 	The responsible for making the managing of the device to draw on screen
   * Sample usage:
   * 	
   */
  class Device
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

    virtual void*
    getSwapChain() = 0;


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

  };
  

}

