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
  class NAU_DIRECTX_EXPORT nauTextureDX : public nauTexture
  {
   public:

    /**
     * Default constructor
     */
    nauTextureDX() = default;

    /**
     * Default destructor
     */
    ~nauTextureDX() {}

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

