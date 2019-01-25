#include "nauMeshDX.h"
#include "nauGraphicsBufferDX.h"
namespace nauEngineSDK {
  void
  nauMeshDX::render(void* pDeviceContext) {
    uint32 stride;
    uint32 offset;
    stride = sizeof(nauVertex);
    offset = 0;
    auto pDC = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);
    auto pVB = reinterpret_cast<nauVertexBufferDX*>(m_vertexBuffer);
    auto pIB = reinterpret_cast<nauIndexBufferDX*>(m_indexBuffer);
   

    pVB->set(pDeviceContext);
    pIB->set(pDeviceContext);

    //pDC->IASetVertexBuffers(0, 1, &pVB->m_pBuffer, &stride, &offset);
    //
    //reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->IASetIndexBuffer(
    //  reinterpret_cast<nauGraphicsBufferDX*>(m_indexBuffer)->m_pBuffer,
    //  DXGI_FORMAT_R32_UINT,
    //  0);

    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->IASetPrimitiveTopology(
      D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->DrawIndexed(
      m_indexBuffer->m_indexData.size(), 
      0, 
      0);
  }
}