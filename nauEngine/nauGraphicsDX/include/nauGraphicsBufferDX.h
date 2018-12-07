/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVertexBufferDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/25 2018
 * @brief Direct X 13 specific vertex Buffer
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"
#include <nauGraphicsBuffer.h>

namespace nauEngineSDK {

  class NAU_DIRECTX_EXPORT nauGraphicsBufferDX : public nauGraphicsBuffer
  {
   public:
     /**
      * Default constructor
      */
    nauGraphicsBufferDX() = default;

    /**
     * Default destructor
     */
    ~nauGraphicsBufferDX() {}

   public:
    /**
     * DirectX buffer
     */
    ID3D11Buffer* m_pBuffer = nullptr;
  };

  class NAU_DIRECTX_EXPORT nauVertexBufferDX : public nauVertexBuffer, nauGraphicsBufferDX
  {
  public:
    nauVertexBufferDX() = default;
    ~nauVertexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);
  };

  class NAU_DIRECTX_EXPORT nauIndexBufferDX : public nauIndexBuffer, nauGraphicsBufferDX
  {
  public:
    nauIndexBufferDX() = default;
    ~nauIndexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);
  };

  class NAU_DIRECTX_EXPORT nauConstantBufferDX : public nauConstantBuffer, nauGraphicsBufferDX
  {
  public:
    nauConstantBufferDX() = default;
    ~nauConstantBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);
  };
  
}

