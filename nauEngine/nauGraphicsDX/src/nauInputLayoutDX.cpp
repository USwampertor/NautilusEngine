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
  nauInputLayoutDX::setInputDescriptor() {
    
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
    add(&inputDesc);
    
    //INDEX
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "COLOR";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 16;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    add(&inputDesc);

    //NORMAL
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "NORMAL";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 32;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    add(&inputDesc);
    
    //TEXCOORD
    memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    inputDesc.SemanticName = "TEXCOORD";
    inputDesc.SemanticIndex = 0;
    inputDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
    inputDesc.InputSlot = 0;
    inputDesc.AlignedByteOffset = 48;
    inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    inputDesc.InstanceDataStepRate = 0;
    add(&inputDesc);
  }

  //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
  void
  nauInputLayoutDX::setVertex() {
    D3D11_INPUT_ELEMENT_DESC vertex;
    vertex.SemanticName = "POSITION";
    vertex.SemanticIndex = 0;
    vertex.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    vertex.InputSlot = 0;
    vertex.AlignedByteOffset = 0;
    vertex.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    vertex.InstanceDataStepRate = 0;
    add(&vertex);
  }

  //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
  void
  nauInputLayoutDX::setColor() {
    D3D11_INPUT_ELEMENT_DESC index;
    index.SemanticName = "COLOR";
    index.SemanticIndex = 0;
    index.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    index.InputSlot = 0;
    index.AlignedByteOffset = 0;
    index.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    index.InstanceDataStepRate = 0;
    add(&index);
  }

  void
  nauInputLayoutDX::reserve(SIZE_T numObjects) {
    m_descVector.reserve(numObjects);
  }

  void
  nauInputLayoutDX::add(void* input) {
    m_descVector.push_back(reinterpret_cast<D3D11_INPUT_ELEMENT_DESC&>(input));
  }

  void
  nauInputLayoutDX::getfromBLOB(void* pReflection, SIZE_T size) {
    UNREFERENCED_PARAMETER(pReflection);
    UNREFERENCED_PARAMETER(size);
  }

  void
  nauInputLayoutDX::clear() {
    m_descVector.clear();
  }

  void
  nauInputLayoutDX::createInputBuffer(void* pDevice, nauShader* pShader) {
    HRESULT hr = static_cast<ID3D11Device*>(pDevice)->CreateInputLayout(
                  &m_descVector[0],
                  (UINT)m_descVector.size(),
                  static_cast<nauShaderDX*>(pShader)->m_d3dBlob->GetBufferPointer(),
                  static_cast<nauShaderDX*>(pShader)->m_d3dBlob->GetBufferSize(),
                  &m_layout);
    if (FAILED(hr)) {
      std::cout<<"Failed to create Vertex Buffer you idiot" << std::endl;
    }
  }

  void
  nauInputLayoutDX::setLayout(void* pImmediateContext) {
    static_cast<ID3D11DeviceContext*>(pImmediateContext)->IASetInputLayout(m_layout);
  }
}