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
#include "nauDeviceDX.h"


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

    result = D3DCompile(shadersource.c_str(), 
                        shadersource.size(), 
                        filename.c_str(),
                        0, 
                        D3D_COMPILE_STANDARD_FILE_INCLUDE, 
                        entryPoint.c_str(), 
                        profile.c_str(), 
                        FLAGS, 
                        0, 
                        &m_d3dBlob, 
                        &error);
    if (FAILED(result)) {
      String errorString = static_cast<char*>(error->GetBufferPointer());
      std::cout << "Error at getting buffer" << errorString << std::endl;
      //throw::std::exception("Error at getting buffer");
      if (error != nullptr) {
        error->Release();
      }
      printf("Exiting with code 223. For further information, read error 223");
      exit(223);
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
  
  bool
  VertexShaderDX::init(Device* pDevice) {
    return true;
  }

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
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Pixel shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  
  bool
  PixelShaderDX::init(Device* pDevice) {
    return true;
  }
  
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
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  
  bool
  GeometryShaderDX::init(Device* pDevice) {
    return true;
  }
  
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
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  
  bool
  ComputeShaderDX::init(Device* pDevice) {
    auto pd3dDevice = reinterpret_cast<ID3D11DeviceContext*>(pDevice->get());
    Vector<cl::Platform> allPlatforms;
    Vector<cl::Platform> availablePlatforms;
    Vector<cl::Device> allDevices;
    Vector<cl::Device> availableDevices;

    cl::Platform::get(&allPlatforms);
    if (allPlatforms.size() == 0) {
      std::cout << "No platforms found. \n";
      throw::std::exception("No support in this machine for Open CL");
    }

    for (auto platform : allPlatforms) {
      String sharingInfo = platform.getInfo<CL_PLATFORM_EXTENSIONS>();

      size_t found = sharingInfo.find("cl_khr_d3d11_sharing");
      if (found != String::npos) { 
        printf("Available Platform for CL shader"); 
        availablePlatforms.push_back(platform);
      } 
    }

    if (availablePlatforms.empty()) {
      throw::std::exception("No available platform for d3d11 sharing with cl");
    }

    m_defaultPlatform = availablePlatforms[0];
    std::cout << "using platform: "
              << m_defaultPlatform.getInfo<CL_PLATFORM_NAME>()
              << std::endl;

    cl_context_properties properties[] = {
      CL_CONTEXT_PLATFORM, reinterpret_cast<cl_context_properties>(m_defaultPlatform()),
      CL_CONTEXT_D3D11_DEVICE_KHR, reinterpret_cast<intptr_t>(pd3dDevice),
      CL_CONTEXT_INTEROP_USER_SYNC, CL_FALSE,
      0
    };

    clGetDeviceIDsFromD3D11KHR_fn retriever = reinterpret_cast<clGetDeviceIDsFromD3D11KHR_fn>(
      clGetExtensionFunctionAddressForPlatform(m_defaultPlatform(), 
                                               "clGetDeviceIDsFromD3D11KHR"));

    uint32 devices = 0;
    uint32 result = retriever(m_defaultPlatform(),
                              CL_D3D11_DEVICE_KHR, 
                              reinterpret_cast<void*>(pd3dDevice),
                              CL_PREFERRED_DEVICES_FOR_D3D11_KHR,
                              0,
                              nullptr,
                              &devices);

    if (CL_SUCCESS != result) {
      throw::std::exception("Couldn't find a device suited for D3D11 sharing");
    }

    return true;
  }
  
  void
  ComputeShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }

  void
  ComputeShaderDX::set(Device* pDevice) {
    auto pd3dContext = reinterpret_cast<ID3D11DeviceContext*>(pDevice->getContext());
    pd3dContext->CSSetShader(m_pComputeShader, 0, 0);
  }

  void*
  ComputeShaderDX::getShader() {
    return m_pComputeShader;
  }

  /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
  
  bool
  TextureShaderDX::init(Device* pDevice) {
    return true;
  }

  
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