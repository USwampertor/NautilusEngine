/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauRasterizerState.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauDevice.h"

namespace nauEngineSDK {

   /**
    * nauRasterizerState
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class RasterizerState
  {
  public:

    /**
     * default constructor
     */
    RasterizerState() = default;

    /**
     * Virtual destructor
     */
    virtual ~RasterizerState() = default;

    /**
     * @brief Creates a rasterizer state to 
     * @param 
     * @return 
     *
     */
    virtual bool
    createRasterizerState(Device* pDevice) = 0;

  };
  
}

