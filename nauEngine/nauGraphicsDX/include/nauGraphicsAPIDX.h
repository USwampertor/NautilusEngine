/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauGraphicsAPIDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesDX.h"

#include <DirectXMath.h>

#include <nauGraphicsAPI.h>
#include <nauCamera.h>
#include <nauMesh.h>
#include <nauGameObject.h>
#include <nauMatrix4.h>

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
 

  

}
