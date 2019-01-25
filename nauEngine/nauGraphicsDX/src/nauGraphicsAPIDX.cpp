/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsAPIDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X graphics API implementation of the base core API
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauGraphicsAPIDX.h"

namespace nauEngineSDK {

  bool
  nauGraphicsAPIDX::initDevice(void* scrHandler) {

    m_fov = 0.0f;
    
    if (!m_device.initializeDevice(scrHandler)) {
      std::cout << "Failed to initialize device... \n";
      return false;
    }
    //CreateRenderTargetView
    if (!m_texture.createRenderTargetView(m_device.m_pd3dDevice, 
                                          m_device.m_pSwapChain)) {
      std::cout << "Failed to create Render Target View... \n";
      return false;
    }
    //CreateDepthStencilTexture descriptor
    if (!m_texture.createDepthstencil(m_device.m_pd3dDevice,
                                      m_device.m_pImmediateContext,
                                      m_device.m_width,
                                      m_device.m_height)) {
      std::cout << "Failed to create Depth Stencil... \n";
      return false;
    }
    
    if (!m_viewPort.createViewPort(m_device.m_width,
                                   m_device.m_height,
                                   1.0f,
                                   1.0f)) {

    }
    m_viewPort.setViewPort(m_device.m_pImmediateContext);
    

    m_vertexShader.createFromFile(m_device.m_pd3dDevice, "resources/VS.hlsl", "ColorVertexShader");
    m_pixelShader.createFromFile(m_device.m_pd3dDevice, "resources/PS.hlsl", "ColorPixelShader");
    
    m_inputLayout.setInputDescriptor();

    
    m_inputLayout.createInputBuffer(m_device.m_pd3dDevice, &m_vertexShader);

    
    m_world = DirectX::XMMatrixIdentity();

    DirectX::XMVECTOR position;
    position = DirectX::XMVectorSet(0.0f, 0.0f, -10.0f, 1.0f);

    DirectX::XMVECTOR objective;
    objective = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

    DirectX::XMVECTOR up;
    up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 1.0f);

    m_view = DirectX::XMMatrixLookAtLH(position, objective, up);

    m_projection = DirectX::XMMatrixPerspectiveFovLH((75.0f*3.141592f / 180.0f), 
                                                     static_cast<float>(m_device.m_width / 
                                                                        m_device.m_height), 
                                                     m_screenNear, 
                                                     m_screenDepth);
    

    m_meshList.setDevice(m_device.m_pd3dDevice);
    test();
    
    return true;
  }

  void
  nauGraphicsAPIDX::onRender() {
    setShaders(m_device.m_pImmediateContext,
               m_vertexShader.m_pVertexShader,
               SHADERFLAGS::VERTEX);

    setShaders(m_device.m_pImmediateContext,
               m_pixelShader.m_pPixelShader,
               SHADERFLAGS::PIXEL);

    m_inputLayout.setLayout(m_device.m_pImmediateContext);

    float color[4] = { 1.0f,0.0f,1.0f,1.0f };
    m_device.m_pImmediateContext->ClearRenderTargetView(m_texture.m_pRenderTargetView, 
                                                        color);
    m_device.m_pImmediateContext->ClearDepthStencilView(m_texture.m_DepthStencilView, 
                                                        D3D11_CLEAR_DEPTH, 
                                                        1.0f, 
                                                        0);
    m_meshList.render();
    m_device.m_pSwapChain->Present(DXGI_SWAP_EFFECT_DISCARD, DXGI_PRESENT_DO_NOT_WAIT);

  }

  void
  nauGraphicsAPIDX::setShaders(void* pDeviceContext, void* pShader, SHADERFLAGS flags) {
    if      (SHADERFLAGS::VERTEX == flags) {
      reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->VSSetShader(
                                                reinterpret_cast<ID3D11VertexShader*>(pShader),
                                                0,
                                                0);
    }

    else if (SHADERFLAGS::PIXEL == flags) {
      reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->PSSetShader(
        reinterpret_cast<ID3D11PixelShader*>(pShader),
        0,
        0);
    }
  }

  void
  nauGraphicsAPIDX::test() {
    
    nauMeshDX* m = new nauMeshDX();
    m->m_vertexBuffer = new nauVertexBufferDX();
    m->m_indexBuffer = new nauIndexBufferDX();
    m->m_texture = new nauTextureDX();
    m_meshList.m_meshes.push_back(m);
    auto& mesh = m_meshList.m_meshes.back();

    ID3D11DeviceContext* pImmContext;

    m_meshList.m_pDevice->GetImmediateContext(&pImmContext);
    mesh->m_texture->loadFromFile("resources/sheikah.jpg", 
                                  m_meshList.m_pDevice, 
                                  pImmContext);

    mesh->m_texture->createShaderSampler(m_meshList.m_pDevice);
    mesh->m_texture->setShaderSampler(m_meshList.m_pDevice);

    nauVertex pVertex;

    pVertex.m_position = { -1.0f,-1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,0.5f,0.25f,1.0f };
    pVertex.m_normal = { 0.0f, 0.0f, 0.0f, 1.0f };
    pVertex.m_u = 0.0f;
    pVertex.m_v = 1.0f;

    mesh->m_vertexBuffer->add(pVertex);

    pVertex.m_position = { 0.0f,1.0f,0.0f,1.0f };
    pVertex.m_color = { 0.5f,1.0f, 0.0f,1.0f };
    pVertex.m_normal = { 0.0f, 0.0f, 0.0f, 1.0f };
    pVertex.m_u = 0.5f;
    pVertex.m_v = 0.0f;

    mesh->m_vertexBuffer->add(pVertex);

    pVertex.m_position = { 1.0f,-1.0f,0.0f,1.0f };
    pVertex.m_color = { 0.25f, 0.5f, 1.0f,1.0f };
    pVertex.m_normal = { 0.0f, 0.0f, 0.0f, 1.0f };
    pVertex.m_u = 1.0f;
    pVertex.m_v = 1.0f;

    mesh->m_vertexBuffer->add(pVertex);

    mesh->m_indexBuffer->add(0);
    mesh->m_indexBuffer->add(1);
    mesh->m_indexBuffer->add(2);

    mesh->m_vertexBuffer->createHardware(m_meshList.m_pDevice,
                                         D3D11_USAGE_DEFAULT);
    mesh->m_indexBuffer->createHardware(m_meshList.m_pDevice,
                                        D3D11_USAGE_DEFAULT);

  }
 
}