/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRasterizerStateDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/07 2019
 * @brief Rasterizer state DX member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauRasterizerStateDX.h"

namespace nauEngineSDK {
  
  bool
  RasterizerStateDX::createRasterizerState(Device* pDevice) {
    
    HRESULT hr = E_FAIL;
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    D3D11_RASTERIZER_DESC rasterizerDesc;
    memset(&rasterizerDesc, 0, sizeof(rasterizerDesc));
    rasterizerDesc.FillMode = D3D11_FILL_SOLID;
    rasterizerDesc.CullMode = D3D11_CULL_BACK;
    rasterizerDesc.FrontCounterClockwise = false;
    rasterizerDesc.DepthBias = 0;
    rasterizerDesc.DepthBiasClamp = 0;
    rasterizerDesc.SlopeScaledDepthBias = 0;
    rasterizerDesc.DepthClipEnable = true;  
    rasterizerDesc.ScissorEnable = false;
    rasterizerDesc.MultisampleEnable = false;
    rasterizerDesc.AntialiasedLineEnable = false;
    hr = pd3dDevice->CreateRasterizerState(&rasterizerDesc, &m_rasterizer);
    if (FAILED(hr)) {
      throw::std::exception("Couldn't create rasterizer state");
    }

    pd3dContext->RSSetState(m_rasterizer);

    return true;
  }

}