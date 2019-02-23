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
#include <nauCamera.h>
#include <nauMesh.h>

#include "nauDeviceDX.h"
#include "nauGraphicsBufferDX.h"
#include "nauInputLayoutDX.h"
#include "nauModelDX.h"
#include "nauShaderDX.h"
#include "nauSamplerStateDX.h"
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
  class NAU_DIRECTX_EXPORT GraphicsAPIDX : public GraphicsAPI
  {
   public:

    /**
     * Default Constructor
     */
    GraphicsAPIDX() = default;

    /**
     * default destructor
     */
    ~GraphicsAPIDX() {}

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
     * @brief Sets the shaders
     * @param 
     * @return 
     *
     */
    void
    setShaders(void* pDeviceContext, void* pShader, SHADERFLAGS flags);

    /**
     * @brief This is just a test
     * @param 
     * @return 
     *
     */
    void
    test();

  public:


    //TO DO: TAKE THIS SHITS OUT
    DirectX::XMMATRIX m_world;
    DirectX::XMMATRIX m_view;
    DirectX::XMMATRIX m_projection;
    //

    /**
     * Vertex Shader
     */
    nauVertexShaderDX m_vertexShader;

    /**
     * Pixel Shader
     */
    nauPixelShaderDX m_pixelShader;

    /**
     * Input Layout
     */
    InputLayoutDX m_inputLayout;

    /**
     * Device 
     */
    DeviceDX m_device;

    /**
     * Texture of test object
     */
    TextureDX m_texture;

    /**
     * ViewPort
     */
    ViewPortDX m_viewPort;

    /**
     * MeshList
     */
    //Vector<nauMesh> m_meshList;
    ModelDX m_meshList;

    /**
     * Sampler state
     */
    SamplerStateDX m_samplerState;

    /**
     * Screen depth
     */
    float m_screenDepth = 1000.0f;

    /**
     * Screen near
     */
    float m_screenNear = 5.0f;

    /**
     * Field of View
     */
    float m_fov = 0;
  };
 

  

}
MS_ALIGN(16)
extern "C" NAU_DIRECTX_EXPORT nauEngineSDK::GraphicsAPI* 
createGraphicsAPI() {
  return new nauEngineSDK::GraphicsAPIDX();
}
GCC_ALIGN(16)
