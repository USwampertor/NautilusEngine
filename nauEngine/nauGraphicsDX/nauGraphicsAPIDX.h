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

#include <DirectXMath.h>

#include <nauGraphicsAPI.h>
#include <nauMesh.h>

#include "nauDeviceDX.h"
#include "nauInputLayoutDX.h"
#include "nauShaderDX.h"
#include "nauTextureDX.h"
#include "nauViewPortDX.h"


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
    initDevice(void* scrHandler);

    /**
     * @brief
     * @param
     * @return
     *
     */
    void
    onRender();

    /**
     * @brief gets the info of the shaders and sets the API
     * @param
     * @return
     *
     */
    void
    setShaders();

  public:


    //TO DO: TAKE THIS SHITS OUT
    DirectX::XMMATRIX m_world;
    DirectX::XMMATRIX m_view;
    DirectX::XMMATRIX m_projection;
    //

    /**
     * Vertex Shader
     */

  };
  
}

