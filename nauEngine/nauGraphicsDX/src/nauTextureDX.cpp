/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauTextureDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/06 2018
 * @brief Texture 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauTextureDX.h"


namespace nauEngineSDK {

  bool
  nauTextureDX::loadFromFile(String path, void* pDevice, void* pDeviceContext) {
    UNREFERENCED_PARAMETER(pDeviceContext);
    D3D11_TEXTURE2D_DESC descTexture;
    int byteperpixel = 0;
    int x = 0;
    int y = 0;
    auto m_fileData = stbi_load(path.c_str(), &x, &y, &byteperpixel, 4);
    HRESULT hr = S_OK;

    if (!m_fileData) {
      
      std::cout << "Couldn't load file, loading default file..." << std::endl;
      stbi_image_free(m_fileData);
      m_fileData = stbi_load("checkers.jpg", &x, &x, &byteperpixel, 4);

      if (!m_fileData) {
        std::cout << "Couldn't load default font \n YOU SHOULD FEAR NOW" << std::endl;
        stbi_image_free(m_fileData);
        return false;
      }


    }

    m_width   = static_cast<uint32>(x);
    m_height  = static_cast<uint32>(y);
    
    //Have a case if theres no texture cause the idiot didnt make it fine

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

    D3D11_SUBRESOURCE_DATA texturedataBuffer;

    memset(&texturedataBuffer, 0, sizeof(texturedataBuffer));
    
    
    //Nuestro vector tiene el tama隳 de todos los pixeles que se encuentran
    //En la textura multiplicado por cuanta informacion tiene cada uno
   
    
    texturedataBuffer.pSysMem = m_fileData; 
    texturedataBuffer.SysMemPitch = m_width * 4;
   
    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateTexture2D(&descTexture, &texturedataBuffer, &m_pd3dTexture2D);
    if (FAILED(hr)) {
      return false;
    }
    stbi_image_free(m_fileData);



    createShaderResourceView(reinterpret_cast<ID3D11Device*>(pDevice));
    setShaderResourceView(reinterpret_cast<ID3D11Device*>(pDevice));

    return true;
  }


  bool
  nauTextureDX::createShaderResourceView(void* pDevice) {
    HRESULT hr = E_FAIL;
    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateShaderResourceView(m_pd3dTexture2D, 
                                                                            nullptr, 
                                                                            &m_shaderResource);
    if (FAILED(hr)) {
      std::cout << "Failed to create shader resource View" << std::endl;
      return false;
    }
    return true;
  }

  void
  nauTextureDX::setShaderResourceView(void* pDevice) {
    ID3D11DeviceContext* immContext;
    reinterpret_cast<ID3D11Device*>(pDevice)->GetImmediateContext(&immContext);
    immContext->PSSetShaderResources(0, 1, &m_shaderResource);
  }

  bool
  nauTextureDX::createRenderTargetView(void* pDevice, void* swapChain) {
    
    HRESULT hr = E_FAIL;
    ID3D11Texture2D* pBackBuffer = nullptr;
    
    hr = reinterpret_cast<IDXGISwapChain*>(swapChain)->GetBuffer(0,
                                                      __uuidof(ID3D11Texture2D), 
                                                      reinterpret_cast<LPVOID*>(&pBackBuffer));
    if (FAILED(hr)) {
      std::cout << "Failed to create shader resource View" << std::endl;
      return false;
    }

    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateRenderTargetView(pBackBuffer, 
                                                                          nullptr, 
                                                                          &m_pRenderTargetView);
    //Releases the back buffer
    pBackBuffer->Release();
    return true;
  }

  bool
  nauTextureDX::createDepthStencilView(void* pDevice, void* pDeviceContext) {
    
    UNREFERENCED_PARAMETER(pDeviceContext);
    UNREFERENCED_PARAMETER(pDevice);
    return true;
  }

  bool
  nauTextureDX::createDepthstencil(void* pDevice,
                                   void* pDeviceContext,
                                   uint32 width,
                                   uint32 height) {
    HRESULT hr = E_FAIL;
    D3D11_TEXTURE2D_DESC descDepth;
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

    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateTexture2D(&descDepth, 
                                                                   nullptr, 
                                                                   &m_pd3dTexture2D);

    //D3D11_TEXTURE2D_DESC descDepth;
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;

    memset(&descDSV, 0, sizeof(descDSV));

    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;

    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateDepthStencilView(m_pd3dTexture2D, 
                                                                          &descDSV, 
                                                                          &m_DepthStencilView);
    
    if (FAILED(hr)) {
      std::cout << "Failed to create depth stencil view" << std::endl;
      return false;
    }


    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->OMSetRenderTargets(1, 
                                                                        &m_pRenderTargetView, 
                                                                        m_DepthStencilView);

    return true;
  }

  bool
  nauTextureDX::createShaderSampler(void* pDevice) {
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
    hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateSamplerState(&sampler, 
                                                                      &m_sampleState);
    if (FAILED(hr)) {
      std::cout << "Failed to create sampler state" << std::endl;
      return false;
    }


    return true;
  }

  bool
  nauTextureDX::setShaderSampler(void* pDevice) {
    
    HRESULT hr = E_FAIL;

    ID3D11DeviceContext* immContext;
    reinterpret_cast<ID3D11Device*>(pDevice)->GetImmediateContext(&immContext);
    //First parameter is the register where you are using the texture
    //second is how many times we are going to do this
    immContext->PSSetSamplers(0, 1, &m_sampleState);
    if (FAILED(hr)) {
      std::cout << "Failed to set sampler state" << std::endl;
      return false;
    }

    return true;
  }


}
