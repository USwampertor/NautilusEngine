/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTextureDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/28 2018
 * @brief Texture implementation for DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauTexture.h>

namespace nauEngineSDK {
  class NAU_DIRECTX_EXPORT TextureDX : public Texture
  {
   public:

    /**
     * Default constructor
     */
    TextureDX() = default;

    /**
     * Default destructor
     */
    ~TextureDX() = default;

    virtual bool
    loadFromFile(String path, Device* pDevice) override;

    virtual bool
    loadFromMemory(Device* pDevice, Vector<char> buffer) override;

    
    virtual void*
    getAPITexture() override;

    /**
     * Member declaration
     */
   public:
    
    /**
     * ID3D11 texture
     */
    ID3D11Texture2D* m_pd3dTexture2D = nullptr;

    
  };
}

