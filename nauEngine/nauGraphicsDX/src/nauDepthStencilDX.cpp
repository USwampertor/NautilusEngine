/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauDepthStencilDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#include "nauDepthStencilDX.h"

namespace nauEngineSDK {

  bool
  DepthStencilDX::createDepthStencil(Device& pDevice,
                                     uint32 height,
                                     uint32 width) {

    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice.get());
    
    //Sets the Depth Stencil
    HRESULT hr = E_FAIL;
    D3D11_TEXTURE2D_DESC descDepth;

    //This allows us to control what type of depth test Direct3D will do for each pixel.
    memset(&descDepth, 0, sizeof(descDepth));
    descDepth.Width = width;
    descDepth.Height = height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;




    hr = pd3dDevice->CreateTexture2D(&descDepth, nullptr, &m_pDepthStencilTexture);

    if (FAILED(hr)) {
      throw::std::exception("Failed to create depth stencil");
    }

    //In the case of the DirectX API, we need a depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;

    memset(&descDSV, 0, sizeof(descDSV));

    descDSV.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;

    hr = pd3dDevice->CreateDepthStencilView(m_pDepthStencilTexture,
                                            &descDSV,
                                            &m_pDepthStencilView);

    if (FAILED(hr)) {
      throw::std::exception("Failed to create depth stencil view");
    }

    return true;
  }

  void*
  DepthStencilDX::getView() {
    return m_pDepthStencilView;
  }

  void
  DepthStencilDX::clearView(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
  
    pd3dContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH,  1.0f, 0);
  }

}
