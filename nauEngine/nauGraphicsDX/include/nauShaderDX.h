/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauShaderDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief DirectX shader implementation of base class core Shader
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"
#include <nauShader.h>

namespace nauEngineSDK {

  class NAU_DIRECTX_EXPORT ShaderDX : public Shader
  {
  public:

    /**
     * Default constructor
     */
    ShaderDX() = default;

    /**
     * Default destructor
     */
    virtual 
    ~ShaderDX() {
      if (m_d3dBlob != nullptr) {
        m_d3dBlob->Release();
        m_d3dBlob = nullptr;
      }
    };

    virtual bool
    compile(String filename, String entryPoint, String profile, uint32 FLAGS) override;

    virtual void*
    getData() = 0;

    virtual void
    set(Device* pDevice) = 0;

   public:

    /**
     * DirectX blob resource. It normally has all the important data of the shader
     */
    ID3DBlob* m_d3dBlob = nullptr;

  };
  

  class NAU_DIRECTX_EXPORT VertexShaderDX : public ShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    VertexShaderDX() = default;

    /**
     * Default Constructor
     */
    ~VertexShaderDX() {
      if (m_pVertexShader != nullptr) {
        m_pVertexShader->Release();
        m_pVertexShader = nullptr;
      }
    };

    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) override;

    virtual void
    set(Device* pDevice) override;

   public:

    /**
     * the vertex Shader for DirectX
     */
    ID3D11VertexShader* m_pVertexShader;
  };

  class NAU_DIRECTX_EXPORT PixelShaderDX : public ShaderDX
  {
   public:
    /**
     * Default Constructor
     */
     PixelShaderDX() = default;

    /**
     * Default Constructor
     */
    ~PixelShaderDX() {

      if (m_pPixelShader != nullptr) {
        m_pPixelShader->Release();
        m_pPixelShader = nullptr;
      }
    }

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);

    virtual void
    set(Device* pDevice) override;

   public:

    /**
     * Pixel Shader for DirectX
     */
    ID3D11PixelShader* m_pPixelShader;
  };

  class NAU_DIRECTX_EXPORT ComputeShaderDX : public ShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    ComputeShaderDX() = default;

    /**
     * Default Constructor
     */
    ~ComputeShaderDX() {};

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);

    virtual void
    set(Device* pDevice) override;

   public:

    /**
     * Computer shader for DirectX
     */
    ID3D11ComputeShader* m_pComputeShader;

  };

  class NAU_DIRECTX_EXPORT GeometryShaderDX : public ShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    GeometryShaderDX() = default;

    /**
     * Default Constructor
     */
    ~GeometryShaderDX() {};

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);
  
    virtual void
    set(Device* pDevice) override;

    /**
     * 
     */
    ID3D11GeometryShader* m_pGeometryShader;
  };

  class NAU_DIRECTX_EXPORT TextureShaderDX : public ShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    TextureShaderDX() = default;

    /**
     * Default Constructor
     */
    ~TextureShaderDX() {};

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);
    
    virtual void
    set(Device* pDevice) override;

  };

}
