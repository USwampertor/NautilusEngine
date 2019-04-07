/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCoreFactoryDX.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/29 2019
 * @brief Core Factory specific to DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesDX.h"

#include "nauDepthStencilDX.h"
#include "nauDeviceDX.h"
#include "nauGraphicsAPIDX.h"
#include "nauGraphicsBufferDX.h"
#include "nauInputLayoutDX.h"
#include "nauShaderDX.h"
#include "nauTextureDX.h"

#include <nauCoreFactory.h>

namespace nauEngineSDK {

  class CoreFactoryDX : public CoreFactory
  {
   public:

    /**
     * Default constructor
     */
     CoreFactoryDX() = default;

    /**
     * Default destructor
     */
    ~CoreFactoryDX() = default;

    virtual GraphicsAPI*
    createGraphicsAPI() override;

    virtual Device*
    createDevice() override;

    virtual Shader*
    createVertexShader() override;

    virtual Shader*
    createPixelShader() override;

    virtual Texture*
    createTexture() override;

    virtual InputLayout*
    createInputLayout() override;

    virtual SamplerState*
    createSamplerState() override;

    virtual ViewPort*
    createViewPort() override;

    virtual DepthStencil*
    createDepthStencil() override;

    virtual VertexBuffer*
    createVertexBuffer() override;

    virtual IndexBuffer*
    createIndexBuffer() override;

    virtual ConstantBuffer*
    createConstantBuffer() override;

  };
  
  MS_ALIGN(16)
  extern "C" NAU_DIRECTX_EXPORT CoreFactory*
  createFactory() {
  
    
    return new CoreFactoryDX();
  }
  GCC_ALIGN(16)
}


