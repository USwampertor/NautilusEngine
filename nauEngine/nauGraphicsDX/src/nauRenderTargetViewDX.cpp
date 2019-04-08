/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRenderTargetViewDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/07 2019
 * @brief member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauRenderTargetViewDX.h"

namespace nauEngineSDK {
  
  bool
  RenderTargetViewDX::createRenderTargetView(Device* pDevice, Texture* texture) {
    
    HRESULT hr = E_FAIL;
    auto pd3dTexture = reinterpret_cast<ID3D11Texture2D*>(texture->getAPITexture());

    
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    hr = pd3dDevice->CreateRenderTargetView(pd3dTexture, nullptr, &m_pRenderTargetView);
    return true;
  }

  void
  RenderTargetViewDX::set(Device& pDevice, DepthStencil& depthStencil) {

    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice.getContext());
    auto pd3dDepthStencil = reinterpret_cast<ID3D11DepthStencilView*>(depthStencil.getView());

    pd3dContext->OMSetRenderTargets(1,&m_pRenderTargetView, nullptr);

  }

  void
  RenderTargetViewDX::clearView(Device* pDevice, Vector4 color) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->ClearRenderTargetView(m_pRenderTargetView, &color[0]);

  }
}
