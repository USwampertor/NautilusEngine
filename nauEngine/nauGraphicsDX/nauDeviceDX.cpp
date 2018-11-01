#include "nauDeviceDX.h"
namespace nauEngineSDK {
  bool
    nauDeviceDX::initializeDevice(void* scrHandler) {
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

      result = D3D11CreateDeviceAndSwapChain( nullptr,
                                              dt,
                                              nullptr,
                                              deviceFlags,
                                              &featureLevels[0],
                                              static_cast<UINT>(featureLevels.size()),
                                              D3D11_SDK_VERSION,
                                              &sd,
                                              &m_pSwapChain,
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
  nauDeviceDX::onRender() {

  }

  bool
  nauDeviceDX::createBuffer() {
    return true;
  }

  bool
  nauDeviceDX::createDepthStencilView() {
    return true;
  }



}