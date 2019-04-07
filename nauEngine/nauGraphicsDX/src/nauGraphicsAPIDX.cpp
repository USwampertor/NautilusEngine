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
  GraphicsAPIDX::init(void* scrHandler) {

    if (!initDevice(scrHandler)) {
      std::cout << "Failed to initialize device... \n";
      return false;
    }

    return true;
  }

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
    m_fov = Math::degToRad(90.0f);
    m_world = Matrix4::IDENTITY;

    m_camera.m_objective.setValues(0.0f, 0.0f, 0.0f);
    m_camera.m_position.setValues(0.0f, 0.0f, -10.0f);
    m_camera.m_up = Vector3::UP;

    m_camera.createView();

    m_projection.perspective(m_fov,
                             static_cast<float>(m_device.m_width / m_device.m_height),
                             m_screenNear,
                             m_screenDepth);

    //m_meshList.setDevice(&m_device);


    MeshComponent* com = new MeshComponent();
    com->m_model = new Model();
    com->m_model->setDevice(&m_device);
    com->m_model->loadFromFile("resources/Vela_Mat_1.X");
    com->m_model->loadFromFile("resources/Vela_Mat_2.X");
    com->m_model->loadFromFile("resources/Vela_Mat_3.X");
    com->m_model->loadFromFile("resources/Vela_Mat_4.X");
    com->m_model->loadFromFile("resources/Vela_Mat_5.X");
    com->m_model->loadFromFile("resources/Vela_Mat_6.X");
    for (auto mesh : com->m_model->m_meshes) {
      Material* mat = new Material();
    }
    m_testModel.addComponent(com);
    

    //m_meshList.loadFromFile("resources/Vela.FBX");
    //test();


    m_constantBuffer.add(reinterpret_cast<char*>(&m_world), sizeof(m_world));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_camera.getView()), 
                         sizeof(Matrix4));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_projection), sizeof(m_projection));

    m_constantBuffer.createHardware(m_device.m_pd3dDevice, 0);

    m_device.m_pImmediateContext->UpdateSubresource(m_constantBuffer.m_pBuffer,
                                                    0,
                                                    nullptr, 
                                                    &m_constantBuffer.m_constantData[0],
                                                    m_constantBuffer.m_constantData.size(),
                                                    0);

    m_constantBuffer.setVertexShader(m_device.m_pImmediateContext, 0, 1);
    m_constantBuffer.setPixelShader(m_device.m_pImmediateContext, 0, 1);
    //end test
    return true;
  }

  void
  GraphicsAPIDX::render() {
    


    setShaders(m_device.m_pImmediateContext,
               m_vertexShader.m_pVertexShader,
               SHADERFLAGS::VERTEX);

    setShaders(m_device.m_pImmediateContext,
               m_pixelShader.m_pPixelShader,
               SHADERFLAGS::PIXEL);

    m_constantBuffer.clear();
    m_world.rotateY(0.001f);
    m_constantBuffer.add(reinterpret_cast<char*>(&m_world), sizeof(m_world));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_camera.getView()),
                                                 sizeof(Matrix4));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_projection), sizeof(m_projection));


    m_device.m_pImmediateContext->UpdateSubresource(m_constantBuffer.m_pBuffer,
                                                    0,
                                                    nullptr,
                                                    &m_constantBuffer.m_constantData[0],
                                                    0,
                                                    0);
    m_constantBuffer.setVertexShader(m_device.m_pImmediateContext, 0, 1);
    m_constantBuffer.setPixelShader(m_device.m_pImmediateContext, 0, 1);

    m_inputLayout.setLayout(m_device.m_pImmediateContext);

    float color[4] = { 0.5f,0.5f,0.5f,1.0f };
    m_device.m_pImmediateContext->ClearRenderTargetView(m_texture.m_pRenderTargetView, 
                                                        color);
    m_device.m_pImmediateContext->ClearDepthStencilView(m_texture.m_DepthStencilView, 
                                                        D3D11_CLEAR_DEPTH, 
                                                        1.0f, 
                                                        0);
    m_samplerState.setShaderSampler(m_device.m_pd3dDevice);
    Model* m = static_cast<MeshComponent*>(m_testModel.getComponent(COMPONENT::MESH))->m_model;
    m->render();
    
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

  Device*
  GraphicsAPIDX::getDevice() {
    return &m_device;
  }


  void
  GraphicsAPIDX::swapBuffer() {
    m_device.m_pSwapChain->Present(DXGI_SWAP_EFFECT_DISCARD, DXGI_PRESENT_DO_NOT_WAIT);
  }
}