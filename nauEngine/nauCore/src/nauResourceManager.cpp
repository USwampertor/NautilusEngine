/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauResourceManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/05/26 2019
 * @brief Resource manager member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauResourceManager.h"

namespace nauEngineSDK {

  void
  ResourceManager::init(Device* pDevice) {
    m_pDevice = pDevice;
  }

  Sptr<Resource*>
  ResourceManager::load(String path) {

    Sptr<Resource*> resource = std::make_shared<Resource*>();

    if (!canDecode(path)) {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE(" object at path: " + path + " is not a valid format");
      return nullptr;
#endif
    }

    return resource;
  }

  void
  ResourceManager::flush() {

  }

  bool 
  ResourceManager::canDecode(String path) {

    return true;
  }





}