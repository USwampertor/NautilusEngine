/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDepthStencilDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/29 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesDX.h"

#include <nauDepthStencil.h>


namespace nauEngineSDK {

  class NAU_DIRECTX_EXPORT DepthStencilDX : public DepthStencil
  {
   public:

    /**
     * default constructor
     */
    DepthStencilDX() = default;

    /**
     * default destructor
     */
    ~DepthStencilDX() = default;

    virtual bool
    createDepthStencil(Device& pDevice,
                       uint32 height,
                       uint32 width) override;
  
    virtual void
    clearView(Device* pDevice) override;

    virtual void*
    getView() override;

    virtual bool
    createView() override;

    virtual bool
    createState() override;


    /**
     * Depth stencil view
     */
    ID3D11DepthStencilView* m_pDepthStencilView = nullptr;

    /**
     * Texture of the depth stencil
     */
    ID3D11Texture2D* m_pDepthStencilTexture = nullptr;

    /**
     * Depth Stencil State
     */
    ID3D11DepthStencilState* m_pDepthStencilState = nullptr;
  };
  
}


