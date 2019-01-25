/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsBufferDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/21 2018
 * @brief DirectX hardware declaration
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauGraphicsBufferDX.h"

namespace nauEngineSDK {
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBufferDX.cpp DirectX vertex hardware function declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauVertexBufferDX::createHardware(void* pDevice, uint32 usage) {
    
    D3D11_USAGE tUsage = static_cast<D3D11_USAGE>(usage);
    D3D11_BUFFER_DESC bd;
    memset(&bd, 0, sizeof(bd));

    bd.Usage = tUsage;
    bd.ByteWidth = static_cast<uint32>(sizeof(nauVertex)*m_vertexData.size());
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA InitData;
    memset(&InitData, 0, sizeof(InitData));
    InitData.pSysMem = &m_vertexData[0];

    auto pDev = reinterpret_cast<ID3D11Device*>(pDevice);

    HRESULT hr = pDev->CreateBuffer(&bd, &InitData, &m_pBuffer);
    if (FAILED(hr)) {
      std::cout << "Failed to create Vertex Buffer you idiot \n" ;
    }
  }

  void
  nauVertexBufferDX::write(void* pDevice, void* pData, SIZE_T numBytes) {

    D3D11_MAPPED_SUBRESOURCE subRes;
    memset(&subRes, 0, sizeof(subRes));
    //from this buffer we wanna do something
    
    //here we write all the shit we need, the thing is that this is not relative to anything specific


    //we later discard the original thing because we don't need it anymore
    reinterpret_cast<ID3D11DeviceContext*>(pDevice)->Unmap(m_pBuffer, 0);
  }

  void
  nauVertexBufferDX::set(void* pDevice) {
    auto pDC = reinterpret_cast<ID3D11DeviceContext*>(pDevice);
    uint32 str = sizeof(nauVertex);
    uint32 off = 0;
    pDC->IASetVertexBuffers(0, 1, &m_pBuffer, &str, &off);
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBufferDX.cpp DirectX index hardware function declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauIndexBufferDX::createHardware(void* pDevice, uint32 usage) {
    
    D3D11_USAGE tUsage = static_cast<D3D11_USAGE>(usage);
    D3D11_BUFFER_DESC bd;
    memset(&bd, 0, sizeof(bd));

    bd.Usage = tUsage;
    bd.ByteWidth = static_cast<UINT32>(sizeof(uint32)*m_indexData.size());
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA InitData;
    memset(&InitData, 0, sizeof(InitData));
    InitData.pSysMem = &m_indexData[0];

    auto pDev = reinterpret_cast<ID3D11Device*>(pDevice);
    HRESULT hr = pDev->CreateBuffer(&bd, &InitData, &m_pBuffer);
    if (FAILED(hr)) {
      std::cout << "Failed to create Vertex Buffer you idiot \n";
    }
  }

  void
  nauIndexBufferDX::write(void* pDevice, void* pData, SIZE_T numBytes) {

  }

  void
  nauIndexBufferDX::set(void* pDevice) {
    auto pDC = reinterpret_cast<ID3D11DeviceContext*>(pDevice);
    pDC->IASetIndexBuffer(this->m_pBuffer, DXGI_FORMAT_R32_UINT, 0);
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBufferDX.cpp DirectX constant hardware function declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauConstantBufferDX::createHardware(void* pDevice, uint32 usage) {
    
    D3D11_USAGE tUsage = static_cast<D3D11_USAGE>(usage);
    D3D11_BUFFER_DESC bd;
    memset(&bd, 0, sizeof(bd));

    bd.Usage = tUsage;
    bd.ByteWidth = static_cast<UINT32>(sizeof(char)*m_constantData.size());
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA InitData;
    memset(&InitData, 0, sizeof(InitData));
    InitData.pSysMem = &m_constantData[0];

    HRESULT hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateBuffer(&bd, 
                                                                        &InitData, 
                                                                        &m_pBuffer);
    if (FAILED(hr)) {
      std::cout << "Failed to create Vertex Buffer you idiot \n";
    }
  }

  void
  nauConstantBufferDX::write(void* pDevice, void* pData, SIZE_T numBytes) {

  }

  void
  nauConstantBufferDX::set(void* pDevice) {

  }
}