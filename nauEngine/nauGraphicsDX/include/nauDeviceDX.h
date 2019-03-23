/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauDeviceDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X Device class
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauDevice.h>

namespace nauEngineSDK {
  class NAU_DIRECTX_EXPORT DeviceDX : public Device
  {
   public:
    /**
     * Default constructor
     */
    DeviceDX() = default;
    
    /**
     * Default destructor
     */
    ~DeviceDX() = default;
    
    bool 
    initializeDevice(void* scrHandler);
  
    void
    onRender();

    bool
    createBuffer();

    bool
    createDepthStencilView();

    ///GETTERS///

    void*
    get();

    void*
    getContext();

    ///EVENTS///



  public:

    /**
     * window handler
     */
    HWND m_handler;


    /**
     * DirectX device pointer
     */
    ID3D11Device* m_pd3dDevice = nullptr;

    /**
     * DirectX immediate context pointer
     */
    ID3D11DeviceContext* m_pImmediateContext = nullptr;

    /**
     * DirectX swap chain
     */
    IDXGISwapChain* m_pSwapChain = nullptr;


  };
  
}

