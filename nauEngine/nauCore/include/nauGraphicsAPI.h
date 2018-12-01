/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsAPI.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief Base core Graphics API object for graphics interface
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  
   /**
    * nauGraphics
    * Description:
    * 	the Graphics Interface for the engine
    * Sample usage:
    * 	You cast any of the dynamic libraries with this so it can be used
    */
  class NAU_CORE_EXPORT nauGraphicsAPI
  {
   public:
    
    /**
     * default constructor
     */
    nauGraphicsAPI() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~nauGraphicsAPI() {};

    /**
     * @brief initializes the device of the API
     * @param normally you would put a window handler
     * @return true if the initialization went all right
     *
     */
    virtual bool 
    initDevice(void* scrHandler) = 0;

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual void 
    onRender() = 0;

    /**
     * @brief gets the info of the shaders and sets the API
     * @param 
     * @return 
     *
     */
    virtual void 
    setShaders() = 0;
  
  };
  
}


