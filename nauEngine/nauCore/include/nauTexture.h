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
#include "nauDevice.h"
#include "nauShaderResourceView.h"

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
    ~Texture() = default;

    /**
     * @brief Initializes a texture as an empty object
     * @param Device object
     * @param int32 width of the texture
     * @param int32 height of the texture
     * @return true if able to create
     *
     */
    virtual bool
    init(Device* pDevice, int32 width, int32 height) = 0;

    /**
     * @brief Loads a resource from a path
     * @param string path of the file, device and device context
     * @return 
     *
     */
    virtual bool
    loadFromFile(String path, Device* pDevice) = 0;

    /**
     * @brief Load a Texture based on memory
     * @param device and the buffer with the information
     * @return true if able to create
     *
     */
    virtual bool
    loadFromMemory(Device* pDevice, Vector<char> buffer) = 0;

    /**
     * Gets the texture inside of it
     */
    virtual void*
    getAPITexture() = 0;

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
    Vector<char> m_textureData;

    /**
     * 
     */
    ShaderResourceView* m_shaderResourceView;
  };
  
}
