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
  nauDepthStencilDX::createDepthStencil(void* pDevice,
                                        void* pDeviceContext,
                                        uint32 height,
                                        uint32 width,
                                        nauTexture* texture) {


    HRESULT hr = S_OK;
    D3D11_TEXTURE2D_DESC descDepth;

    ID3D11Device* pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice);
    ID3D11DeviceContext* pd3dImmediate = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);
    nauTextureDX* pTextureDX = reinterpret_cast<nauTextureDX*>(texture);

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

    hr = pd3dDevice->CreateTexture2D(&descDepth,
                                     nullptr, 
                                     &pTextureDX->m_pd3dTexture2D);

    //D3D11_TEXTURE2D_DESC descDepth;
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;

    memset(&descDSV, 0, sizeof(descDSV));

    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;

    //hr = pd3dDevice->CreateDepthStencilView(pTextureDX->m_pd3dTexture2D, &descDSV, &m_DepthStencilView);
    //if (FAILED(hr))
    //{
    //  return false;
    //}
    //
    //pd3dImmediate->OMSetRenderTargets(1, &m_pRenderTargetView, m_DepthStencilView);
    //
    return true;
  }

}
