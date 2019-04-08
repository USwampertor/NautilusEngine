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
  RenderTargetViewDX::createRenderTargetView(Device* pDevice, void* pSwapChain) {
    HRESULT hr = E_FAIL;

    ID3D11Texture2D* pBackBuffer = nullptr;

    auto pd3dSwapChain = reinterpret_cast<IDXGISwapChain*>(pSwapChain);

    hr = pd3dSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&pBackBuffer));
    if (FAILED(hr)) {
      throw::std::exception("Failed to create RenderTargetView");
      //return false;
    }
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    hr = pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView);
    //Releases the back buffer
    pBackBuffer->Release();
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
