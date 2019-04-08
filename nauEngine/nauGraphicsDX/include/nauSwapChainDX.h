/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSwapChainDX.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/08 2019
 * @brief Swap Chain DX 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesDX.h"

#include <nauSwapChain.h>

namespace nauEngineSDK {


  class SwapChainDX : public SwapChain
  {
  public:
    /**
     * Default constructor
     */
    SwapChainDX() = default;
    
    /**
     * Default destructor
     */
    ~SwapChainDX() = default;
  
    virtual void*
    get() override;
  
    virtual void
    getBackBuffer(Texture* ref) override;

   public:
    /**
     * DirectX object
     */
    IDXGISwapChain* m_pSwapChain = nullptr;
  };
  
}

