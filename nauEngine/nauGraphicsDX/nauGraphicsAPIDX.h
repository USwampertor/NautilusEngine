/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsAPIDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesDX.h"

#include <nauGraphicsAPI.h>

namespace nauEngineSDK {

  /**
   * nauGraphics
   * Description:
   * 	the DirectX implemented base core Graphics API class
   * Sample usage:
   * 	You use all the objects in a DirectX context
   */
  class NAU_DIRECTX_EXPORT nauGraphicsAPIDX : public nauGraphicsAPI
  {
   public:

    /**
     * Default Constructor
     */
    nauGraphicsAPIDX() = default;

    /**
     * default destructor
     */
    ~nauGraphicsAPIDX() {}

    /**
     * @brief initializes the device of the API
     * @param normally you would put a window handler
     * @return true if the initialization went all right
     *
     */
    bool
    initDevice(void* scrHandler) = 0;

    /**
     * @brief
     * @param
     * @return
     *
     */
    void
    onRender() = 0;

    /**
     * @brief gets the info of the shaders and sets the API
     * @param
     * @return
     *
     */
    void
    setShaders() = 0;

  };
  
}

