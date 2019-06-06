/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicPass.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/04 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauGraphicPass.h"
namespace nauEngineSDK {

  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  void
  GraphicPass::setPixelShader(Device* pDevice) {
    pDevice->setShader(m_pixelShader->getShader(), SHADERFLAGS::PIXEL);
  }

  void
  GraphicPass::setVertexShader(Device* pDevice) {
    pDevice->setShader(m_vertexShader->getShader(), SHADERFLAGS::VERTEX);
  }

  void
  GraphicPass::setComputeShader(Device* pDevice) {
    pDevice->setShader(m_computeShader->getShader(), SHADERFLAGS::COMPUTE);
  }

  bool
  GraphicPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    m_pixelShader->createFromFile(pDevice->get(), fileName.c_str(), entry.c_str());
    return true;
  }

  bool
  GraphicPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    m_vertexShader->createFromFile(pDevice->get(), fileName.c_str(), entry.c_str());
    return true;
  }

  bool
  GraphicPass::loadComputeShader(Device* pDevice, String fileName, String entry) {
    m_computeShader->createFromFile(pDevice->get(), fileName.c_str(), entry.c_str());
    return true;
  }

  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  bool
  GBPass::init(Device* pDevice, Map<String, Texture*> textures) {

    m_pixelShader   = pDevice->createPixelShader();
    m_vertexShader  = pDevice->createVertexShader();
    m_buffer        = pDevice->createConstantBuffer();
    m_renderTarget  = pDevice->createRenderTargetView();
    m_sampler       = pDevice->createSamplerState();
    m_inputLayout   = pDevice->createInputLayout();
    m_depthStencil  = pDevice->createDepthStencil();
    m_rasterizer    = pDevice->createRasterizer();
    m_info.m_color  = pDevice->createRenderTargetView();
    m_info.m_emissive = pDevice->createRenderTargetView();
    m_info.m_normal = pDevice->createRenderTargetView();
    m_info.m_depth = pDevice->createRenderTargetView();

    if (!m_info.m_color->createRenderTargetView(pDevice, pDevice->getBackBuffer())) return false;
    if (!m_info.m_emissive->createRenderTargetView(pDevice, textures["EMISSIVE"])) return false;
    if (!m_info.m_normal->createRenderTargetView(pDevice, textures["NORMAL"])) return false;
    if (!m_info.m_emissive->createRenderTargetView(pDevice, textures["DEPTH"])) return false;
    if (!m_depthStencil->createDepthStencil(*pDevice, 
                                            pDevice->m_height, 
                                            pDevice->m_width)) return false;



    m_depthStencil->createState(pDevice);
    m_depthStencil->setState(pDevice);
    
    if (!m_depthStencil->createView(pDevice)) return false;

    m_info.m_color->set(*pDevice, *m_depthStencil);

    if (!m_pixelShader->init()) { 
      std::cout << "Couldn't initiate the Pixel shader of the geometric pass" << std::endl;
      exit(442);
    }
    if (!m_vertexShader->init()) {
      std::cout << "Couldn't initiate the Vertex shader of the geometric pass" << std::endl;
      exit(445);
    }

    if (!loadVertexShader(pDevice, "resources/VS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/PS.hlsl", "ps_main")) return false;

    m_rasterizer->createRasterizerState(pDevice);
    m_inputLayout->setInputDescriptor();
    m_inputLayout->createInputBuffer(pDevice, m_vertexShader);
    m_sampler->createSampler(pDevice);

    Matrix4 m = { 0 };
    float f = 0;
    m_buffer->clear();

    //Mat world view projection
    m_buffer->add(reinterpret_cast<char*>(&m), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m), sizeof(Matrix4));

    m_buffer->createHardware(pDevice->get(), 0);
    return true;
  }

 
  void
  GBPass::setLayout(Device* pDevice) {

  }

  void
  GBPass::setShaderSampler(Device* pDevice) {

  }

  void
  GBPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {
    
    setPixelShader(pDevice);
    setVertexShader(pDevice);

    m_buffer->updateSubResource(pDevice->getContext(), 0, 0, 0);
    
    m_buffer->setVertexShader(pDevice->getContext());
    
    m_inputLayout->setLayout(pDevice->getContext());

    m_info.m_color->clearView(pDevice, Vector4(0.5f, 0.5f, 0.5f, 1.0f));
    m_depthStencil->clearView(pDevice);

    for (auto model : m_orderedList) {
      model->m_model->drawMesh();
    }
  }

  void
  GBPass::updatePass() {
    m_buffer->clear();
    m_buffer->add(reinterpret_cast<char*>(&m_info.WorldMat), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m_info.ViewMat), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m_info.Projection), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m_info.fNear), sizeof(float));
    m_buffer->add(reinterpret_cast<char*>(&m_info.fFar), sizeof(float));

  }
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicPass.cpp 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  bool
  SSAOPass::init(Device* pDevice, Map<String, Texture*> textures) {

    m_pixelShader = pDevice->createPixelShader();
    m_vertexShader = pDevice->createVertexShader();
    m_buffer = pDevice->createConstantBuffer();
    m_renderTarget = pDevice->createRenderTargetView();
    m_sampler = pDevice->createSamplerState();
    m_inputLayout = pDevice->createInputLayout();
    m_depthStencil = pDevice->createDepthStencil();
    m_rasterizer = pDevice->createRasterizer();

    if (!loadVertexShader(pDevice, "resources/QuadVS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/SSAOPass.hlsl", "ps_main")) return false;

    return true;
  }

  void
  SSAOPass::setLayout(Device* pDevice) {

  }

  void
  SSAOPass::setShaderSampler(Device* pDevice) {

  }

  void
  SSAOPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {
    setPixelShader(pDevice);
    setVertexShader(pDevice);

    m_buffer->setPixelShader(pDevice->getContext());


    //for (auto model : m_orderedList) {
    //  model->m_model->drawMesh();
    //}
  }

  void
  SSAOPass::updatePass() {


  }

  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  bool
  ReductionPass::init(Device* pDevice, Map<String, Texture*> textures) {
    m_pixelShader = pDevice->createPixelShader();
    m_vertexShader = pDevice->createVertexShader();
    m_buffer = pDevice->createConstantBuffer();
    m_renderTarget = pDevice->createRenderTargetView();
    m_sampler = pDevice->createSamplerState();
    m_inputLayout = pDevice->createInputLayout();
    m_depthStencil = pDevice->createDepthStencil();
    m_rasterizer = pDevice->createRasterizer();

    if (!loadVertexShader(pDevice, "resources/QuadVS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/ReductionPass.hlsl", "ps_main")) return false;

    return true;
  }

  void
  ReductionPass::setLayout(Device* pDevice) {

  }

  void
  ReductionPass::setShaderSampler(Device* pDevice) {

  }

  void
  ReductionPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
  ReductionPass::updatePass() {


  }
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  bool
  BlurPass::init(Device* pDevice, Map<String, Texture*> textures) {
    m_pixelShader = pDevice->createPixelShader();
    m_vertexShader = pDevice->createVertexShader();
    m_buffer = pDevice->createConstantBuffer();
    m_renderTarget = pDevice->createRenderTargetView();
    m_sampler = pDevice->createSamplerState();
    m_inputLayout = pDevice->createInputLayout();
    m_depthStencil = pDevice->createDepthStencil();
    m_rasterizer = pDevice->createRasterizer();

    if (!loadVertexShader(pDevice, "resources/QuadVS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/Blur.hlsl", "ps_main")) return false;

    return true;
  }

  void
  BlurPass::setLayout(Device* pDevice) {

  }

  void
  BlurPass::setShaderSampler(Device* pDevice) {

  }

  void
  BlurPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
  BlurPass::updatePass() {


  }
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  bool
  LightningPass::init(Device* pDevice, Map<String, Texture*> textures) {
    m_pixelShader = pDevice->createPixelShader();
    m_vertexShader = pDevice->createVertexShader();
    m_buffer = pDevice->createConstantBuffer();
    m_renderTarget = pDevice->createRenderTargetView();
    m_sampler = pDevice->createSamplerState();
    m_inputLayout = pDevice->createInputLayout();
    m_depthStencil = pDevice->createDepthStencil();
    m_rasterizer = pDevice->createRasterizer();

    if (!loadVertexShader(pDevice, "resources/QuadVS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/LightningPass.hlsl", "ps_main")) return false;

    return true;
  }

  void
  LightningPass::setLayout(Device* pDevice) {

  }

  void
  LightningPass::setShaderSampler(Device* pDevice) {

  }

  void
  LightningPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {

    setVertexShader(pDevice);
    setPixelShader(pDevice);
  }

  void
  LightningPass::updatePass() {


  }
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  bool
  LuminancePass::init(Device* pDevice, Map<String, Texture*> textures) {
    m_pixelShader = pDevice->createPixelShader();
    m_vertexShader = pDevice->createVertexShader();
    m_buffer = pDevice->createConstantBuffer();
    m_renderTarget = pDevice->createRenderTargetView();
    m_sampler = pDevice->createSamplerState();
    m_inputLayout = pDevice->createInputLayout();
    m_depthStencil = pDevice->createDepthStencil();
    m_rasterizer = pDevice->createRasterizer();

    if (!loadVertexShader(pDevice, "resources/QuadVS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/LuminancePass.hlsl", "ps_main")) return false;

    return true;
  }

  void
  LuminancePass::setLayout(Device* pDevice) {

  }

  void
  LuminancePass::setShaderSampler(Device* pDevice) {

  }

  void
  LuminancePass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
  LuminancePass::updatePass() {


  }
  
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  
  bool
  FinalPass::init(Device* pDevice, Map<String, Texture*> textures) {
    m_pixelShader = pDevice->createPixelShader();
    m_vertexShader = pDevice->createVertexShader();
    m_buffer = pDevice->createConstantBuffer();
    m_renderTarget = pDevice->createRenderTargetView();
    m_sampler = pDevice->createSamplerState();
    m_inputLayout = pDevice->createInputLayout();
    m_depthStencil = pDevice->createDepthStencil();
    m_rasterizer = pDevice->createRasterizer();

    if (!loadVertexShader(pDevice, "resources/QuadVS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/FinalPass.hlsl", "ps_main")) return false;

    return true;
  }

  void
  FinalPass::setLayout(Device* pDevice) {

  }

  void
  FinalPass::setShaderSampler(Device* pDevice) {

  }

  void
  FinalPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
  FinalPass::updatePass() {


  }

  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  bool
  ComputePass::init(Device* pDevice, Map<String, Texture*> textures) {
    return true;
  }

  void
  ComputePass::setLayout(Device* pDevice) {

  }

  void
  ComputePass::setShaderSampler(Device* pDevice) {

  }

  void
  ComputePass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
  ComputePass::updatePass() {


  }

}