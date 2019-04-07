/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauGraphicPass.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/04 2019
 * @brief Graphics managment for passes. It stores a series of objects to be called
 *        up on passes
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauDepthStencil.h"
#include "nauGraphicsBuffer.h"
#include "nauInputLayout.h"
#include "nauTexture.h"

namespace nauEngineSDK {
   /**
    * GraphicsPass
    * Description:
    *   Sets what is going to happen in a pass 
    * Sample usage:
    * 
    */
  class GraphicPass
  {
  public:
    /**
     * Default constructor
     */
    GraphicPass() = default;
  
    /**
     * Default destructor
     */
    ~GraphicPass() = default;

    bool
    init();

    /**
     * DepthStencil object reference
     */
    DepthStencil* m_depthStencil;

    /**
     * Render Target View
     */
    Texture* m_renderTargetOutput;

    /**
     * Pixel Shader object
     */
    PixelShader* m_pixelShader;

    /**
     * InputLayout
     */
    InputLayout* m_inputLayout;

  };

}

