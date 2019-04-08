/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRenderManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief RenderManager member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauRenderManager.h"

namespace nauEngineSDK {

  bool
  RenderManager::init(Device* pDevice) {

    m_rendereableTextures.insert(std::make_pair("NORMAL", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("POSITION", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("COLOR", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("DEPTH", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("EMISSIVE", pDevice->createTexture()));

    if (!m_gbPass.init(pDevice));


    m_fov = Math::degToRad(90.0f);
    m_world = Matrix4::IDENTITY;

    m_mainCamera.m_objective.setValues(0.0f, 0.0f, 0.0f);
    m_mainCamera.m_position.setValues(0.0f, 0.0f, -10.0f);
    m_mainCamera.m_up = Vector3::UP;

    m_mainCamera.createView();

    m_projection.perspective(m_fov,
                             static_cast<float>(pDevice->m_width / pDevice->m_height),
                             m_screenNear,
                             m_screenFar);

    return true;
  }

  void
  RenderManager::render(Vector<MeshComponent*> m_orderedList, GraphicsAPI* api) {
    
    m_gbPass.render();
    
  }

  void
  RenderManager::addPass(GraphicPass* pass) {

  }

  Vector<MeshComponent*>
  RenderManager::createScreenAlignedQuad(Device* pDevice) {
    MeshComponent* quad = new MeshComponent();
    quad->m_model = new Model();

  }

  void
  RenderManager::update() {
    m_gbPass.m_info.WorldMat = m_world;
    m_gbPass.m_info.ViewMat = m_mainCamera.getView();
    m_gbPass.m_info.Projection = m_projection;
    //constantbuffer add everything
    //Constant Buffer setPixel and Vertez

  }
}

///
/**
 * Clear everything
 * Set shaders
 * Set resources
 *    Update Constant Buffers
 *    UpdateSubresource
 *    SetConstantBuffer Pixel and Vertex
 *    Clear
 *    Update Sampler
 * Update Topology
 * Set Render Target
 * Set index and vertex
 */