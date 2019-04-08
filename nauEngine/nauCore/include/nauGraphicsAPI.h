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

#include <nauModule.h>
#include <nauVector2.h>

#include "nauDevice.h"

namespace nauEngineSDK {
 

   /**
    * nauGraphics
    * Description:
    * 	the Graphics Interface for the engine
    * Sample usage:
    * 	You cast any of the dynamic libraries with this so it can be used
    */
  class GraphicsAPI : public Module<GraphicsAPI>
  {
   public:
    
    /**
     * default constructor
     */
    GraphicsAPI() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~GraphicsAPI() = default;

    /**
     * Initializes the basic stuff for the renderer to work
     */
    virtual bool
    init(void* scrHandler) = 0;

    /**
     * @brief initializes the device of the API
     * @param normally you would put a window handler
     * @return true if the initialization went all right
     *
     */
    virtual bool 
    initDevice(void* scrHandler) = 0;


    /**
     * @brief exposes the device and returns it
     * @param 
     * @return the device
     *
     */
    virtual Device*
    getDevice() = 0;

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual void 
    render() = 0;
    
    /**
     * @brief presents the Swap chain and swaps it
     * @param 
     * @return 
     *
     */
    virtual void
    swapBuffer() = 0;


    /**
     * @brief clears the information retrieved
     * @param 
     * @return 
     *
     */
    virtual void
    clear() = 0;

    virtual Vector2
    getWindowSize() = 0;

    virtual void
    onStartUp() override {
      this->isStartedUp() = true;
    }
  };
  
  extern NAU_CORE_EXPORT GraphicsAPI*
  g_graphicsAPI;

}


