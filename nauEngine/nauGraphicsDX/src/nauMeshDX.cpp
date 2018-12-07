#include "nauMeshDX.h"
#include "nauGraphicsBufferDX.h"
namespace nauEngineSDK {
  void
  nauMeshDX::render(void* pDeviceContext) {
    unsigned int stride;
    unsigned int offset;
    stride = sizeof(nauVertex);
    offset = 0;//sizeof(float);

    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->IASetVertexBuffers(
      0,
      1,
      &(reinterpret_cast<nauGraphicsBufferDX*>(m_vertexBuffer)->m_pBuffer),
      &stride, 
      &offset);
    
    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->IASetIndexBuffer(
      reinterpret_cast<nauGraphicsBufferDX*>(m_indexBuffer)->m_pBuffer,
      DXGI_FORMAT_R32_UINT,
      0);

    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->IASetPrimitiveTopology(
      D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->DrawIndexed(
      m_indexBuffer->m_indexData.size(), 
      0, 
      0);
  }
}