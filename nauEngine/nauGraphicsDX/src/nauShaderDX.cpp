/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauShaderDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X implementation of all shader member declaration
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauShaderDX.h"


namespace nauEngineSDK {

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  bool
  ShaderDX::compile(String filename, 
                       String entryPoint, 
                       String profile, 
                       uint32 FLAGS) {
    
    HRESULT result = S_OK;
    ID3DBlob* error = nullptr;
    std::ifstream file(filename.c_str());
    file.open(filename.c_str());
    String shadersource;
    if (!file.is_open())
    {
      result = S_FALSE;
      return false;
    }
    shadersource = { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
    file.close();

#ifdef DEBUG
    FLAGS |= D3DCOMPILE_DEBUG;
#endif

    result = D3DCompile(shadersource.c_str(), shadersource.size(), filename.c_str(), 0, 0, entryPoint.c_str(), profile.c_str(), FLAGS, 0, &m_d3dBlob, &error);
    if (error)
    {
      std::cout << "Error at getting buffer" << error->GetBufferPointer() << std::endl;
      error->Release();
      return false;
    }

    return true;
  }

  void*
  ShaderDX::getData() {
    return m_d3dBlob;
  }



/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Vertex shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauVertexShaderDX::createFromFile(void* pDevice, 
                                    const char* fileName, 
                                    const char* entryPoint) {
    HRESULT hr = E_FAIL;
    hr = ShaderDX::compile(fileName, entryPoint, "vs_5_0", D3DCOMPILE_ENABLE_STRICTNESS);
    NAU_ASSERT(m_d3dBlob != nullptr && "Vertex Shader blob is NULL");
    if (FAILED(hr)) {
      printf("Failed to compile Vertex Shader");
      exit(666);
    }
    auto pDev = static_cast<ID3D11Device*>(pDevice);
    hr = pDev->CreateVertexShader(m_d3dBlob->GetBufferPointer(),
                                  m_d3dBlob->GetBufferSize(),
                                  nullptr,
                                  &m_pVertexShader);
    if (FAILED(hr)) {
      printf("Failed to create Vertex Shader");
      exit(666);
    }
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Pixel shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauPixelShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = E_FAIL;
    hr = ShaderDX::compile(fileName, entryPoint, "ps_5_0", D3DCOMPILE_ENABLE_STRICTNESS);
    NAU_ASSERT(m_d3dBlob != nullptr && "Pixel Shader blob is NULL");
    if (FAILED(hr)) {
      printf("Failed to compile Vertex Shader");
      exit(666);
    }

    auto pDev = static_cast<ID3D11Device*>(pDevice);
    hr = pDev->CreatePixelShader(m_d3dBlob->GetBufferPointer(),
                                 m_d3dBlob->GetBufferSize(),
                                 nullptr,
                                 &m_pPixelShader);
    if (FAILED(hr)) {
      printf("Failed to create Pixel Shader");
      exit(666);
    }

  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauGeometryShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauComputeShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }

  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  void
  nauTextureShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }
}