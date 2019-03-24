/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSwapChain.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesCore.h"

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
  };
  
}

