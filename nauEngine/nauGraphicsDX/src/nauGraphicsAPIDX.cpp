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
using namespace DirectX;

namespace nauEngineSDK {

  bool
    GraphicsAPIDX::initDevice(void* scrHandler) {

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

    if (!m_viewPort.createViewPort(static_cast<float>(m_device.m_width),
      static_cast<float>(m_device.m_height),
      1.0f,
      1.0f)) {
      std::cout << "Could not create ViewPort \n";
      exit(828);
    }
    m_viewPort.setViewPort(m_device.m_pImmediateContext);


    m_vertexShader.createFromFile(m_device.m_pd3dDevice, "resources/VS.hlsl", "ColorVertexShader");
    m_pixelShader.createFromFile(m_device.m_pd3dDevice, "resources/PS.hlsl", "ColorPixelShader");

    m_inputLayout.setInputDescriptor();


    m_inputLayout.createInputBuffer(m_device.m_pd3dDevice, &m_vertexShader);

    m_samplerState.createShaderSampler(m_device.m_pd3dDevice);



    ///////////// This is for testing the renderer
    m_fov = Math::degToRad(75.0f);
    m_world = Matrix4::IDENTITY;

    m_camera.m_objective.setValues(0.0f, 0.0f, 0.0f);
    m_camera.m_position.setValues(0.0f, 0.0f, -10.0f);
    m_camera.m_up = Vector3::UP;

    m_camera.createView();

    XMMATRIX directWorld;
    XMMATRIX directView;
    XMMATRIX directProjection;
    XMVECTOR deye = XMVectorSet(0.0f, 0.0f, -10.0f, 1.0f);
    XMVECTOR dobjective = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
    XMVECTOR dup = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);


    directView = XMMatrixLookAtLH(deye, dobjective, dup);
    directView = XMMatrixTranspose(directView);
    directWorld = XMMatrixIdentity();// XMMatrixSet(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    directProjection = XMMatrixPerspectiveFovLH(m_fov,
      static_cast<float>(m_device.m_width / m_device.m_height),
      m_screenNear,
      m_screenDepth);
    directProjection = XMMatrixTranspose(directProjection);


    m_projection.perspective(m_fov,
                             static_cast<float>(m_device.m_width / m_device.m_height),
                             m_screenNear,
                             m_screenDepth);


    m_meshList.setDevice(m_device.m_pd3dDevice);
    m_meshList.loadFromFile("resources/max.obj");
    //test();


    //TODO: PUT THIS IN THE CONSTANT BUFFER
    D3D11_BUFFER_DESC bd;
    memset(&bd, 0, sizeof(bd));
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(DirectBuffer);
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    bd.CPUAccessFlags = 0;

    ID3D11Buffer* buffer = nullptr;
    DirectBuffer* b = new DirectBuffer();

    CBuffer* nauB = new CBuffer();

    HRESULT hr = m_device.m_pd3dDevice->CreateBuffer(&bd, nullptr, &buffer);
    if (FAILED(hr)) { return false; }

    m_cbuffer.m_world       = m_world;
    m_cbuffer.m_view        = m_camera.m_view;
    m_cbuffer.m_projection  = m_projection;

    b->m_world = directWorld;
    b->m_view = directView;
    b->m_projection = directProjection;

    m_device.m_pImmediateContext->UpdateSubresource(buffer, 
                                                    0, 
                                                    nullptr, 
                                                    reinterpret_cast<char*>(&b), 
                                                    0, 
                                                    0);

    m_device.m_pImmediateContext->VSSetConstantBuffers(0, 1, &buffer);
    m_device.m_pImmediateContext->PSSetConstantBuffers(0, 1, &buffer);
    //end test
    return true;
  }

  void
  GraphicsAPIDX::onRender() {
    
    setShaders(m_device.m_pImmediateContext,
               m_vertexShader.m_pVertexShader,
               SHADERFLAGS::VERTEX);

    setShaders(m_device.m_pImmediateContext,
               m_pixelShader.m_pPixelShader,
               SHADERFLAGS::PIXEL);

    m_inputLayout.setLayout(m_device.m_pImmediateContext);

    float color[4] = { 0.5f,0.5f,0.5f,1.0f };
    m_device.m_pImmediateContext->ClearRenderTargetView(m_texture.m_pRenderTargetView, 
                                                        color);
    m_device.m_pImmediateContext->ClearDepthStencilView(m_texture.m_DepthStencilView, 
                                                        D3D11_CLEAR_DEPTH, 
                                                        1.0f, 
                                                        0);
    m_samplerState.setShaderSampler(m_device.m_pd3dDevice);
    m_meshList.render();
    
    m_device.m_pSwapChain->Present(DXGI_SWAP_EFFECT_DISCARD, DXGI_PRESENT_DO_NOT_WAIT);
  }

  void
  GraphicsAPIDX::setShaders(void* pDeviceContext, void* pShader, SHADERFLAGS flags) {

    auto devContext = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);

    if      (SHADERFLAGS::VERTEX == flags) {
      auto vertexShader = reinterpret_cast<ID3D11VertexShader*>(pShader);
      devContext->VSSetShader(vertexShader, 0, 0);
    }

    else if (SHADERFLAGS::PIXEL == flags) {
      auto pixelShader = reinterpret_cast<ID3D11PixelShader*>(pShader);
      devContext->PSSetShader( pixelShader, 0, 0);
    }
  }

  void
  GraphicsAPIDX::test() {
    
    MeshDX* m = new MeshDX();
    m->m_vertexBuffer = new VertexBufferDX();
    m->m_indexBuffer = new IndexBufferDX();
    m->m_texture = new TextureDX();
    m_meshList.m_meshes.push_back(m);
    auto& mesh = m_meshList.m_meshes.back();

    ID3D11DeviceContext* pImmContext;

    m_meshList.m_pDevice->GetImmediateContext(&pImmContext);
    mesh->m_texture->loadFromFile("resources/sheikah.jpg", 
                                  m_meshList.m_pDevice, 
                                  pImmContext);

    mesh->m_texture->createShaderSampler(m_meshList.m_pDevice);
    mesh->m_texture->setShaderSampler(m_meshList.m_pDevice);

    Vertex pVertex;

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