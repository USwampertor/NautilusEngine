/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRasterizerStateDX.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/07 2019
 * @brief Rasterizer State class for culling and different rendering modes
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauRasterizerState.h>

namespace nauEngineSDK {
  class RasterizerStateDX : public RasterizerState
  {
  public:
    /**
     * Default constructor
     */
    RasterizerStateDX() = default;

    /**
     * Default destructor
     */
    ~RasterizerStateDX() = default;

    virtual bool
    createRasterizerState(Device* pDevice) override;
    
    /**
     * Rasterizer state object from D3D11
     */
    ID3D11RasterizerState* m_rasterizer;
  };

}

