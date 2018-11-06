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

  class NAU_DIRECTX_EXPORT nauShaderDX : public nauShader
  {
  public:

    /**
     * Default constructor
     */
    nauShaderDX() = default;

    /**
     * Default destructor
     */
    virtual ~nauShaderDX() {
    
      if (m_d3dBlob != nullptr) {
        m_d3dBlob->Release();
        m_d3dBlob = nullptr;
      }
    };

    /**
     * @brief Compiles a shader resource with the info showed with the directX compiler
     * @param string filename the path or nae of the file
     *        string entry point, basically the name of the main
     *        profile of object
     *        FLAGS for any other information getting of the compiler of the shader
     * @return
     *
     */
    bool
    compile(String filename, String entryPoint, String profile, uint32 FLAGS);

    /**
     * returns the D3DBLOB
     */
    void*
    getData();

   public:

    /**
     * DirectX blob resource. It normally has all the important data of the shader
     */
    ID3DBlob* m_d3dBlob = nullptr;

  };
  

  class NAU_DIRECTX_EXPORT nauVertexShaderDX : public nauShaderDX, public nauVertexShader
  {
   public:
    /**
     * Default Constructor
     */
    nauVertexShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauVertexShaderDX() {
      if (m_pVertexShader != nullptr) {
        m_pVertexShader->Release();
        m_pVertexShader = nullptr;
      }
    };

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);

   public:

    /**
     * the vertex Shader for DirectX
     */
    ID3D11VertexShader* m_pVertexShader;
  };

  class NAU_DIRECTX_EXPORT nauPixelShaderDX : public nauShaderDX, public nauPixelShader
  {
   public:
    /**
     * Default Constructor
     */
     nauPixelShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauPixelShaderDX() {

      if (m_pPixelShader != nullptr) {
        m_pPixelShader->Release();
        m_pPixelShader = nullptr;
      }
    }

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);

   public:

    /**
     * Pixel Shader for DirectX
     */
    ID3D11PixelShader* m_pPixelShader;
  };

  class NAU_DIRECTX_EXPORT nauComputeShaderDX : public nauShaderDX, public nauComputeShader
  {
   public:
    /**
     * Default Constructor
     */
    nauComputeShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauComputeShaderDX() {};

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);

   public:

    /**
     * Computer shader for DirectX
     */
    ID3D11ComputeShader* m_pComputeShader;

  };

  class NAU_DIRECTX_EXPORT nauGeometryShaderDX : public nauShaderDX, public nauGeometryShader
  {
   public:
    /**
     * Default Constructor
     */
    nauGeometryShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauGeometryShaderDX() {};

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);
  

    /**
     * 
     */
    ID3D11GeometryShader* m_pGeometryShader;
  };

  class NAU_DIRECTX_EXPORT nauTextureShaderDX : public nauShaderDX, public nauTextureShader
  {
   public:
    /**
     * Default Constructor
     */
    nauTextureShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauTextureShaderDX() {};

    void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint);
    

  };

}
