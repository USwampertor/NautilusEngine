/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauShader.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/20 2018
 * @brief Shader base class and children 
 * Vertex Pixel Geometry Compute and Texture shader children class
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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


