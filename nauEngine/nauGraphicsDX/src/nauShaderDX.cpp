/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauShaderDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X implementation of all shader member declaration
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauShaderDX.h"
#include "nauDeviceDX.h"


namespace nauEngineSDK {

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
  ShaderDX::compile(String filename, 
                       String entryPoint, 
                       String profile, 
                       uint32 FLAGS) {
    
    HRESULT result = E_FAIL;
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

#ifdef NAU_DEBUG_MODE
    FLAGS |= D3DCOMPILE_DEBUG;
#endif

    result = D3DCompile(shadersource.c_str(), shadersource.size(), filename.c_str(), 0, 0, entryPoint.c_str(), profile.c_str(), FLAGS, 0, &m_d3dBlob, &error);
    if (error)
    {
      //throw::std::exception("Error at getting buffer");
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


/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Vertex shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  VertexShaderDX::createFromFile(void* pDevice, 
                                 const char* fileName, 
                                 const char* entryPoint) {
    char dirPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, dirPath);
    String folderPath(dirPath);
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

  void
  VertexShaderDX::set(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->VSSetShader(m_pVertexShader, 0, 0);
  }

  void*
  VertexShaderDX::getShader() {
    return m_pVertexShader;
  }
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Pixel shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  PixelShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
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

  void
  PixelShaderDX::set(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->PSSetShader(m_pPixelShader, 0, 0);
  }

  void*
  PixelShaderDX::getShader() {
    return m_pPixelShader;
  }
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  GeometryShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }

  void
  GeometryShaderDX::set(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
  }

  void*
  GeometryShaderDX::getShader() {
    return m_pGeometryShader;
  }
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  ComputeShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }

  void
  ComputeShaderDX::set(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
  }

  void*
  ComputeShaderDX::getShader() {
    return m_pComputeShader;
  }

  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
 /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  TextureShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }

  void
  TextureShaderDX::set(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
  }

  void*
  TextureShaderDX::getShader() {
    return nullptr;
  }
}