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
    descDepth.Format = DXGI_FORMAT_R24G8_TYPELESS;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;




    hr = pd3dDevice->CreateTexture2D(&descDepth, nullptr, &m_pDepthStencilTexture);

    if (FAILED(hr)) {
      throw::std::exception("Failed to create depth stencil");
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


  bool
  DepthStencilDX::createView(Device* pDevice) {
    //In the case of the DirectX API, we need a depth stencil view
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    HRESULT hr = E_FAIL;
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;

    memset(&descDSV, 0, sizeof(descDSV));

    descDSV.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
    descDSV.Texture2D.MipSlice = 0;

    hr = pd3dDevice->CreateDepthStencilView(m_pDepthStencilTexture,
                                            &descDSV,
                                            &m_pDepthStencilView);

    if (FAILED(hr)) {
      throw::std::exception("Failed to create depth stencil view");
    }
    return true;
  }

  bool
  DepthStencilDX::createState(Device* pDevice) {


    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());

    HRESULT hr = E_FAIL;

    D3D11_DEPTH_STENCIL_DESC stencilDesc;
    memset(&stencilDesc, 0, sizeof(stencilDesc));

    stencilDesc.DepthEnable = true;
    stencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
    stencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    stencilDesc.StencilEnable = false;
    stencilDesc.StencilReadMask;
    stencilDesc.StencilWriteMask;
    const D3D11_DEPTH_STENCILOP_DESC defaultDesc =
    { D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP,D3D11_COMPARISON_ALWAYS };
    stencilDesc.FrontFace = defaultDesc;
    stencilDesc.BackFace = defaultDesc;

    hr = pd3dDevice->CreateDepthStencilState(&stencilDesc, &m_pDepthStencilState);
      if (FAILED(hr)) {
        return false;
    }

    return true;
  }

  void
  DepthStencilDX::setState(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->OMSetDepthStencilState(m_pDepthStencilState, 1);
  }

}
