/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauGraphicsAPIDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#pragma once

#include "nauPrerequisitesDX.h"

#include <DirectXMath.h>

#include <nauGraphicsAPI.h>
#include <nauMesh.h>

#include "nauDeviceDX.h"
#include "nauGraphicsBufferDX.h"
#include "nauInputLayoutDX.h"
#include "nauModelDX.h"
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
    nauInputLayoutDX m_inputLayout;

    /**
     * Device 
     */
    nauDeviceDX m_device;

    /**
     * Texture of test object
     */
    nauTextureDX m_texture;

    /**
     * ViewPort
     */
    nauViewPortDX m_viewPort;

    /**
     * MeshList
     */
    //Vector<nauMesh> m_meshList;
    nauModelDX m_meshList;

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

extern "C" NAU_DIRECTX_EXPORT nauEngineSDK::nauGraphicsAPI* 
createGraphicsAPI() {
  return new nauEngineSDK::nauGraphicsAPIDX();
}