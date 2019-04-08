/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauVertexBufferDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/25 2018
 * @brief Direct X 13 specific vertex Buffer
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
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
    /**
     * DirectX buffer
     */
    ID3D11Buffer* m_pBuffer = nullptr;
  };

  class NAU_DIRECTX_EXPORT VertexBufferDX : public VertexBuffer, public GraphicsBufferDX
  {
  public:
    VertexBufferDX() = default;
    ~VertexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);

    void
    set(void* pDevice);
  };

  class NAU_DIRECTX_EXPORT IndexBufferDX : public IndexBuffer, public GraphicsBufferDX
  {
  public:
    IndexBufferDX() = default;
    ~IndexBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);

    void
    set(void* pDevice);
  };

  class NAU_DIRECTX_EXPORT ConstantBufferDX : public ConstantBuffer, public GraphicsBufferDX
  {
  public:
    ConstantBufferDX() = default;
    ~ConstantBufferDX() {}

    void
    createHardware(void* pDevice, uint32 usage = 0);

    void
    write(void* pDevice, void* pData, SIZE_T numBytes);

    void
    setVertexShader(void* pContext, uint32 slot = 0, uint32 numBuffer = 1);

    void
    setPixelShader(void* pContext, uint32 slot = 0, uint32 numBuffer = 1);

    virtual bool
    updateSubResource(void* pContext,
                      uint32 subresource = 0, 
                      uint32 row = 0, 
                      uint32 depth = 0) override;
  };
  
}

