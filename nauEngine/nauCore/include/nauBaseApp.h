/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBaseApp.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/29 2018
 * @brief Base Application with core implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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
  class NAU_CORE_EXPORT BaseApp
  {
   public:
    
     /**
     * default constructor
     */
    BaseApp() = default;

    /**
     * virtual destructor
     */
    virtual 
    ~BaseApp() {};

    virtual void
    start() = 0;

    virtual void
    render() = 0;

    virtual void
    initApp() = 0;

    virtual void
    shutDown() = 0;

    virtual void
    close() = 0;


  };
}


