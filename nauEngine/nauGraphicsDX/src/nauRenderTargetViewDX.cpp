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
  RenderTargetViewDX::set(Device& pDevice, DepthStencil& depthStencil, int32 position) {

    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice.getContext());
    auto pd3dDepthStencil = reinterpret_cast<ID3D11DepthStencilView*>(depthStencil.getView());

    pd3dContext->OMSetRenderTargets(position,&m_pRenderTargetView, pd3dDepthStencil);

  }

  void
  RenderTargetViewDX::clearView(Device* pDevice, Vector4 color) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->ClearRenderTargetView(m_pRenderTargetView, &color[0]);

  }

  void*
  RenderTargetViewDX::getRendereableTexture(Device* pDevice) {
    
    D3D11_RENDER_TARGET_VIEW_DESC* targetDesc = new D3D11_RENDER_TARGET_VIEW_DESC;
    m_pRenderTargetView->GetDesc(targetDesc);


    HRESULT hr = E_FAIL;
    ID3D11Texture2D* texture = nullptr;

    D3D11_TEXTURE2D_DESC descTexture;
    memset(&descTexture, 0, sizeof(descTexture));

    descTexture.Width = m_width;
    descTexture.Height = m_height;
    descTexture.MipLevels = 1;
    descTexture.ArraySize = 1;
    descTexture.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    descTexture.SampleDesc.Count = 1;
    descTexture.SampleDesc.Quality = 0;
    descTexture.Usage = D3D11_USAGE_DEFAULT;
    descTexture.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    descTexture.CPUAccessFlags = 0;
    descTexture.MiscFlags = 0;


    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    hr = pd3dDevice->CreateRenderTargetView(texture, nullptr, &m_pRenderTargetView);

    if (FAILED(hr)) {
      throw::std::exception("COULDNT MAKE A RENDEREABLE TEXTURE");
    }
    return texture;
  }

  void*
  RenderTargetViewDX::getRenderTarget() {
    return m_pRenderTargetView;
  }
}
