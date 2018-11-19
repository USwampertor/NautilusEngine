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
  
    void 
    SetInputDesc();
    
    void
    reserve(SIZE_T numObjects);

    void
    add(void* input);

    void
    getfromBLOB(void* pReflection, SIZE_T size);
    
    void
    clear();

    void
    createInputBuffer(void* pDevice, void* pShader);

    void
    setLayout(void* pImmediateContext);

   public:
    ID3D11InputLayout * m_layout;
    std::vector<D3D11_INPUT_ELEMENT_DESC> descvector;
  };
  
}

