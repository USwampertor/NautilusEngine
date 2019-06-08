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

#include "nauComponent.h"
#include "nauDepthStencil.h"
#include "nauDevice.h"
#include "nauGraphicsBuffer.h"
#include "nauInputLayout.h"
#include "nauPassPerInfo.h"
#include "nauRenderTargetView.h"
#include "nauRasterizerState.h"
#include "nauSamplerState.h"
#include "nauTexture.h"

namespace nauEngineSDK {
  
  class GraphicPass
  {
  public:
    /**
     * Default constructor
     */
    GraphicPass() = default;
  
    /**
     * Default destructor
     */
    virtual 
    ~GraphicPass() {}

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) = 0;

    void
    setPixelShader(Device* pDevice);

    void
    setVertexShader(Device* pDevice);

    void
    setComputeShader(Device* pDevice);

    bool
    loadPixelShader(Device* pDevice, String fileName, String entry);

    bool
    loadVertexShader(Device* pDevice, String fileName, String entry);

    bool
    loadComputeShader(Device* pDevice, String fileName, String entry);

    virtual void
    setLayout(Device* pDevice) = 0;

    virtual void
    setShaderSampler(Device* pDevice) = 0;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) = 0;

    virtual void
    updatePass() = 0;

    /**
     * Render Target View
     */
    RenderTargetView* m_renderTarget = nullptr;

    /**
     * DepthStencil object reference
     */
    DepthStencil* m_depthStencil = nullptr;

    /**
     * Pixel Shader object
     */
    Shader* m_pixelShader = nullptr;

    /**
     * Vertex Shader
     */
    Shader* m_vertexShader = nullptr;

    /**
     * Compute Shader
     */
    Shader* m_computeShader = nullptr;

    /**
     * InputLayout
     */
    InputLayout* m_inputLayout = nullptr;

    /**
     * Sampler State
     */
    SamplerState* m_sampler = nullptr;

    /**
     * Constant Buffer
     */
    ConstantBuffer* m_buffer = nullptr;

    /**
     * Rasterizer State
     */
    RasterizerState* m_rasterizer = nullptr;

    /**
     * The textures passed to the graphic pass to manage and update
     */
    Map<String, Texture*> m_parentTexture;
  };

  class GBPass : public GraphicPass
  {
  public:
    GBPass() = default;

    ~GBPass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*>) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

    GBPassInfo m_info;

  };

  class NAU_CORE_EXPORT SSAOPass : public GraphicPass
  {
  public:
    SSAOPass() = default;

    ~SSAOPass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

  };

  class NAU_CORE_EXPORT ReductionPass : public GraphicPass
  {
  public:
    ReductionPass() = default;

    ~ReductionPass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

  };

  class NAU_CORE_EXPORT BlurPass : public GraphicPass
  {
  public:
    BlurPass() = default;

    ~BlurPass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

  };

  class NAU_CORE_EXPORT LightningPass : public GraphicPass
  {
  public:
    LightningPass() = default;

    ~LightningPass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;
    
    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

    LGPassInfo m_lightInfo;
  };

  class NAU_CORE_EXPORT LuminancePass : public GraphicPass
  {
  public:
    LuminancePass() = default;

    ~LuminancePass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

  };

  class NAU_CORE_EXPORT FinalPass : public GraphicPass
  {
   public:
    FinalPass() = default;

    ~FinalPass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

    Texture* m_colorTexture;

    FNPassInfo m_info;

  };

  class NAU_CORE_EXPORT ComputePass : public GraphicPass
  {
  public:
    ComputePass() = default;

    ~ComputePass() = default;

    virtual bool
    init(Device* pDevice, Map<String, Texture*> textures) override;

    virtual void
    setLayout(Device* pDevice) override;

    virtual void
    setShaderSampler(Device* pDevice) override;

    virtual void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice) override;

    virtual void
    updatePass() override;

    Texture* m_colorTexture;

  };

}

