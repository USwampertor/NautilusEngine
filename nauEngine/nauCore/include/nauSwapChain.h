/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauSwapChain.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once
#include "nauPrerequisitesCore.h"

#include "nauTexture.h"

namespace nauEngineSDK {
  
   /**
    * nauSwapChain
    * Description:
    * 	Swaps the buffer with the backbuffer information. Its an encapsulation
    * Sample usage:
    * 	
    */
  class SwapChain
  {
  public:

    /**
     * default constructor
     */
    SwapChain() = default;

    /**
     * virtual destructor
     */
    virtual ~SwapChain() = default;

    /**
     * Returns the swapChain encapsulated in the class
     */
    virtual void*
    get() = 0;

    /**
     * Retrieves a texture based up on the backBuffer
     */
    virtual void
    getBackBuffer(Texture* ref) = 0;
  };
  
}

