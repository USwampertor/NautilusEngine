/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCoreFactory.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/14 2019
 * @brief Core Factory for creation of Graphic objects for plugin calling
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauDepthStencil.h"
#include "nauGraphicsAPI.h"
#include "nauGraphicsBuffer.h"
#include "nauModule.h"
#include "nauInputLayout.h"
#include "nauShader.h"
#include "nauSamplerState.h"
#include "nauTexture.h"
#include "nauViewPort.h"


namespace nauEngineSDK {
   /**
    * CoreFactory
    * Description:
    *   Its used to create Objects for Graphics Plugin
    * Sample usage:
    *   Create Sampler creates a PLUGIN-specific sampler
    */
  class CoreFactory : public Module <CoreFactory>
  {
  public:
    /**
     * Default Constructor
     */
    CoreFactory() = default;
  
    /**
     * Default destructor
     */
    virtual
    ~CoreFactory() = default;

    /**
     * @brief Creates a Graphics API specific to a Graphics library
     * @param 
     * @return a Pointer to a Graphics API*
     *
     */
    virtual GraphicsAPI*
    createGraphicsAPI() = 0;

    /**
     * @brief Creates a Device specific to a Graphics library
     * @param 
     * @return a pointer to specific Device
     *
     */
    virtual Device*
    createDevice() = 0;

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
  };
  

  extern NAU_CORE_EXPORT CoreFactory*
  g_CoreFactory;
}

