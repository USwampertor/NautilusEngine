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

    
    virtual void
    setShaders(void* pDeviceContext, void* pShader, SHADERFLAGS flags) override;


    ///GETTERS///

    
    virtual Device*
    getDevice() override;

    ///GRAPHIC FUNCTIONS///

    virtual void
    render() override;
   
    virtual void
    swapBuffer() override;

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
    Model m_meshList;

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
