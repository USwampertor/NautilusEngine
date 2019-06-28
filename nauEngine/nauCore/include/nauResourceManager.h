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
  class ResourceManager
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

    Map<String, Resource> m;

  };
  
}

