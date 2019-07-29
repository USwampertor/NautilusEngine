#include "nauDynamicLibrary.h"

namespace nauEngineSDK {

  typedef void* (*PLUGIN_FUNCTION)();
  void*
  DynamicLibrary::LoadLibrary(String path, String functionName) {
    PLUGIN_FUNCTION t_api;

#if NAU_PLATFORM == NAU_PLATFORM_WIN32 
    char dirPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, dirPath);
    String folderPath(dirPath);
    folderPath = folderPath.append("\\").append(path);

    HINSTANCE myDll = LoadLibraryExA(folderPath.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!myDll) {
      DWORD err = GetLastError();
      std::cout << "Could not find dll at given path: " << path << std::endl;
      std::cout << err << std::endl;
      std::cout << "Press any key to continue...";
      return nullptr;
    }
    std::cout << "Loading " << path << "..." << std::endl;

    t_api = (PLUGIN_FUNCTION)GetProcAddress(myDll, functionName.c_str());
    if (!t_api) {

      NAU_ASSERT(t_api == nullptr && "NO PLUGIN WITH GIVEN NAME");

      FreeLibrary(myDll);
      return nullptr;
    }
#elif

#endif
    return t_api();
  }
}