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

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  
   /**
    * nauShader
    * Description:
    * 	Shader parent class for Vertex and Pixel
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT Shader
  {
   public:
    
    /**
     * Default constructor of shader
     */
    Shader() = default;

    /**
     * Virtual destructor for child management
     */
    virtual ~Shader() {};

    /**
     * @brief Compiles a shader resource with the info showed
     * @param string filename the path or nae of the file
     *        string entry point, basically the name of the main
     *        profile of object
     *        FLAGS for any other information getting of the compiler of the shader
     * @return 
     *
     */
    virtual bool
    compile(String filename, String entryPoint, String profile, uint32 FLAGS) = 0;

    /**
     * @brief returns an object with the info of the shader, normally is a BLOB
     * @param 
     * @return the BLOB or the data container
     *
     */
    virtual void*
    getData() = 0;

    /**
     * @brief Creates a shader from specific File with a specific encoding
     * @param void* Device is the device in charge of the shader,
     *        filename of the shader
     *        const char entry point of the file
     * @return
     *
     */
    virtual void
    createFromFile(void* pDevice, const char* fileName, const char* entryPoint) = 0;

  };

  class NAU_CORE_EXPORT nauVertexShader   : public Shader
  {
   public:

    /**
     * Default constructor
     */
    nauVertexShader() = default;

    /**
     * virtual destructor
     */
    virtual
    ~nauVertexShader() {};

  };

  class NAU_CORE_EXPORT nauPixelShader    : public Shader
  {
   public:

    /**
     * Default constructor
     */
     nauPixelShader() = default;

    /**
     * virtual destructor
     */
    virtual
    ~nauPixelShader() {};
  };

  class NAU_CORE_EXPORT nauComputeShader  : public Shader
  {
   public:

    /**
     * Default constructor
     */
     nauComputeShader() = default;

    /**
     * virtual destructor
     */
    virtual
    ~nauComputeShader() {};
  };

  class NAU_CORE_EXPORT nauGeometryShader : public Shader
  {
   public:

    /**
     * Default constructor
     */
     nauGeometryShader() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~nauGeometryShader() {};
  };
  
  class NAU_CORE_EXPORT nauTextureShader  : public Shader
  {
   public:

    /**
     * Default constructor
     */
     nauTextureShader() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~nauTextureShader() {};
  };

}
