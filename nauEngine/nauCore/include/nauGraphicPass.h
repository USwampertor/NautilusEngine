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
    ~GraphicPass() = default;

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

  };

  class GBPass : public GraphicPass
  {
  public:
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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

    GBPassInfo m_info;
  };

  class NAU_CORE_EXPORT SSAOPass : public GraphicPass
  {
  public:
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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

  };

  class NAU_CORE_EXPORT ReductionPass : public GraphicPass
  {
  public:
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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

  };

  class NAU_CORE_EXPORT BlurPass : public GraphicPass
  {
  public:
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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

  };

  class NAU_CORE_EXPORT LightningPass : public GraphicPass
  {
  public:
    LightningPass() = default;

    ~LightningPass() = default;

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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

  };

  class NAU_CORE_EXPORT LuminancePass : public GraphicPass
  {
  public:
    LuminancePass() = default;

    ~LuminancePass() = default;

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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

  };

  class NAU_CORE_EXPORT FinalPass : public GraphicPass
  {
   public:
    FinalPass() = default;

    ~FinalPass() = default;

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
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    updatePass();

  };


}

