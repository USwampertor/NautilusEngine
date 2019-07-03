/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauResourceManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/05/26 2019
 * @brief Resource Manager
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauModule.h"
#include "nauPrerequisitesCore.h"
#include "nauResource.h"

namespace nauEngineSDK {
  
/**
 * ResourceManager
 * Description:
 *   The resource manager is in charge of saving and loading objects so 
 *   Memory and resources are not scattered and can be recycled
 * Sample usage:
 * 
 */
class ResourceManager : Module<ResourceManager>
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
  init();

  static Resource
  load(String path);

  static void
  flush();

  static bool
  canDecode();

  Map<String, Sptr<Resource>> m;

};
  
}

