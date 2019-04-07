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

#include "nauShaderDX.h"

namespace nauEngineSDK {
  
  class NAU_DIRECTX_EXPORT InputLayoutDX : public InputLayout
  {
   public:
  
    /**
     * Default Constructor
     */
    InputLayoutDX() = default;
  
    /**
     * Default destructor
     */
    ~InputLayoutDX() {}
  
    void 
    setInputDescriptor();
    
    //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
    void
    setVertex();

    //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
    void
    setColor();

    void
    reserve(SIZE_T numObjects);

    void
    add(void* input);

    void
    getfromBLOB(void* pReflection, SIZE_T size);
    
    void
    clear();

    void
    createInputBuffer(Device* pDevice, Shader* pShader);

    void
    setLayout(void* pImmediateContext);

   public:

    /**
     * the DX11 input layout
     */
    ID3D11InputLayout* m_layout;

    /**
     * the element descriptor vector of the objects in the input layout
     */
    std::vector<D3D11_INPUT_ELEMENT_DESC> m_descVector;
  };
  
}

