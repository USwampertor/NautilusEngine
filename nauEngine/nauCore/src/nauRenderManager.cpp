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

    ///DEFAULT OBJECT INITIALIZATION

    m_fov = Math::degToRad(90.0f);
    m_world = Matrix4::IDENTITY;

    m_mainCamera.m_objective.setValues(0.0f, 100.0f, 0.0f);
    m_mainCamera.m_position.setValues(0.0f, 100.0f, -100.0f);
    m_mainCamera.m_up = Vector3::UP;

    m_mainCamera.createView();

    m_projection.perspective(m_fov,
                             static_cast<float>(pDevice->m_width / pDevice->m_height),
                             m_screenNear,
                             m_screenFar);

    ///BUFFER INITIALIZATION
    if (!m_gbPass.init(pDevice)) return false;

    return true;
  }

  void
  RenderManager::render(Vector<MeshComponent*> m_orderedList, Device* pDevice) {
    
    m_gbPass.render(m_orderedList, pDevice);
    
  }

  void
  RenderManager::addPass(GraphicPass* pass) {

  }

  Vector<MeshComponent*>
  RenderManager::createScreenAlignedQuad(Device* pDevice) {
    Vector<MeshComponent*> quads;
    MeshComponent* quad = new MeshComponent();
    quad->m_model = new Model();
    Mesh* m = new Mesh();
    
    m->m_indexBuffer = pDevice->createIndexBuffer();
    m->m_vertexBuffer = pDevice->createVertexBuffer();
    m->m_indexBuffer->reserve(3);
    m->m_vertexBuffer->reserve(3);

    Vertex pVertex;
    pVertex.m_position = { -1.0f,-1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,1.0f,1.0f,1.0f };
    pVertex.m_uv = { 0.0f, 1.0f };
    m->m_vertexBuffer->add(pVertex);

    pVertex.m_position = { -1.0f,1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,1.0f,1.0f,1.0f };
    pVertex.m_uv = { 1.0f, 1.0f };
    m->m_vertexBuffer->add(pVertex);

    pVertex.m_position = { 1.0f,1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,1.0f,1.0f,1.0f };
    pVertex.m_uv = { 1.0f, 0.0f };
    m->m_vertexBuffer->add(pVertex);

    pVertex.m_position = { 1.0f,-1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,1.0f,1.0f,1.0f };
    pVertex.m_uv = { 1.0f, 1.0f };
    m->m_vertexBuffer->add(pVertex);

    m->m_indexBuffer->add(0);
    m->m_indexBuffer->add(1);
    m->m_indexBuffer->add(2);
    m->m_indexBuffer->add(2);
    m->m_indexBuffer->add(3);
    m->m_indexBuffer->add(0);

    m->m_indexBuffer->createHardware(pDevice->get(),0);

    m->m_vertexBuffer->createHardware(pDevice->get(),0);
    quad->m_model->m_meshes.push_back(m);
    quads.push_back(quad);
    return quads;
  }

  void
  RenderManager::update() {
    m_world.rotateY(0.001f);


    m_gbPass.m_info.WorldMat = m_world;
    m_gbPass.m_info.ViewMat = m_mainCamera.getView();
    m_gbPass.m_info.Projection = m_projection;

    m_gbPass.updatePass();
    //constan tbuffer add everything
    //Constant Buffer setPixel and Vertex

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