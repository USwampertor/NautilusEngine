/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDevice.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include <nauPrerequisitesCore.h>

namespace nauEngineSDK {
   /**
    * nauDevice
    * Description:
    * 	The responsible for making the managing of the device to draw on screen
    * Sample usage:
    * 	
    */
  class nauDevice
  {
   public:
    /**
     * Default constructor
     */
    nauDevice() = default;

    /**
     * Virtual constructor
     */
    virtual ~nauDevice() = 0;

    /**
     * @brief initializes device with the handler given
     * @param 
     * @return 
     *
     */
    virtual bool 
    initializeDevice(void* scrHandler) = 0;

    /**
     * @brief renders
     * @param 
     * @return 
     *
     */
    virtual void
    onRender() = 0;

    /**
     * @brief creates a buffer of specific type
     * @param 
     * @return 
     *
     */
    virtual bool
    createBuffer() = 0;

    /**
     * @brief creates a depth stencil view
     * @param 
     * @return 
     *
     */
    virtual bool
    createDepthStencilView() = 0;

    /**
     * Member declaration
     */
   public:
    /**
     * the width of the window
     */
    uint32 m_width;

    /**
     * the height of the window
     */
    uint32 m_height;

  };
  
}

