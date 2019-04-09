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
#include "nauTexture.h"
#include "nauDevice.h"

namespace nauEngineSDK {
   /**
    * nauDepthStencil
    * Description:
    * 	Defines the merger how to perform the depth state, drawing or not a 
    * specific pixel
    * Sample usage:
    * 	depth enabled checks if it should render with depth
    */
  class DepthStencil
  {
   public:
    
    /**
     * default constructor
     */
    DepthStencil() = default;
    
    /**
     * virtual destructor
     */
    virtual ~DepthStencil() = default;

    /**
     * @brief creates a depth stencil descriptor
     * @param void* device and void* immediate context
     * @return true if able to construct
     *
     */
    virtual bool
    createDepthStencil(Device& pDevice, 
                       uint32 height, 
                       uint32 width) = 0;

    /**
     * @brief Cleans the Depths Stencil
     * @param 
     * @return 
     *
     */
    virtual void
    clearView(Device* pDevice) = 0;

    /**
     * Gets the depth stencil
     */
    virtual void*
    getView() = 0;

    /**
     * Creates the depth stencil view object
     */
    virtual bool
    createView(Device* pDevice) = 0;

    /**
     * Creates the depth stencil state Object
     */
    virtual bool
    createState(Device* pDevice) = 0;

    /**
     * Sets the Stencil State
     */
    virtual void
    setState(Device* pDevice) = 0;

    /**
     * Member declaration
     */
   public:

    /**
     * defines if it should render things based in a depth
     */
    bool m_depthEnable =  true;

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

    /**
     * Width of texture
     */
    uint32 m_size;

    /**
     * Height of texture
     */
    uint32 m_height;

  };
  
}

