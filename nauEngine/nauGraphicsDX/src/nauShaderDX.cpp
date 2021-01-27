/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauShaderDX.cpp
 * @author Marco "Swampy" Millán
 * @date 2018/10/31 2018
 * @brief Direct X implementation of all shader member declaration
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauShaderDX.h"
#include "nauDeviceDX.h"


namespace nauEngineSDK {

/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * nauShaderDX.cpp Shader member declaration
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

  bool
  ShaderDX::compile(String filename, 
                       String entryPoint, 
                       String profile, 
                       uint32 FLAGS) {
    
    HRESULT result = E_FAIL;
    ID3DBlob* error = nullptr;

    //TODO: Change this for the FileStream
    std::ifstream file(filename.c_str());
    file.open(filename.c_str());

    if (!file.is_open()) {
      //File was not found or could not be opened
      String errorString = "";
      errorString += "Shader file could not be found...";
      errorString += filename;
      Logger::instance().toIDE(errorString, LOGGER_LEVEL::ERRORED);
      //Should try to load a default shader in any case

      //Logger::instance().toIDE("Attempting to load default shader", LOGGER_LEVEL::ERRORED);

      result = S_FALSE;
      return false;

    }
    
    String shadersource;
    shadersource = { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
    
    file.close();

    //Debug options
#ifdef NAU_DEBUG_MODE
    FLAGS |= D3DCOMPILE_DEBUG;
#endif

    //Compiles the Shader
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
      
      String errorString = "";
      errorString += "Error at compiling Shader with name ";
      errorString += filename;
      errorString += " due to the following errors: ";
      errorString += static_cast<char*>(error->GetBufferPointer());
      errorString += ". HRESULT returned FAILED with code: ";
      errorString += std::to_string(static_cast<uint32>(HRESULT_CODE(result)));

      Logger::instance().toIDE(errorString, LOGGER_LEVEL::ERRORED);
      
      if (error != nullptr) {
        error->Release();
      }
      
      Logger::instance().toIDE("The application exited with error 665. For further information, read Documentation->Errors",LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      
      exit(655);
      return false;
    }

    return true;
  }

  void*
  ShaderDX::getData() {
    return m_d3dBlob;
  }


/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * nauShaderDX.cpp Vertex shader member declaration
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
  
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
    //NAU_ASSERT(m_d3dBlob == nullptr && "Vertex Shader blob is NULL");

    if (!ShaderDX::compile(fileName, entryPoint, "vs_5_0", D3DCOMPILE_ENABLE_STRICTNESS)) {
      Logger::instance().toIDE("The application exited with error 666. For further information, read Documentation->Errors", LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(666);
    }

    auto pDev = static_cast<ID3D11Device*>(pDevice);
    hr = pDev->CreateVertexShader(m_d3dBlob->GetBufferPointer(),
                                  m_d3dBlob->GetBufferSize(),
                                  nullptr,
                                  &m_pVertexShader);
    if (FAILED(hr)) {

      String errorString = "";
      errorString += "Error at trying to create Vertex Shader with name ";
      errorString += fileName;
      errorString += ". HRESULT returned FAILED with code: ";
      errorString += std::to_string(static_cast<uint32>(HRESULT_CODE(hr)));
      
      Logger::instance().toIDE(errorString, LOGGER_LEVEL::ERRORED);

      Logger::instance().toIDE("The application exited with error 667. For further information, read Documentation->Errors", LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(667);
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
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * nauShaderDX.cpp Pixel shader member declaration
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
  
  bool
  PixelShaderDX::init(Device* pDevice) {
    return true;
  }
  
  void
  PixelShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = E_FAIL;
    //NAU_ASSERT(m_d3dBlob != nullptr && "Pixel Shader blob is NULL");

    if (!ShaderDX::compile(fileName, entryPoint, "ps_5_0", D3DCOMPILE_ENABLE_STRICTNESS)) {
      Logger::instance().toIDE("The application exited with error 666. For further information, read Documentation->Errors", LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(676);
    }

    auto pDev = static_cast<ID3D11Device*>(pDevice);
    hr = pDev->CreatePixelShader(m_d3dBlob->GetBufferPointer(),
                                 m_d3dBlob->GetBufferSize(),
                                 nullptr,
                                 &m_pPixelShader);
    if (FAILED(hr)) {
      String errorString = "";
      errorString += "Error at trying to create Pixel Shader with name ";
      errorString += fileName;
      errorString += ". HRESULT returned FAILED with code: ";
      errorString += std::to_string(static_cast<uint32>(HRESULT_CODE(hr)));

      Logger::instance().toIDE(errorString, LOGGER_LEVEL::ERRORED);

      Logger::instance().toIDE("The application exited with error 667. For further information, read Documentation->Errors", LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(677);
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
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
  
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
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
  
  bool
  ComputeShaderDX::init(Device* pDevice) {
    auto pd3dDevice = (pDevice->get());
    Vector<cl::Platform> allPlatforms;
    Vector<cl::Platform> availablePlatforms;
    Vector<cl_device_id> allDevices;
    Vector<cl::Device> availableDevices;
    String platformName;
    String platformProfile;
    String sharingInfo;

    cl::Platform::get(&allPlatforms);
    if (allPlatforms.size() == 0) {
      //std::cout << "No platforms found. \n";
      //throw::std::exception("No support in this machine for Open CL");

      String errorString = "";
      errorString += "Error trying to initialize Compute Shader.";
      errorString += " No support in this machine for Open CL computing ";

      Logger::instance().toIDE(errorString, LOGGER_LEVEL::ERRORED);

    }

    for (auto platform : allPlatforms) {
      platformName = platform.getInfo<CL_PLATFORM_NAME>();
      platformProfile = platform.getInfo<CL_PLATFORM_PROFILE>();
      sharingInfo = platform.getInfo<CL_PLATFORM_EXTENSIONS>();
      size_t found = sharingInfo.find("cl_khr_d3d11_sharing");
      if (found != String::npos) { 
        printf("Available Platform for CL shader"); 
        availablePlatforms.push_back(platform);
      } 
    }

    if (availablePlatforms.empty()) {
      throw::std::exception("No available platform for d3d11 sharing with cl");
    }

    uint32 devices = 0;
    cl_int result = 0;
    bool possibleToShare = false;

    for (auto platform : availablePlatforms) {
      platformName = platform.getInfo<CL_PLATFORM_NAME>();
      platformProfile = platform.getInfo<CL_PLATFORM_PROFILE>();
      sharingInfo = platform.getInfo<CL_PLATFORM_EXTENSIONS>();
      clGetDeviceIDsFromD3D11KHR_fn retriever = nullptr;

      cl_context_properties properties[] = {
        CL_CONTEXT_PLATFORM, reinterpret_cast<cl_context_properties>(platform()),
        CL_CONTEXT_D3D11_DEVICE_KHR, reinterpret_cast<intptr_t>(pd3dDevice),
        CL_CONTEXT_INTEROP_USER_SYNC, CL_FALSE,
        0
      };
      
      retriever = reinterpret_cast<clGetDeviceIDsFromD3D11KHR_fn>(
        clGetExtensionFunctionAddressForPlatform(platform(),
                                                 "clGetDeviceIDsFromD3D11KHR"));
      result = retriever(platform(),
                         CL_D3D11_DEVICE_KHR, 
                         pd3dDevice,
                         CL_PREFERRED_DEVICES_FOR_D3D11_KHR,
                         0,
                         nullptr,
                         &devices);



      if (CL_SUCCESS == result) {
        //We found that the platform can host sharing devices
        allDevices.clear();
        allDevices.reserve(devices);
        retriever(platform(),
                  CL_D3D11_DEVICE_KHR,
                  pd3dDevice,
                  CL_PREFERRED_DEVICES_FOR_D3D11_KHR,
                  devices,
                  &allDevices[0],
                  nullptr);
        if (CL_SUCCESS == result) {
          //We found a series of available devices that can be used
          for (auto devs : allDevices) {
            
            m_defaultContext = cl::Context({ m_defaultDevice },
                                           properties,
                                           nullptr,
                                           nullptr,
                                           &result);
            if (CL_SUCCESS == result) {
              //We made a context, found a device and a platform available to share
              m_defaultPlatform = platform;
              m_defaultDevice = devs;
              possibleToShare = true;
              break;
            }
          }
        }
      }
    }

    if (!possibleToShare) {
      throw::std::exception("IMPOSSIBLE TO SHARE BETWEEN CL AND D3D11");
    }

    std::cout << "using platform: "
              << m_defaultPlatform.getInfo<CL_PLATFORM_NAME>()
              << std::endl;
    std::cout << "using device: "
              << m_defaultDevice.getInfo<CL_DEVICE_NAME>()
              << std::endl;
    std::cout << "using context: "
              << m_defaultContext.getInfo<CL_CONTEXT_PROPERTIES>()[0]
              << std::endl;

    m_commandQueue = cl::CommandQueue(m_defaultContext, m_defaultDevice);
    
    return true;
  }
  
  void
  ComputeShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    char dirPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, dirPath);
    String folderPath(dirPath);
    HRESULT hr = E_FAIL;
    hr = ShaderDX::compile(fileName, entryPoint, "cs_5_0", D3DCOMPILE_ENABLE_STRICTNESS);
    NAU_ASSERT(m_d3dBlob != nullptr && "Compute Shader blob is NULL");
    if (FAILED(hr)) {
      printf("Failed to compile Compute Shader");
      exit(666);
    }
    auto pDev = static_cast<ID3D11Device*>(pDevice);
    hr = pDev->CreateComputeShader(m_d3dBlob->GetBufferPointer(),
      m_d3dBlob->GetBufferSize(),
      nullptr,
      &m_pComputeShader);
    if (FAILED(hr)) {
      printf("Failed to create Compute Shader");
      exit(666);
    }

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

  /*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * nauShaderDX.cpp Geometry shader member declaration
 */
 /*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
  
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