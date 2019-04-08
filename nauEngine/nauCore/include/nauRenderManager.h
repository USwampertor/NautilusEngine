/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRenderManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/23 2019
 * @brief Render Manager module in charge of doing all the render stuff in the 
 *        specific library. It should render Mesh Components
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauComponent.h"
#include "nauModule.h"
#include "nauGraphicPass.h"
#include "nauGraphicsAPI.h"
#include "nauCoreFactory.h"

namespace nauEngineSDK {

   /**
    * RenderManager
    * Description:
    *   Used for rendering meshComponents each frame 
    * Sample usage:
    *   render() renders everything
    */
  class NAU_CORE_EXPORT RenderManager : public Module<RenderManager>
  {
   public:
    /**
     * Default constructor
     */
    RenderManager() = default;

    /**
     * Default virtual destructor
     */
    virtual ~RenderManager() = default;

    /**
     * @brief initiates the RenderManager
     * @param Device as long as I cant get the global instance
     * @return 
     *
     */
    bool
    init(GraphicsAPI* api);

    /**
     * @brief Manages the rendering and renders by pass
     * @param meshes to render, Graphics API
     * @return 
     *
     */
    void
    render(Vector<MeshComponent*> m_orderedList, GraphicsAPI* api);

    void
    addPass(GraphicPass* pass);

   public:
     Vector<GraphicPass*> m_passes;
  };
  
}


