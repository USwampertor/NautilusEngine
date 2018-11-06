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


namespace nauEngineSDK {

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  bool
  nauShaderDX::compile(String filename, 
                       String entryPoint, 
                       String profile, 
                       uint32 FLAGS) {
    HRESULT result = S_OK;
    ID3DBlob* error = nullptr;
    std::ifstream file(filename);
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
  nauShaderDX::getData() {
    return m_d3dBlob;
  }



/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Vertex shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
  nauVertexShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;
    
  }

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauShaderDX.cpp Pixel shader member declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  void
    nauPixelShaderDX::createFromFile(void* pDevice, const char* fileName, const char* entryPoint) {
    HRESULT hr = S_OK;

  }
}