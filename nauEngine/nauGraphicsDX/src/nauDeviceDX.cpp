/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDeviceDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/07 2018
 * @brief Device implementation in DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauDeviceDX.h"

#include "nauDepthStencilDX.h"
#include "nauGraphicsBufferDX.h"
#include "nauInputLayoutDX.h"
#include "nauSamplerStateDX.h"
#include "nauShaderDX.h"
#include "nauShaderResourceViewDX.h"
#include "nauSwapChainDX.h"
#include "nauTextureDX.h"
#include "nauViewPortDX.h"

namespace nauEngineSDK {
  bool
  DeviceDX::initializeDevice(void* scrHandler) {

    m_swapChain = new SwapChainDX();
    
    m_handler = reinterpret_cast<HWND>(scrHandler);
    
    HRESULT result = S_OK;
    
    RECT rectangle;
    GetClientRect(m_handler, &rectangle);
    
    m_width = rectangle.right - rectangle.left;
    m_height = rectangle.bottom - rectangle.top;

    uint32 deviceFlags = 0;

#if defined (NAU_DEBUG_MODE)
    deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    Vector<D3D_DRIVER_TYPE>driverTypes;
    driverTypes.push_back(D3D_DRIVER_TYPE_HARDWARE);
    driverTypes.push_back(D3D_DRIVER_TYPE_WARP);
    driverTypes.push_back(D3D_DRIVER_TYPE_REFERENCE);
    
    Vector<D3D_FEATURE_LEVEL> featureLevels;
    featureLevels.push_back(D3D_FEATURE_LEVEL_11_0);
    featureLevels.push_back(D3D_FEATURE_LEVEL_10_1);
    featureLevels.push_back(D3D_FEATURE_LEVEL_10_0);

    DXGI_SWAP_CHAIN_DESC sd;

    memset(&sd, 0, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = m_width;
    sd.BufferDesc.Height = m_height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = m_handler;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true;

    D3D_FEATURE_LEVEL selectedFL;

    for (size_t driverTypeIndex = 0; driverTypeIndex < driverTypes.size(); ++driverTypeIndex) {
      
      D3D_DRIVER_TYPE& dt = driverTypes[driverTypeIndex];

      result = D3D11CreateDeviceAndSwapChain(nullptr,
                                             dt,
                                             nullptr,
                                             deviceFlags,
                                             &featureLevels[0],
                                             static_cast<uint32>(featureLevels.size()),
                                             D3D11_SDK_VERSION,
                                             &sd,
                                             &reinterpret_cast<SwapChainDX*>(m_swapChain)->m_pSwapChain,
                                             &m_pd3dDevice,
                                             &selectedFL,
                                             &m_pImmediateContext);
      if (SUCCEEDED(result)) {
        break;
      }
    }
    if (FAILED(result)) {
      return false;
    }
    
    return true;
  }

  void
  DeviceDX::onRender() {

  }

  void
  DeviceDX::draw(int size, int topology, int startIndex, int BaseVertex) {
    m_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_pImmediateContext->DrawIndexed(size, startIndex, BaseVertex);
  }

  bool
  DeviceDX::createBuffer() {
    return true;
  }

  bool
  DeviceDX::createDepthStencilView() {
    return true;
  }

  void*
  DeviceDX::get() {
    return m_pd3dDevice;
  }

  void*
  DeviceDX::getContext() {
    return m_pImmediateContext;
  }

  void*
  DeviceDX::getSwapChain() {
    return reinterpret_cast<IDXGISwapChain*>(m_swapChain->get());
  }

  Texture*
  DeviceDX::getBackBuffer() {

    Texture* backBuffer = new TextureDX();
    ID3D11Texture2D* pd3dTexture;
    auto pd3dSwapChain = reinterpret_cast<IDXGISwapChain*>(m_swapChain->get());
    HRESULT hr = E_FAIL;

    hr = pd3dSwapChain->GetBuffer(0,
                                  __uuidof(ID3D11Texture2D),
                                  reinterpret_cast<LPVOID*>(&pd3dTexture));
    if (FAILED(hr)) {
      throw::std::exception("Failed to get back buffer");
    }
    reinterpret_cast<TextureDX*>(backBuffer)->m_pd3dTexture2D = pd3dTexture;
    return backBuffer;
  }

  ///CREATORS

  Shader*
  DeviceDX::createVertexShader() {
    return new VertexShaderDX();
  }

  Shader*
  DeviceDX::createPixelShader() {
    return new PixelShaderDX();
  }

  Texture*
  DeviceDX::createTexture() {
    return new TextureDX();
  }

  InputLayout*
  DeviceDX::createInputLayout() {
    return new InputLayoutDX();
  }

  SamplerState*
  DeviceDX::createSamplerState() {
    return new SamplerStateDX();
  }

  ViewPort*
  DeviceDX::createViewPort() {
    return new ViewPortDX();
  }

  DepthStencil*
  DeviceDX::createDepthStencil() {
    return new DepthStencilDX();
  }

  VertexBuffer*
  DeviceDX::createVertexBuffer() {
    return new VertexBufferDX();
  }

  IndexBuffer*
  DeviceDX::createIndexBuffer() {
    return new IndexBufferDX();
  }

  ConstantBuffer*
  DeviceDX::createConstantBuffer() {
    return new ConstantBufferDX();
  }

  ShaderResourceView*
  DeviceDX::createShaderResourceView() {
    return new ShaderResourceViewDX();
  }

  SwapChain*
  DeviceDX::createSwapChain() {
    return new SwapChainDX();
  }
}