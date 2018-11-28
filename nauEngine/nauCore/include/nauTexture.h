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
  class nauTexture
  {
  public:

    /**
     * default constructor
     */
    nauTexture() = default;

    /**
     * default destructor
     */
    ~nauTexture() {};

    /**
     * @brief Loads a resource from a path
     * @param string path of the file, device and device context
     * @return 
     *
     */
    virtual bool
    loadFromFile(String path, void* pDevice, void* pDeviceContext) = 0;

    /**
     * Member declaration
     */

    /**
     * width of the texture
     */
    uint32 m_width;

    /**
     * width of the texture
     */
    uint32 m_height;
  };
  
}
