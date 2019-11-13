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

#include <nauCamera.h>
#include <nauGameObject.h>
#include <nauGraphicsAPI.h>
#include <nauLogger.h>
#include <nauMatrix4.h>
#include <nauMesh.h>

#include "nauDeviceDX.h"
#include "nauGraphicsBufferDX.h"
#include "nauInputLayoutDX.h"
#include "nauShaderDX.h"
#include "nauSamplerStateDX.h"
#include "nauTextureDX.h"
#include "nauViewPortDX.h"
#include "nauRenderTargetViewDX.h"
#include "nauDepthStencilDX.h"
#include "nauShaderResourceViewDX.h"

namespace nauEngineSDK {
  /**
   * nauGraphics
   * Description:
   * 	the DirectX implemented base core Graphics API class
   * Sample usage:
   * 	You use all the objects in a DirectX context
   */
  class GraphicsAPIDX : public GraphicsAPI
  {
   public:

    /**
     * Default Constructor
     */
    GraphicsAPIDX() = default;

    /**
     * default destructor
     */
    ~GraphicsAPIDX() = default;

    ///INITIALIZERS//


    virtual bool
    init(void* scrHandler) override;

    virtual bool
    initDevice(void* scrHandler) override;


    ///SETTERS///


    ///GETTERS///

    
    virtual Device*
    getDevice() override;

    ///GRAPHIC FUNCTIONS///

    /**
     * DEPRECATED: DO NOT USE
     */
    virtual void
    render() override;
   
    virtual void
    swapBuffer() override;

    /**
     * DEPRECATED: DO NOT USE
     */
    virtual void
    clear() override;

    virtual Vector2
    getWindowSize() override;

    virtual String
    getAPIName() override { return "DX11"; }

    virtual APITYPE::E
    getAPIType() override { return APITYPE::DX11; }

   public:

    /**
     * Device 
     */
    Device* m_device;

    /**
     * ViewPort
     */
    ViewPortDX m_viewPort;

  };


  MS_ALIGN(16)
  extern "C" NAU_DIRECTX_EXPORT GraphicsAPI*
  createPluginAPI() {
    return new GraphicsAPIDX();
  }
  GCC_ALIGN(16)
}
