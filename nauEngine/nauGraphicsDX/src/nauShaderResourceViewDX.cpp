/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauShaderResourceViewDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauShaderResourceViewDX.h"

namespace nauEngineSDK {

  bool
  ShaderResourceViewDX::createShaderResourceView(Device* pDevice, void* texture, NAUTEXTUREDESCRIPTOR desc) {
   
    HRESULT hr = E_FAIL;


    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    auto pd3dTexture2D = reinterpret_cast<ID3D11Texture2D*>(texture);

    hr = pd3dDevice->CreateShaderResourceView(pd3dTexture2D,
                                              nullptr,
                                              &m_shaderResourceView);
    if (FAILED(hr)) {
      std::cout << "Failed to create shader resource View" << std::endl;
      return false;
    }
    return true;
  }


  void
  ShaderResourceViewDX::setShaderResourceView(Device* pDevice, uint32 start, uint32 views) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->PSSetShaderResources(0, 1, &m_shaderResourceView);
  }

}
