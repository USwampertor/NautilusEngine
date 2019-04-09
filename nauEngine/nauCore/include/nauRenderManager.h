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
#include "nauCamera.h"

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
    init(Device* pDevice);

    /**
     * @brief Manages the rendering and renders by pass
     * @param meshes to render, Graphics API
     * @return 
     *
     */
    void
    render(Vector<MeshComponent*> m_orderedList, Device* pDevice);

    void
    addPass(GraphicPass* pass);

    /**
     * @brief Creates a ScreenAligned
     * @param 
     * @return 
     *
     */
    Vector<MeshComponent*>
    createScreenAlignedQuad(Device* pDevice);

    void
    update();

   public:
    


    Map<String, Texture*> m_rendereableTextures;

    ///Basic Stuff

    float m_fov;

    float m_screenNear = 0.01f;

    float m_screenFar = 1000.0f;

    float m_light;

    ///Matrices
    
    Camera m_mainCamera;

    Matrix4 m_world;

    Matrix4 m_projection;

    ///Rendering Passes

    GBPass m_gbPass;

    SSAOPass m_ssaoPass;

    ReductionPass m_reductionPass;

    BlurPass m_blurPass;

    LightningPass m_lightningPass;

    LuminancePass m_luminancePass;

    FinalPass m_finalPass;

  };
  
}


