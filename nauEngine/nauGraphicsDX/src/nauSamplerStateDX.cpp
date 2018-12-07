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

namespace nauEngineSDK {

  bool
  nauSamplerStateDX::createShaderSampler(void* pDevice) {
    HRESULT hr = S_OK;

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
    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateSamplerState(&sampler, &m_sampleState);
    if (FAILED(hr))
    {
      return false;
    }
    
    
    return true;

  }

  void
  nauSamplerStateDX::setShaderSampler(void* pDevice) {
    ID3D11DeviceContext* immContext;
    reinterpret_cast<ID3D11Device*>(pDevice)->GetImmediateContext(&immContext);
    //First parameter is the register where you are using the texture
    //second is how many times we are going to do this
    immContext->PSSetSamplers(0, 1, &m_sampleState);
  }

}