/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauResourceManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/05/26 2019
 * @brief Resource manager member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauResourceManager.h"

namespace nauEngineSDK {

  void
  ResourceManager::init(Device* pDevice) {
    m_pDevice = pDevice;
  }

  Sptr<Resource>
  ResourceManager::load(String path) {

    Sptr<Resource> resource = std::make_shared<Resource>();



    return resource;
  }

  void
  ResourceManager::flush() {

  }

  bool 
  ResourceManager::canDecode() {



    return true;
  }





}