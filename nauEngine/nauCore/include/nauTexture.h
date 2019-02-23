/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTexture.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief a color and brightness information class
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

  /**
   * nauTexture
   * Description:
   *  
   * Sample usage:
   *
   */
  class NAU_CORE_EXPORT Texture
  {
  public:

    /**
     * default constructor
     */
    Texture() = default;

    /**
     * default destructor
     */
    ~Texture() {}

    /**
     * @brief Loads a resource from a path
     * @param string path of the file, device and device context
     * @return 
     *
     */
    virtual bool
    loadFromFile(String path, void* pDevice, void* pDeviceContext) = 0;

//////////THIS SHOULD BE ON A SEPARATE OBJECT, BUT BEAR WITH ME FOR A MOMENT

    /**
     * @brief creates a shader resource view
     * @param the device
     * @return true if able to create
     *
     */
    virtual bool
    createShaderResourceView(void* pDevice) = 0;

    /**
     * @brief sets the shader resource view in the device
     * @param 
     * @return 
     *
     */
    virtual void
    setShaderResourceView(void* pDevice) = 0;

    /**
     * @brief creates a render target view
     * @param Device and swapChain
     * @return true if able to create
     *
     */
    virtual bool
    createRenderTargetView(void* pDevice, void* swapChain) = 0;

    /**
     * @brief creates a depth stencil view descriptor
     * @param Device and device context
     * @return true if able to create
     *
     */
    virtual bool
    createDepthStencilView(void* pDevice, void* pDeviceContext) = 0;

    /**
     * @brief creates a depth stencil (which is a texture)
     * @param Device | Device Context | width of texture | height of texture
     * @return true if able to create
     *
     */
    virtual bool 
    createDepthstencil(void* pDevice,
                       void* pDeviceContext,
                       uint32 width,
                       uint32 height) = 0;

    /**
     * @brief creates the shader sampler
     * @param Device
     * @return true if able to create
     *
     */
    virtual bool
    createShaderSampler(void* pDevice) = 0;

    /**
     * @brief sets the shader sampler
     * @param Device
     * @return true if able to create
     *
     */
    virtual bool
    setShaderSampler(void* pDevice) = 0;

//////////END OF THE ABERRATION

    /**
     * Member declaration
     */
   public:

    /**
     * width of the texture
     */
    uint32 m_width;

    /**
     * width of the texture
     */
    uint32 m_height;

    /**
     * Texture data in bytes
     */
    std::vector<char> m_textureData;

  };
  
}
