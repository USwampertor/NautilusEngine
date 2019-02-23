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

  class NAU_DIRECTX_EXPORT GraphicsBufferDX : public GraphicsBuffer
  {
   public:
     /**
      * Default constructor
      */
    GraphicsBufferDX() = default;

    /**
     * Default destructor
     */
    ~GraphicsBufferDX() {}

   public:
    /**
     * DirectX buffer
     */
    ID3D11Buffer* m_pBuffer = nullptr;
  };

  class NAU_DIRECTX_EXPORT nauVertexBufferDX : public nauVertexBuffer, GraphicsBufferDX
  {
  public:
    nauVertexBufferDX() = default;
    ~nauVertexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);

    void
    set(void* pDevice);
  };

  class NAU_DIRECTX_EXPORT nauIndexBufferDX : public nauIndexBuffer, GraphicsBufferDX
  {
  public:
    nauIndexBufferDX() = default;
    ~nauIndexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);

    void
    set(void* pDevice);
  };

  class NAU_DIRECTX_EXPORT nauConstantBufferDX : public nauConstantBuffer, GraphicsBufferDX
  {
  public:
    nauConstantBufferDX() = default;
    ~nauConstantBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);

    void
    set(void* pDevice);
  };
  
}

