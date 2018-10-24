/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauShader.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/20 2018
 * @brief Shader base class and children 
 * Vertex Pixel Geometry Compute and Texture shader children class
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

namespace nauEngineSDK {
  
   /**
    * nauShader
    * Description:
    * 	Shader parent class for Vertex and Pixel
    * Sample usage:
    * 	
    */
  class nauShader
  {
   public:

    /**
     * Default constructor of shader
     */
    nauShader() = default;

    /**
     * Virtual destructor for child management
     */
    virtual ~nauShader() = 0;

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


  };

  class nauVertexShader   : public nauShader
  {
  };

  class nauPixelShader    : public nauShader
  {

  };

  class nauComputeShader  : public nauShader
  {

  };

  class nauGeometryShader : public nauShader
  {

  };
  
  class nauTextureShader  : public nauShader
  {

  };

}


