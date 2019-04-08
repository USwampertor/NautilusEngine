/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicPass.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/04 2019
 * @brief Graphics managment for passes. It stores a series of objects to be called
 *        up on passes
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauDepthStencil.h"
#include "nauDevice.h"
#include "nauGraphicsBuffer.h"
#include "nauInputLayout.h"
#include "nauTexture.h"
#include "nauRenderTargetView.h"

namespace nauEngineSDK {
  
  /**
   * GraphicsPass
   * Description:
   *   Sets what is going to happen in a pass 
   * Sample usage:
   * 
   */
  class NAU_CORE_EXPORT GraphicPass
  {
  public:
    /**
     * Default constructor
     */
    GraphicPass() = default;
  
    /**
     * Default destructor
     */
    ~GraphicPass() = default;

    bool
    init(Device* pDevice);

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setLayout(Device* pDevice);

    void
    setShaderSampler(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    void
    render();



    /**
     * DepthStencil object reference
     */
    DepthStencil* m_depthStencil;

    /**
     * Pixel Shader object
     */
    PixelShader* m_pixelShader;

    /**
     * Vertex Shader
     */
    VertexShader* m_vertexShader;

    /**
     * InputLayout
     */
    InputLayout* m_inputLayout;

    /**
     * Sampler State
     */
    SamplerState* m_sampler;

    /**
     * Constant Buffer
     */
    ConstantBuffer* m_buffer;

    /**
     * TextureObjects
     */
    Map<String, RenderTargetView*> m_renderTargets;

  };


   /**
    * GBPass
    * Description:
    *   Render pass specific for graphic buffer implementation
    * Sample usage:
    *   gets all the objects and renders them
    */
  class NAU_CORE_EXPORT GBPass : public GraphicPass
  {

    GBPass() = default;

    ~GBPass() = default;

    bool
    init(Device* pDevice);
    
    void
    setPixelShader(Device* pDevice);
    
    void
    setVertexShader(Device* pDevice);
    
    void
    setLayout(Device* pDevice);
    
    void
    setShaderSampler(Device* pDevice);
    
    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);
    
    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);
    
    void
    render();
  };

  class NAU_CORE_EXPORT SSAOPass : public GraphicPass
  {

    SSAOPass() = default;

    ~SSAOPass() = default;

    bool
    init(Device* pDevice);

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setLayout(Device* pDevice);

    void
    setShaderSampler(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    void
    render();
  };

  class NAU_CORE_EXPORT ReductionPass : public GraphicPass
  {

    ReductionPass() = default;

    ~ReductionPass() = default;

    bool
    init(Device* pDevice);

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setLayout(Device* pDevice);

    void
    setShaderSampler(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    void
    render();
  };

  class NAU_CORE_EXPORT BlurPass : public GraphicPass
  {

    BlurPass() = default;

    ~BlurPass() = default;

    bool
    init(Device* pDevice);

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setLayout(Device* pDevice);

    void
    setShaderSampler(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    void
    render();
  };

  class NAU_CORE_EXPORT LIghtning : public GraphicPass
  {

    LIghtning() = default;

    ~LIghtning() = default;

    bool
    init(Device* pDevice);

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setLayout(Device* pDevice);

    void
    setShaderSampler(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    void
    render();
  };

  class NAU_CORE_EXPORT LIghtning : public GraphicPass
  {

    LIghtning() = default;

    ~LIghtning() = default;

    bool
    init(Device* pDevice);

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setLayout(Device* pDevice);

    void
    setShaderSampler(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    void
    render();
  };


}

