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
     * Render Target View
     */
    Texture* m_renderTargetOutput;

    /**
     * Pixel Shader object
     */
    PixelShader* m_pixelShader;

    /**
     * InputLayout
     */
    InputLayout* m_inputLayout;

    /**
     * Sampler State
     */
    SamplerState* m_sampler;

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

    //bool
    //  init(Device* pDevice) override;
    //
    //void
    //  setPixelShader(Device* pDevice) override;
    //
    //void
    //  setVertexShader(Device* pDevice) override;
    //
    //void
    //  setLayout(Device* pDevice) override;
    //
    //void
    //  setShaderSampler(Device* pDevice) override;
    //
    //bool
    //  loadPixelShader(Device* pDevice, String fileName, String entry) override;
    //
    //bool
    //  loadVertexShader(Device* pDevice, String fileName, String entry) override;
    //
    //void
    //  render() override;


    //void
    //init(Device* pDevice) override;
  };

}

