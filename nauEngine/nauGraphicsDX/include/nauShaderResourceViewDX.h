/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauShaderResourceViewDX.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief shader resource view for rendering
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesDX.h"
#include "nauTextureDX.h"
#include "nauDeviceDX.h"

#include <nauShaderResourceView.h>

namespace nauEngineSDK {
  class ShaderResourceViewDX : public ShaderResourceView
  {
  public:
    /**
     * Default constructor
     */
    ShaderResourceViewDX() = default;

    /**
     * Default destructor
     */
    ~ShaderResourceViewDX() = default;

    virtual bool
    createShaderResourceView(Device* pDevice, void* texture, NAUTEXTUREDESCRIPTOR desc) override;

    /**
     * @brief Creates a shader resource view
     * @param void* device
     * @return
     *
     */
    virtual void
    setShaderResourceView(Device* pDevice, 
                          uint32 start = 0, 
                          uint32 views = 1) override;



    /**
     * Shader resource view of DirectX
     */
    ID3D11ShaderResourceView* m_shaderResourceView;

  };
}


