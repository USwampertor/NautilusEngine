/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauBaseApp.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/29 2018
 * @brief Base Application with core implementation
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

   /**
    * nauBaseApp
    * Description:
    * 	base application for different implementation
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT nauBaseApp
  {
   public:
    
     /**
     * default constructor
     */
    nauBaseApp() = default;

    /**
     * virtual destructor
     */
    virtual ~nauBaseApp() {};
  };
}


