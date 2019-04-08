/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSamplerStateDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief sampler state DirectX implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauSamplerStateDX.h"
#include "nauDeviceDX.h"

namespace nauEngineSDK {

  bool
  SamplerStateDX::createSampler(Device* pDevice) {

    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    
    HRESULT hr = E_FAIL;
    D3D11_SAMPLER_DESC sampler;

    //Here we declare the type of filtering
    sampler.Filter = D3D11_FILTER_ANISOTROPIC;
    sampler.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sampler.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampler.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    sampler.MipLODBias = 0.0f;
    sampler.MaxAnisotropy = 1;
    sampler.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
    sampler.BorderColor[0] = 0;
    sampler.BorderColor[1] = 0;
    sampler.BorderColor[2] = 0;
    sampler.BorderColor[3] = 0;
    sampler.MinLOD = 0;
    sampler.MaxLOD = D3D11_FLOAT32_MAX;

    // Create the texture sampler state.
    hr = pd3dDevice->CreateSamplerState(&sampler, &m_sampleState);
    if (FAILED(hr)) {
      throw::std::exception("Failed to create sampler state");
      return false;
    }
    
    return true;

  }

  void
  SamplerStateDX::setSampler(Device* pDevice, uint32 registration, uint32 times) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    //First parameter is the register where you are using the texture
    //second is how many times we are going to do this
    pd3dContext->PSSetSamplers(registration, times, &m_sampleState);


  }

}