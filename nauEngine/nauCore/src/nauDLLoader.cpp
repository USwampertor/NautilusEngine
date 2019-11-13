#include "nauDLLoader.h"

namespace nauEngineSDK {

  void
  DLLoader::init() {
    Logger::instance().toIDE("Initializing DLLoader module...");
  }


  typedef void* (*G_FACTORY)();
  
  void*
  DLLoader::load(String path, String functionName) {

    String version = "";
    String folderPath = "";
    String logger = "";
#ifdef NAU_ARCH_TYPE == NAU_ARCHITECTURE_x86_32
    version = "x86";
#else
    version = "x64";
#endif // NAU_ARCH_TYPE

#if NAU_DEBUG_MODE
    path.append("d");
#endif // NAU_DEBUG_MODE

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
    path.append(".dll");


    char dirPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, dirPath);
    folderPath.append(dirPath);
    folderPath = folderPath.append("\\").append(version).append("\\").append(path);
    
    HINSTANCE myDll = LoadLibraryExA(folderPath.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!myDll) {
      DWORD err = GetLastError();

      logger = "Could not find library at given path: ";
      logger += dirPath;
      logger += " with given name: ";
      logger += path;
      logger += err;

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