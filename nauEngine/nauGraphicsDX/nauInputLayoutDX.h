/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputLayoutDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief DirectX input layout implementation of base core Input Layout
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"
#include <nauInputLayout.h>

namespace nauEngineSDK {
  
  class nauInputLayoutDX : nauInputLayout
  {
  public:
  
    /**
     * Default Constructor
     */
    nauInputLayoutDX() = default;
  
    /**
     * Default destructor
     */
    ~nauInputLayoutDX() {};
  
    /**
     * @brief sets information to the input descriptor descriptor
     * @param 
     * @return 
     *
     */
    void 
    SetInputDesc();
  
   public:
    ID3D11InputLayout * m_layout;
    std::vector<D3D11_INPUT_ELEMENT_DESC> descvector;
  };
  
}

