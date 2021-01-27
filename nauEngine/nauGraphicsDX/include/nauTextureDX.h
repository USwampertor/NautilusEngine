/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauTextureDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/28 2018
 * @brief Texture implementation for DirectX
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauTexture.h>
#include <nauLogger.h>

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
    init(Device* pDevice, int32 width, int32 height) override;

    virtual bool
    loadFromFile(String path, Device* pDevice) override;

    virtual bool
    loadFromMemory(Device* pDevice, Vector<char> buffer) override;

    virtual void*
    getAPITexture() override;

    virtual bool
    load(String path) override;

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

