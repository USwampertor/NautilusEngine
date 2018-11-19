/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauViewPort.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief View port class for visualization of screen
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
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
  class nauViewPort
  {
   public:
    /**
     * Default constructor
     */
    nauViewPort() = default;

    /**
     * virtual destructor
     */
    virtual ~nauViewPort() {};

    /**
     * @brief Creates a viewPort
     * @param 
     * @return 
     *
     */
    virtual bool
    createViewPort(float width, float height, float topLeftX, float topLeftY);

    virtual void
    setViewPort(void* context);

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
