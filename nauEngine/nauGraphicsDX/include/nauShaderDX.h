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
    init(Device* pDevice) = 0;

    virtual bool
    compile(String filename, String entryPoint, String profile, uint32 FLAGS) override;

    virtual void*
    getData() override;

    virtual void*
    getShader() = 0;

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

    virtual bool
    init(Device* pDevice) override;

    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) override;

    virtual void
    set(Device* pDevice) override;

    virtual void*
    getShader() override;

   public:

    /**
     * the vertex Shader for DirectX
     */
    ID3D11VertexShader* m_pVertexShader = nullptr;
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

    virtual bool
    init(Device* pDevice) override;

    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) override;

    virtual void
    set(Device* pDevice) override;

    virtual void*
    getShader() override;
   public:

    /**
     * Pixel Shader for DirectX
     */
    ID3D11PixelShader* m_pPixelShader = nullptr;
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
    ~ComputeShaderDX() = default;

    virtual bool
    init(Device* pDevice) override;

    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) override;

    virtual void
    set(Device* pDevice) override;

    virtual void*
    getShader() override;

   public:

    /**
     * Computer shader for DirectX
     */
    ID3D11ComputeShader* m_pComputeShader;
    
    /**
     * Kernel object for computing with CL
     */
    cl::Kernel m_kernel;
    
    /**
     * Default platform for computing
     */
    cl::Platform m_defaultPlatform;

    /**
     * The cContext for the CL computing
     */
    cl::Context m_defaultContext;

    /**
     * The default device created from the D3D11 Device
     */
    cl::Device m_defaultDevice;
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
    ~GeometryShaderDX() = default;

    virtual bool
    init(Device* pDevice) override;

    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) override;
  
    virtual void
    set(Device* pDevice) override;

    virtual void*
    getShader() override;

    /**
     * Geometry Shader
     */
    ID3D11GeometryShader* m_pGeometryShader;

    
  };

   /**
    * TextureShader
    * Description:
    *     CURRENTLY NOT SUPPORTED
    * Sample usage:
    * 
    */
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
    ~TextureShaderDX() = default;

    virtual bool
    init(Device* pDevice) override;

    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) override;
    
    virtual void
    set(Device* pDevice) override;

    virtual void*
    getShader() override;
  };

}
