/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauShaderDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief DirectX shader implementation of base class core Shader
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"
#include <nauShader.h>

namespace nauEngineSDK {

  class nauShaderDX : public nauShader
  {
  public:

    /**
     * Default constructor
     */
    nauShaderDX() = default;

    /**
     * Default destructor
     */
    ~nauShaderDX() {};

    /**
     * @brief sets the shader to the device context
     * @param
     * @return
     *
     */
    virtual void
    setShader() = 0;

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual bool
    compile() = 0;

   public:

    /**
     * DirectX blob resource
     */
    ID3DBlob* m_d3dBlob = nullptr;

    /**
     * ImmediateDevice Pointer
     */
    ID3D11DeviceContext* pImmediateDevice = nullptr;

  };
  

  class nauVertexShaderDX : public nauShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    nauVertexShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauVertexShaderDX() {};

    /**
     * @brief sets the shader to the device context
     * @param
     * @return
     *
     */
    void
    setShader() = 0;

    /**
     * @brief
     * @param
     * @return
     *
     */
    bool
    compile() = 0;

    
  };

  class nauPixelShaderDX : public nauShaderDX
  {
   public:
    /**
     * Default Constructor
     */
     nauPixelShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauPixelShaderDX() {};

    /**
     * @brief sets the shader to the device context
     * @param
     * @return
     *
     */
    void
    setShader() = 0;

    /**
     * @brief
     * @param
     * @return
     *
     */
    bool
    compile() = 0;

  };

  class nauComputeShaderDX : public nauShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    nauComputeShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauComputeShaderDX() {};

    /**
     * @brief sets the shader to the device context
     * @param
     * @return
     *
     */
    void
    setShader() = 0;

    /**
     * @brief
     * @param
     * @return
     *
     */
    bool
    compile() = 0;

  };

  class nauGeometryShaderDX : public nauShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    nauGeometryShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauGeometryShaderDX() {};

    /**
     * @brief sets the shader to the device context
     * @param
     * @return
     *
     */
    void
    setShader() = 0;

    /**
     * @brief
     * @param
     * @return
     *
     */
    bool
    compile() = 0;
  };

  class nauTextureShaderDX : public nauShaderDX
  {
   public:
    /**
     * Default Constructor
     */
    nauTextureShaderDX() = default;

    /**
     * Default Constructor
     */
    ~nauTextureShaderDX() {};

    /**
     * @brief sets the shader to the device context
     * @param
     * @return
     *
     */
    void
    setShader() = 0;

    /**
     * @brief
     * @param
     * @return
     *
     */
    bool
    compile() = 0;
  };

}
