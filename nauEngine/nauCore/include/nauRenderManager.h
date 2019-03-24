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

namespace nauEngineSDK {

   /**
    * RenderManager
    * Description:
    *   Used for rendering meshComponents each frame 
    * Sample usage:
    *   render() renders everything
    */
  class RenderManager
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

    virtual void
    render(Vector<MeshComponent> m_orderedList) = 0;
  };
  
}


