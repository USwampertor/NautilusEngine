/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauViewPort.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief View port class for visualization of screen
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

   /**
    * nauViewPort
    * Description:
    * 	View port for API
    * Sample usage:
    * 	
    */
  class ViewPort
  {
   public:
    /**
     * Default constructor
     */
    ViewPort() = default;

    /**
     * virtual destructor
     */
    virtual ~ViewPort() = default;

    /**
     * @brief Creates a viewPort
     * @param 
     * @return 
     *
     */
    virtual bool
    createViewPort(float width, float height, float topLeftX, float topLeftY) = 0;

    /**
     * @brief Sets the viewPort to the device
     * @param the deviceContext
     * @return
     *
     */
    virtual void
    setViewPort(void* context) = 0;

    /**
     * Member declaration
     */
   public:

    /**
     * Depth of the min viewPort
     */
    float m_minDepth;

    /**
     * Depth of the max viewPort
     */
    float m_maxDepth;

  };  
}
