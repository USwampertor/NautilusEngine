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
  class BaseApp
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
    ~BaseApp() = default;


    /**
     * Anything that should go before rendering and starting to get inputs but
     * after the initialization of basic components should go here
     */
    virtual void
    start() = 0;

    /**
     * @brief Render state of the base app, here it goes everything to render
     * @param 
     * @return 
     *
     */
    virtual void
    render() = 0;

    /**
     * @brief Should be used to initialize the basic components of the objects
     * @param First one should be the window handler
     * @return true if all objects were able to initialize, false if one or more didnt
     *
     */
    virtual bool
    initApp(void* hwnd) = 0;

    /**
     * @brief Should be used to end or shut down basic Components for the application
     * @param 
     * @return 
     *
     */
    virtual void
    shutDown() = 0;

    /**
     * Closes the application. Should be used to terminate one or more components
     * after shutting down
     */
    virtual void
    close() = 0;


  };
}


