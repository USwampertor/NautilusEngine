/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauGraphicPass.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/04 2019
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauGraphicPass.h"
namespace nauEngineSDK {

  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

  bool
  GBPass::init(Device* pDevice) {

    m_pixelShader   = pDevice->createPixelShader();
    m_vertexShader  = pDevice->createVertexShader();
    m_buffer        = pDevice->createConstantBuffer();
    m_renderTarget  = pDevice->createRenderTargetView();
    m_sampler       = pDevice->createSamplerState();
    m_inputLayout   = pDevice->createInputLayout();
    m_depthStencil  = pDevice->createDepthStencil();
    m_rasterizer    = pDevice->createRasterizer();

    if (!m_renderTarget->createRenderTargetView(pDevice, pDevice->getBackBuffer())) return false;
    if (!m_depthStencil->createDepthStencil(*pDevice, 
                                            pDevice->m_width, 
                                            pDevice->m_height)) return false;
    if (!m_depthStencil->createView(pDevice))return false;
    m_renderTarget->set(*pDevice, *m_depthStencil);

    if (!loadVertexShader(pDevice, "resources/VS.hlsl", "vs_main")) return false;
    if (!loadPixelShader(pDevice, "resources/PS.hlsl", "ps_main")) return false;

    m_buffer->setVertexShader(pDevice->getContext());
    m_buffer->setPixelShader(pDevice->getContext());

    m_rasterizer->createRasterizerState(pDevice);
    m_inputLayout->setInputDescriptor();
    m_inputLayout->createInputBuffer(pDevice, m_vertexShader);
    m_sampler->createSampler(pDevice);

    Matrix4 m = { 0 };
    m_buffer->clear();
    m_buffer->add(reinterpret_cast<char*>(&m), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m), sizeof(Matrix4));
    m_buffer->add(reinterpret_cast<char*>(&m), sizeof(Matrix4));

    m_buffer->createHardware(pDevice->get(), 0);
    return true;
  }

  void
  GBPass::setPixelShader(Device* pDevice) {
    pDevice->setShader(m_pixelShader->getShader(), SHADERFLAGS::PIXEL);
  }

  void
  GBPass::setVertexShader(Device* pDevice) {
    pDevice->setShader(m_vertexShader->getShader(), SHADERFLAGS::VERTEX);
  }

  void
  GBPass::setLayout(Device* pDevice) {

  }

  void
  GBPass::setShaderSampler(Device* pDevice) {

  }

  bool
  GBPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    m_pixelShader->createFromFile(pDevice->get(), fileName.c_str(), entry.c_str());
    return true;
  }

  bool
  GBPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    m_vertexShader->createFromFile(pDevice->get(), fileName.c_str(), entry.c_str());
    return true;
  }

  void
  GBPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {
    
    setPixelShader(pDevice);
    setVertexShader(pDevice);

    m_buffer->updateSubResource(pDevice->getContext(), 0, 0, 0);
    
    m_buffer->setVertexShader(pDevice->getContext());
    m_buffer->setPixelShader(pDevice->getContext());
    
    m_inputLayout->setLayout(pDevice->getContext());

    m_renderTarget->clearView(pDevice, Vector4(0.5f, 0.5f, 0.5f, 1.0f));
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

  }
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauGraphicPass.cpp 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
    SSAOPass::init(Device* pDevice) {
    return true;
  }

  void
    SSAOPass::setPixelShader(Device* pDevice) {

  }

  void
    SSAOPass::setVertexShader(Device* pDevice) {

  }

  void
    SSAOPass::setLayout(Device* pDevice) {

  }

  void
    SSAOPass::setShaderSampler(Device* pDevice) {

  }

  bool
    SSAOPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
    SSAOPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
    SSAOPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
    SSAOPass::updatePass() {


  }

  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
    ReductionPass::init(Device* pDevice) {
    return true;
  }

  void
    ReductionPass::setPixelShader(Device* pDevice) {

  }

  void
    ReductionPass::setVertexShader(Device* pDevice) {

  }

  void
    ReductionPass::setLayout(Device* pDevice) {

  }

  void
    ReductionPass::setShaderSampler(Device* pDevice) {

  }

  bool
    ReductionPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
    ReductionPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
    ReductionPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
    ReductionPass::updatePass() {


  }
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
    BlurPass::init(Device* pDevice) {
    return true;
  }

  void
    BlurPass::setPixelShader(Device* pDevice) {

  }

  void
    BlurPass::setVertexShader(Device* pDevice) {

  }

  void
    BlurPass::setLayout(Device* pDevice) {

  }

  void
    BlurPass::setShaderSampler(Device* pDevice) {

  }

  bool
    BlurPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
    BlurPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
    BlurPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
    BlurPass::updatePass() {


  }
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
    LightningPass::init(Device* pDevice) {
    return true;
  }

  void
    LightningPass::setPixelShader(Device* pDevice) {

  }

  void
    LightningPass::setVertexShader(Device* pDevice) {

  }

  void
    LightningPass::setLayout(Device* pDevice) {

  }

  void
    LightningPass::setShaderSampler(Device* pDevice) {

  }

  bool
    LightningPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
    LightningPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
    LightningPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
    LightningPass::updatePass() {


  }
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
    LuminancePass::init(Device* pDevice) {
    return true;
  }

  void
    LuminancePass::setPixelShader(Device* pDevice) {

  }

  void
    LuminancePass::setVertexShader(Device* pDevice) {

  }

  void
    LuminancePass::setLayout(Device* pDevice) {

  }

  void
    LuminancePass::setShaderSampler(Device* pDevice) {

  }

  bool
    LuminancePass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
    LuminancePass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
    LuminancePass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
    LuminancePass::updatePass() {


  }
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * nauGraphicPass.cpp 
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
    FinalPass::init(Device* pDevice) {
    return true;
  }

  void
    FinalPass::setPixelShader(Device* pDevice) {

  }

  void
    FinalPass::setVertexShader(Device* pDevice) {

  }

  void
    FinalPass::setLayout(Device* pDevice) {

  }

  void
    FinalPass::setShaderSampler(Device* pDevice) {

  }

  bool
    FinalPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
    FinalPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
    FinalPass::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {


  }

  void
    FinalPass::updatePass() {


  }
}