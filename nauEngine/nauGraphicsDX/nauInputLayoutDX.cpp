/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputLayoutDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief DirectX input layout implementation of base core Input layout
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauInputLayoutDX.h"

namespace nauEngineSDK {
  void
  nauInputLayoutDX::SetInputDesc() {
    
    //VERTEX
    D3D11_INPUT_ELEMENT_DESC inputDesc;
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "POSITION";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 0;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    //add(inputDesc);
    
    //INDEX
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "COLOR";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 16;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    //add(inputDesc);

    //NORMAL
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "NORMAL";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 32;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    //add(inputDesc);
    
    //TEXCOORD
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "TEXCOORD";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 48;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    //add(inputDesc);
  }


  void
  nauInputLayoutDX::reserve(SIZE_T numObjects) {

  }

  void
  nauInputLayoutDX::add(void* input) {

  }

  void
  nauInputLayoutDX::getfromBLOB(void* pReflection, SIZE_T size) {

  }

  void
  nauInputLayoutDX::clear() {

  }

  void
  nauInputLayoutDX::createInputBuffer(void* pDevice, void* pShader) {

  }

  void
  nauInputLayoutDX::setLayout(void* pImmediateContext) {

  }
}