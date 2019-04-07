/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDepthStencilDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauDepthStencilDX.h"

namespace nauEngineSDK {

  bool
  DepthStencilDX::createDepthStencil(Device* pDevice,
                                     uint32 height,
                                     uint32 width,
                                     void* texture) {

    HRESULT hr = E_FAIL;
    D3D11_TEXTURE2D_DESC descDepth;
    auto pd3dTexture2D = reinterpret_cast<ID3D11Texture2D*>(texture);
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());

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



    hr = pd3dDevice->CreateTexture2D(&descDepth, nullptr, &pd3dTexture2D);

    //D3D11_TEXTURE2D_DESC descDepth;
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;

    memset(&descDSV, 0, sizeof(descDSV));

    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;

    hr = pd3dDevice->CreateDepthStencilView(pd3dTexture2D,
                                            &descDSV,
                                            &m_DepthStencilView);

    if (FAILED(hr)) {
      throw::std::exception("Failed to create depth stencil view");
    }

    return true;
  }

  void*
  DepthStencilDX::get() {
    return m_DepthStencilView;
  }

  void
  DepthStencilDX::clean() {

  }

}
