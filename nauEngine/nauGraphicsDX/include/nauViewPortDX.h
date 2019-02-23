/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauViewPortDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/12/06 2018
 * @brief View port implemented in DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesDX.h"
#include <nauViewPort.h>

namespace nauEngineSDK {

   /**
    * nauViewPortDX
    * Description:
    * 	the viewport implemented in DirectX context
    * Sample usage:
    * 	
    */
  class NAU_DIRECTX_EXPORT ViewPortDX : public ViewPort
  {
  public:

    /**
     * Default constructor
     */
    ViewPortDX() = default;

    /**
     * Default destructor
     */
    ~ViewPortDX() {}

    bool
    createViewPort(float width, float height, float topLeftX, float topLeftY);

    void
    setViewPort(void* context);

  public:
    /**
     * The viewport in D3D11
     */
    D3D11_VIEWPORT m_d3dViewPort;

  };
  
}


