/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDepthStencilState.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief Depth stencil state and properties
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
   /**
    * nauDepthStencil
    * Description:
    * 	Defines the merger how to perform the depth state, drawing or not a 
    * specific pixel
    * Sample usage:
    * 	depth enabled checks if it should render with depth
    */
  class NAU_CORE_EXPORT nauDepthStencilState
  {
   public:
    
    /**
     * default constructor
     */
    nauDepthStencilState() = default;
    
    /**
     * virtual destructor
     */
    virtual ~nauDepthStencilState() {};

    /**
     * Member declaration
     */
   public:

    /**
     * defines if it should render things based in a depth
     */
    bool m_depthEnable;

    /**
     * Determines if the whole screen is drawing or not
     */
    bool m_stencilEnable;

    /**
     * Identifies a portion of the depth stencil buffer for reading data
     */
    uint8 m_stencilReadMask;

    /**
     * Identifies a portion of the depth stencil for writing stencil data
     */
    uint8 m_stencilWriteMask;




  };
  
}

