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

  class NAU_CORE_EXPORT VertexShader   : public Shader
  {
   public:

    /**
     * Default constructor
     */
    VertexShader() = default;

    /**
     * virtual destructor
     */
    virtual
    ~VertexShader() {};

  };

  class NAU_CORE_EXPORT PixelShader    : public Shader
  {
   public:

    /**
     * Default constructor
     */
     PixelShader() = default;

    /**
     * virtual destructor
     */
    virtual
    ~PixelShader() {};
  };

  class NAU_CORE_EXPORT ComputeShader  : public Shader
  {
   public:

    /**
     * Default constructor
     */
     ComputeShader() = default;

    /**
     * virtual destructor
     */
    virtual
    ~ComputeShader() {};
  };

  class NAU_CORE_EXPORT GeometryShader : public Shader
  {
   public:

    /**
     * Default constructor
     */
     GeometryShader() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~GeometryShader() {};
  };
  
  class NAU_CORE_EXPORT TextureShader  : public Shader
  {
   public:

    /**
     * Default constructor
     */
     TextureShader() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~TextureShader() {};
  };

}
