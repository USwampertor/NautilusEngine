#include "nauDLLoader.h"

namespace nauEngineSDK {

  void
  DLLoader::init() {
    Logger::instance().toIDE("Initializing DLLoader module...");
  }


  typedef void* (*G_FACTORY)();
  
  void*
  DLLoader::load(String path, String functionName) {

    std::wstring version = L"";
    std::wstring folderPath = L"";
    std::wstring p(path.begin(), path.end());

    String logger = "";
#ifdef NAU_ARCH_TYPE == NAU_ARCHITECTURE_x86_32
    version = L"x86";
#else
    version = L"x64";
#endif // NAU_ARCH_TYPE

#if NAU_DEBUG_MODE
    p.append(L"d");
#endif // NAU_DEBUG_MODE

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
    p.append(L".dll");


    wchar_t dirPath[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, dirPath);
    folderPath.append(dirPath);
    folderPath = folderPath.append(L"\\").append(version).append(L"\\").append(p);
    
    std::wstring str(folderPath.begin(), folderPath.end());
    HINSTANCE myDll = LoadLibraryExW(p.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!myDll) {
      DWORD err = GetLastError();
      
      char dir[MAX_PATH];
      GetCurrentDirectoryA(MAX_PATH, dir);

      logger = "Could not find library at given path: ";
      logger += dir;
      logger += " with given name: ";
      logger += path;
      logger += " and errors: ";
      logger += std::to_string(err);

      Logger::instance().toIDE(logger, LOGGER_LEVEL::ERRORED);

      return nullptr;
    }

    logger = "";
    logger += "Loading DLL: ";
    logger += path;

    Logger::instance().toIDE(logger);

    G_FACTORY t_api = (G_FACTORY)GetProcAddress(myDll, functionName.c_str());
    if (!t_api) {

      logger = "";
      logger = "Could not find specified function with name: ";
      logger += functionName;
      logger += " at library: ";
      logger += path;

      Logger::instance().toIDE(logger, LOGGER_LEVEL::ERRORED);

      logger = "";
      logger = "Releasing library...";

      Logger::instance().toIDE(logger);

      FreeLibrary(myDll);
      return nullptr;
    }

    Logger::instance().toIDE("Loaded library...");

#elif NAU_PLATFORM == NAU_PLATFORM_LINUX
    path.append(".so");
#else
    Logger::instance().toIDE("PLATFORM NOT SUPPORTED", LOGGER_LEVEL::ERRORED);
#endif


    return t_api();
  }
}