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
    m_device = new DeviceDX();
    if (!initDevice(scrHandler)) {
      std::cout << "Failed to initialize device... \n";
      return false;
    }

    return true;
  }

  bool
  GraphicsAPIDX::initDevice(void* scrHandler) {

    m_fov = 0.0f;

    if (!m_device->initializeDevice(scrHandler)) {
      std::cout << "Failed to initialize device... \n";
      return false;
    }
    
    if (!m_viewPort.createViewPort(static_cast<float>(m_device->m_width),
                                   static_cast<float>(m_device->m_height),
                                   1.0f,
                                   1.0f)) {
      std::cout << "Could not create ViewPort \n";
      exit(828);
    }
    m_viewPort.setViewPort(m_device->getContext());

    ///////////// This is for testing the renderer
    

    //m_meshList.setDevice(&m_device);


    
    ///
   
    //test();


    m_constantBuffer.add(reinterpret_cast<char*>(&m_world), sizeof(m_world));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_camera.getView()), 
                         sizeof(Matrix4));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_projection), sizeof(m_projection));

    m_constantBuffer.createHardware(m_device->get(), 0);


    reinterpret_cast<ID3D11DeviceContext*>(m_device->getContext())->UpdateSubresource(m_constantBuffer.m_pBuffer,
                                                    0,
                                                    nullptr, 
                                                    &m_constantBuffer.m_constantData[0],
                                                    m_constantBuffer.m_constantData.size(),
                                                    0);

    m_constantBuffer.setVertexShader(m_device->getContext(), 0, 1);
    m_constantBuffer.setPixelShader(m_device->getContext(), 0, 1);
    //end test
    return true;
  }

  void
  GraphicsAPIDX::render() {
    


    setShaders(m_device->getContext(),
               m_vertexShader.m_pVertexShader,
               SHADERFLAGS::VERTEX);

    setShaders(m_device->getContext(),
               m_pixelShader.m_pPixelShader,
               SHADERFLAGS::PIXEL);

    m_constantBuffer.clear();
    m_world.rotateY(0.001f);
    m_constantBuffer.add(reinterpret_cast<char*>(&m_world), sizeof(m_world));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_camera.getView()),
                                                 sizeof(Matrix4));
    m_constantBuffer.add(reinterpret_cast<char*>(&m_projection), sizeof(m_projection));


    reinterpret_cast<ID3D11DeviceContext*>(m_device->getContext())->UpdateSubresource(m_constantBuffer.m_pBuffer,
                                           0,
                                           nullptr,
                                           &m_constantBuffer.m_constantData[0],
                                           0,
                                           0);
    m_constantBuffer.setVertexShader(m_device->getContext(), 0, 1);
    m_constantBuffer.setPixelShader(m_device->getContext(), 0, 1);

    m_inputLayout.setLayout(m_device->getContext());

    clear();
    m_samplerState.setShaderSampler(m_device);
    
    
  }


  Device*
  GraphicsAPIDX::getDevice() {
    return m_device;
  }

  void
  GraphicsAPIDX::clear() {
    Vector4 col = { 0.5f,0.5f,0.5f,1.0f };
    auto pContext = reinterpret_cast<ID3D11DeviceContext*>(m_device->getContext());
    auto pStencil = reinterpret_cast<ID3D11DepthStencilView*>(m_depthStencil.getView());

    m_renderTarget.clearView(m_device, col);
    m_depthStencil.clearView(m_device);

  }

  void
  GraphicsAPIDX::swapBuffer() {
    reinterpret_cast<IDXGISwapChain*>(m_device->getSwapChain())->Present(DXGI_SWAP_EFFECT_DISCARD, DXGI_PRESENT_DO_NOT_WAIT);
  }

  Vector2
  GraphicsAPIDX::getWindowSize() {
    return Vector2(getDevice()->m_width, getDevice()->m_height);
  }
}