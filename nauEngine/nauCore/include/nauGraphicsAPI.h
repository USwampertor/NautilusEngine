/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauGraphicsAPI.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief Base core Graphics API object for graphics interface
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once
#include "nauPrerequisitesCore.h"
#include <nauModule.h>

namespace nauEngineSDK {
  
  enum SHADERFLAGS {
    NONE = 0,
    PIXEL,
    VERTEX,
    COMPUTE,
    GEOMETRY,
    TEXTURE
  };

   /**
    * nauGraphics
    * Description:
    * 	the Graphics Interface for the engine
    * Sample usage:
    * 	You cast any of the dynamic libraries with this so it can be used
    */
  class NAU_CORE_EXPORT GraphicsAPI : public Module<GraphicsAPI>
  {
   public:
    
    /**
     * default constructor
     */
    GraphicsAPI() = default;
    
    /**
     * virtual destructor
     */
    virtual
    ~GraphicsAPI() {}

    /**
     * @brief initializes the device of the API
     * @param normally you would put a window handler
     * @return true if the initialization went all right
     *
     */
    virtual bool 
    initDevice(void* scrHandler) = 0;

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual void 
    onRender() = 0;

    /**
     * @brief gets the info of the shaders and sets the API
     * @param device Context | Shader (pixel vertex etc) | SHADERFLAGS
     * @return 
     *
     */
    virtual void 
    setShaders(void* pDeviceContext, void* pShader, SHADERFLAGS flags ) = 0;
  
    /**
     * Graphics test function, it can load a specific object
     */
    virtual void
    test() = 0;
  };
  
}


