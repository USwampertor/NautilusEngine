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


#include "nauTexture.h"
#include "nauModel.h"
#include "nauSkeleton.h"
#include "nauAnimator.h"
#include "nauMaterial.h"
#include "nauAnimation.h"


namespace nauEngineSDK {

  void
  ResourceManager::init(Device* pDevice) {
    m_pDevice = pDevice;
  }

  Sptr<Resource>
  ResourceManager::load(String path) {

    Sptr<Resource> resource;

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

  Sptr<Resource>
  ResourceManager::create(String name, RESOURCETYPE::E type) {
    Sptr<Resource> resource;
    uint32 lastDot;

    lastDot = name.find_last_of('.');
    String newExtension = name.substr(0, lastDot);
    
    if (RESOURCETYPE::SKELETON == type) {
      newExtension += ".skl";
      resource = std::static_pointer_cast<Resource>(std::make_shared<Skeleton>());
    }
    else if (RESOURCETYPE::AUDIO == type) {
      newExtension += ".aud";
    }
    else if (RESOURCETYPE::CUBEMAP == type) {

      newExtension += ".ddx";
    }
    else if (RESOURCETYPE::MATERIAL == type) {

      newExtension += ".mtl";
      resource = std::static_pointer_cast<Resource>(std::make_shared<Material>());
    }
    else if (RESOURCETYPE::MODEL == type) {

      newExtension += ".fbx";
    }
    else if (RESOURCETYPE::TEXTURE == type) {

      newExtension += ".png";
    }
    else if (RESOURCETYPE::ANIMATOR == type) {

      newExtension += ".atr";
      resource = std::static_pointer_cast<Resource>(std::make_shared<Animator>());
    }
    else if (RESOURCETYPE::ANIMATION == type) {
      newExtension += ".atn";
      resource = std::static_pointer_cast<Resource>(std::make_shared<Animation>());
    }
    m.insert(std::make_pair(name, resource));

    return resource;
  }

  bool 
  ResourceManager::canDecode(String path) {

    return true;
  }





}