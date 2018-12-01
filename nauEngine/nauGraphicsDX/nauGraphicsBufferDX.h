/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauVertexBufferDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/25 2018
 * @brief Direct X 13 specific vertex Buffer
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesDX.h"
#include <nauGraphicsBuffer.h>

namespace nauEngineSDK {
  class NAU_DIRECTX_EXPORT nauGraphicsBufferDX : public nauGraphicsBuffer
  {
  public:
    nauGraphicsBufferDX() = default;
    ~nauGraphicsBufferDX() {}

   public:

    /**
     * DirectX buffer
     */
    ID3D11Buffer* m_pBuffer = nullptr;
  };

  class nauVertexBufferDX : public nauVertexBuffer, nauGraphicsBufferDX
  {
  public:
    nauVertexBufferDX() = default;
    ~nauVertexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);
  };

  class nauIndexBufferDX : public nauIndexBuffer, nauGraphicsBufferDX
  {
  public:
    nauIndexBufferDX() = default;
    ~nauIndexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);
  };

  class nauConstantBufferDX : public nauConstantBuffer, nauGraphicsBufferDX
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

