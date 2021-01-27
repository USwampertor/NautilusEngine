/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauSwapChainDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/08 2019
 * @brief Swap Chain DX member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauSwapChainDX.h"

namespace nauEngineSDK {
  
  void*
  SwapChainDX::get() {
    return m_pSwapChain;
  }

  void
  SwapChainDX::getBackBuffer(Texture* ref) {
    auto pd3dTexture = reinterpret_cast<ID3D11Texture2D*>(ref->getAPITexture());
    HRESULT hr = E_FAIL;

    hr = m_pSwapChain->GetBuffer(0, 
                                 __uuidof(ID3D11Texture2D), 
                                 reinterpret_cast<LPVOID*>(&pd3dTexture));
    if (FAILED(hr)) {
      throw::std::exception("Failed to get backbuffer");
      //return false;
    }


  }
}
