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
  InputLayoutDX::setInputDescriptor() {
    
    //VERTEX
    this->m_descVector.emplace_back();
    auto& vectorDesc = m_descVector.back();

    memset(&vectorDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    vectorDesc.SemanticName = "POSITION";
    vectorDesc.SemanticIndex = 0;
    vectorDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    vectorDesc.InputSlot = 0;
    vectorDesc.AlignedByteOffset = 0;
    vectorDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    vectorDesc.InstanceDataStepRate = 0;
    //add(&vectorDesc);
    
    this->m_descVector.emplace_back();
    auto& colorDesc = m_descVector.back();
    //COLOR
    memset(&colorDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    colorDesc.SemanticName = "COLOR";
    colorDesc.SemanticIndex = 0;
    colorDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    colorDesc.InputSlot = 0;
    colorDesc.AlignedByteOffset = 16;
    colorDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    colorDesc.InstanceDataStepRate = 0;
    //add(&colorDesc);

    this->m_descVector.emplace_back();
    auto& normalDesc = m_descVector.back();
    //NORMAL
    memset(&normalDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    normalDesc.SemanticName = "NORMAL";
    normalDesc.SemanticIndex = 0;
    normalDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    normalDesc.InputSlot = 0;
    normalDesc.AlignedByteOffset = 32;
    normalDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    normalDesc.InstanceDataStepRate = 0;
    //add(&normalDesc);
    
    this->m_descVector.emplace_back();
    auto& coordDesc = m_descVector.back();
    //TEXCOORD
    memset(&coordDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    coordDesc.SemanticName = "TEXCOORD";
    coordDesc.SemanticIndex = 0;
    coordDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
    coordDesc.InputSlot = 0;
    coordDesc.AlignedByteOffset = 48;
    coordDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    coordDesc.InstanceDataStepRate = 0;
    //add(&coordDesc);
  }

  //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
  void
  InputLayoutDX::setVertex() {
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
  InputLayoutDX::setColor() {
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
  InputLayoutDX::reserve(SIZE_T numObjects) {
    m_descVector.reserve(numObjects);
  }

  void
  InputLayoutDX::add(void* input) {
    m_descVector.push_back(reinterpret_cast<D3D11_INPUT_ELEMENT_DESC&>(input));
  }

  void
  InputLayoutDX::getfromBLOB(void* pReflection, SIZE_T size) {
    UNREFERENCED_PARAMETER(pReflection);
    UNREFERENCED_PARAMETER(size);
  }

  void
  InputLayoutDX::clear() {
    m_descVector.clear();
  }

  void
  InputLayoutDX::createInputBuffer(void* pDevice, Shader* pShader) {
    HRESULT hr = static_cast<ID3D11Device*>(pDevice)->CreateInputLayout(
                  &m_descVector[0],
                  (UINT)m_descVector.size(),
                  static_cast<ShaderDX*>(pShader)->m_d3dBlob->GetBufferPointer(),
                  static_cast<ShaderDX*>(pShader)->m_d3dBlob->GetBufferSize(),
                  &m_layout);
    if (FAILED(hr)) {
      std::cout<<"Failed to create Vertex Buffer you idiot" << std::endl;
    }
  }

  void
  InputLayoutDX::setLayout(void* pImmediateContext) {
    static_cast<ID3D11DeviceContext*>(pImmediateContext)->IASetInputLayout(m_layout);
  }
}