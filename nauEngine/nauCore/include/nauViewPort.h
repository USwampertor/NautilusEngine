/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauViewPort.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief View port class for visualization of screen
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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
  class NAU_CORE_EXPORT nauViewPort
  {
   public:
    /**
     * Default constructor
     */
    nauViewPort() = default;

    /**
     * virtual destructor
     */
    virtual ~nauViewPort() {}

    /**
     * @brief Creates a viewPort
     * @param 
     * @return 
     *
     */
    virtual bool
    createViewPort(float width, float height, float topLeftX, float topLeftY) = 0;

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
