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
    
    uint32 offset = 0;

    //VERTEX
    this->m_descVector.emplace_back();
    auto& vectorDesc = m_descVector.back();

    memset(&vectorDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    vectorDesc.SemanticName = "POSITION";
    vectorDesc.SemanticIndex = 0;
    vectorDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    vectorDesc.InputSlot = 0;
    vectorDesc.AlignedByteOffset = offset;
    vectorDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    vectorDesc.InstanceDataStepRate = 0;
    //add(&vectorDesc);
    offset += sizeof(float) * 4;

    this->m_descVector.emplace_back();
    auto& colorDesc = m_descVector.back();
    //COLOR
    memset(&colorDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    colorDesc.SemanticName = "COLOR";
    colorDesc.SemanticIndex = 0;
    colorDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    colorDesc.InputSlot = 0;
    colorDesc.AlignedByteOffset = offset;
    colorDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    colorDesc.InstanceDataStepRate = 0;
    //add(&colorDesc);
    offset += sizeof(float) * 4;

    this->m_descVector.emplace_back();
    auto& normalDesc = m_descVector.back();
    //NORMAL
    memset(&normalDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    normalDesc.SemanticName = "NORMAL";
    normalDesc.SemanticIndex = 0;
    normalDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    normalDesc.InputSlot = 0;
    normalDesc.AlignedByteOffset = offset;
    normalDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    normalDesc.InstanceDataStepRate = 0;
    //add(&normalDesc);
    offset += sizeof(float) * 4;


    this->m_descVector.emplace_back();
    auto& coordDesc = m_descVector.back();
    //TEXCOORD
    memset(&coordDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    coordDesc.SemanticName = "TEXCOORD";
    coordDesc.SemanticIndex = 0;
    coordDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
    coordDesc.InputSlot = 0;
    coordDesc.AlignedByteOffset = offset;
    coordDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    coordDesc.InstanceDataStepRate = 0;
    //add(&coordDesc);
    offset += sizeof(float) * 2;

    //TANGENT
    this->m_descVector.emplace_back();
    auto& tangentDesc = m_descVector.back();

    memset(&tangentDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    tangentDesc.SemanticName = "TANGENT";
    tangentDesc.SemanticIndex = 0;
    tangentDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
    tangentDesc.InputSlot = 0;
    tangentDesc.AlignedByteOffset = offset;
    tangentDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    tangentDesc.InstanceDataStepRate = 0;
    offset += sizeof(float) * 3;


    //BINORMAL
    this->m_descVector.emplace_back();
    auto& binormal = m_descVector.back();

    memset(&binormal, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    binormal.SemanticName = "BINORMAL";
    binormal.SemanticIndex = 0;
    binormal.Format = DXGI_FORMAT_R32G32B32_FLOAT;
    binormal.InputSlot = 0;
    binormal.AlignedByteOffset = offset;
    binormal.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    binormal.InstanceDataStepRate = 0;
    offset += sizeof(float) * 3;
    /*
    //IDs
    this->m_descVector.emplace_back();
    auto& Ids = m_descVector.back();

    memset(&Ids, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    Ids.SemanticName = "TEXCOORD";
    Ids.SemanticIndex = 1;
    Ids.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
    Ids.InputSlot = 0;
    Ids.AlignedByteOffset = offset;
    Ids.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    Ids.InstanceDataStepRate = 0;
    offset += sizeof(float) * 4;
    /*
    //WEIGHTS
    this->m_descVector.emplace_back();
    auto& weights = m_descVector.back();

    memset(&binormal, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
    binormal.SemanticName = "TEXCOORD";
    binormal.SemanticIndex = 3;
    binormal.Format = DXGI_FORMAT_R32_FLOAT;
    binormal.InputSlot = 3;
    binormal.AlignedByteOffset = offset;
    binormal.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    binormal.InstanceDataStepRate = 0;

    */
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
  InputLayoutDX::createInputBuffer(Device* pDevice, Shader* pShader) {
    auto pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->get());
    auto pdxShader = reinterpret_cast<VertexShaderDX*>(pShader);
    HRESULT hr = pd3dDevice->CreateInputLayout(&m_descVector[0],
                                               (UINT)m_descVector.size(),
                                               pdxShader->m_d3dBlob->GetBufferPointer(),
                                               pdxShader->m_d3dBlob->GetBufferSize(),
                                               &m_layout);
    if (FAILED(hr)) {
      std::cout<<"Failed to create Vertex Buffer you idiot" << std::endl;
    }
  }

  void
  InputLayoutDX::setLayout(void* pImmediateContext) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pImmediateContext);
    pd3dContext->IASetInputLayout(m_layout);
  }
}