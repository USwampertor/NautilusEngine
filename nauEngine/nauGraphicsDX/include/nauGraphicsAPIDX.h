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
#include <nauGameObject.h>
#include <nauMatrix4.h>

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

    ///INITIALIZERS//


    bool
    init(void* scrHandler);

    bool
    initDevice(void* scrHandler);


    ///SETTERS///

    
    void
    setShaders(void* pDeviceContext, void* pShader, SHADERFLAGS flags);



    ///GETTERS///

    
    Device*
    getDevice();

    ///GRAPHIC FUNCTIONS///

    void
    render();
   
    void
    swapBuffer();

   public:


    //TO DO: TAKE THIS SHITS OUT
    Matrix4 m_world;
    Camera m_camera;
    Matrix4 m_projection;
    //

    /**
     * Test GameObject
     */
    GameObject m_testModel;

    /**
     * Vertex Shader
     */
    VertexShaderDX m_vertexShader;

    /**
     * Pixel Shader
     */
    PixelShaderDX m_pixelShader;

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
    float m_screenNear = 0.01f;

    /**
     * Field of View
     */
    float m_fov = 0;

    ConstantBufferDX m_constantBuffer;

  };
 

  

}


MS_ALIGN(16)
extern "C" NAU_DIRECTX_EXPORT nauEngineSDK::GraphicsAPI* 
createGraphicsAPI() {
  return new nauEngineSDK::GraphicsAPIDX();
}
GCC_ALIGN(16)
