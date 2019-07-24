/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauResourceManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/05/26 2019
 * @brief Resource Manager
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once
#include "nauLogger.h"
#include "nauModule.h"
#include "nauPrerequisitesCore.h"
#include "nauResource.h"
#include "nauGraphicsAPI.h"

namespace nauEngineSDK {
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauResourceManager.h forward declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

  class Texture;
  class Skeleton;
  class Model;



/**
 * ResourceManager
 * Description:
 *   The resource manager is in charge of saving and loading objects so 
 *   Memory and resources are not scattered and can be recycled
 * Sample usage:
 * 
 */
class NAU_CORE_EXPORT ResourceManager : public Module<ResourceManager>
{
public:

  /**
   * Default constructor
   */
  ResourceManager() = default;

  /**
   * Default destructor
   */
  ~ResourceManager() = default;

  /**
   * @brief Initializes the object
   * @param 
   * @return 
   *
   */
  void
  init(Device* pDevice);

  Sptr<Resource>
  load(String path);

  Sptr<Resource>
  create(String name, RESOURCETYPE::E type);

  void
  flush();

  bool
  canDecode(String path);

private:

  Map<String, Sptr<Resource>> m;

  Device* m_pDevice;
};
  
}

