/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTextureDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/06 2018
 * @brief Texture 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauTextureDX.h"

#ifndef STB_IMAGE_IMPLEMENTATION
# define STB_IMAGE_IMPLEMENTATION
# include <stb_image.h>
#endif


namespace nauEngineSDK {

  bool
  TextureDX::loadFromFile(String path, Device* pDevice) {
    
    D3D11_TEXTURE2D_DESC descTexture;
    NAUTEXTUREDESCRIPTOR nauDesc;
    int32 byteperpixel = 0;
    int32 x = 0;
    int32 y = 0;
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

    nauDesc.width           = descTexture.Width = m_width;
    nauDesc.height          = descTexture.Height = m_height;
    nauDesc.mipLevel        = descTexture.MipLevels = 1;
    nauDesc.size            = descTexture.ArraySize = 1;
    nauDesc.format          = descTexture.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    nauDesc.descCount       = descTexture.SampleDesc.Count = 1;
    nauDesc.descQuality     = descTexture.SampleDesc.Quality = 0;
    nauDesc.usage           = descTexture.Usage = D3D11_USAGE_DEFAULT;
    nauDesc.bindFlags       = descTexture.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    nauDesc.cpuAccessFlags  = descTexture.CPUAccessFlags = 0;
    nauDesc.miscFlags       = descTexture.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA texturedataBuffer;

    memset(&texturedataBuffer, 0, sizeof(texturedataBuffer));
   
    
    texturedataBuffer.pSysMem = m_fileData; 
    texturedataBuffer.SysMemPitch = m_width * 4;
   
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    hr = pd3dDevice->CreateTexture2D(&descTexture, 
                                     &texturedataBuffer, 
                                     &m_pd3dTexture2D);
    if (FAILED(hr)) {
      return false;
    }
    stbi_image_free(m_fileData);


    m_shaderResourceView = pDevice->createShaderResourceView();
    m_shaderResourceView->createShaderResourceView(pDevice, m_pd3dTexture2D, nauDesc);
    m_shaderResourceView->setShaderResourceView(pDevice);

    return true;
  }

  bool
  TextureDX::loadFromMemory(Device* pDevice, Vector<char> buffer) {

    return true;
  }


  void*
  TextureDX::getAPITexture() {
    return m_pd3dTexture2D;
  }
}
