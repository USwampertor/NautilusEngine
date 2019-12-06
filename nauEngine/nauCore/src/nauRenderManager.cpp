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

#include "nauCameraManager.h"

namespace nauEngineSDK {

  bool
  RenderManager::init(Device* pDevice) {

    Logger::instance().toIDE("Initializing RenderManager");

    ///Render able Textures
    m_rendereableTextures.insert(std::make_pair("NORMAL", g_graphicsAPI->getDevice()->createTexture()));
    m_rendereableTextures.insert(std::make_pair("POSITION", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("COLOR", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("DEPTH", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("EMISSIVE", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("REDUCTION", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("BLURV", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("AMBIENT", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("LUMINANCE", pDevice->createTexture()));
    m_rendereableTextures.insert(std::make_pair("LIGHTNING", pDevice->createTexture()));

    for (auto texture : m_rendereableTextures) {
      (texture.second)->init(pDevice, pDevice->m_width, pDevice->m_height);
    }

    ///DEFAULT OBJECT INITIALIZATION
    //m_fov = Math::degToRad(90.0f);
    m_world = Matrix4::IDENTITY;

    //m_mainCamera.m_objective.setValues(0.0f, 100.0f, 0.0f);
    //m_mainCamera.m_position.setValues(0.0f, 100.0f, -100.0f);
    //m_mainCamera.m_up = Vector3::UP;
    //
    //m_mainCamera.createView();

    m_projection.perspective(CameraManager::instance().getActiveCamera()->m_fov,
                             static_cast<float>(pDevice->m_width / pDevice->m_height),
                             CameraManager::instance().getActiveCamera()->m_near,
                             CameraManager::instance().getActiveCamera()->m_far);

    ///BUFFER INITIALIZATION
    if (!m_gbPass.init(pDevice,m_rendereableTextures)) return false;
    //if (!m_ssaoPass.init(pDevice, m_rendereableTextures)) return false;
    //if (!m_blurPass.init(pDevice, m_rendereableTextures)) return false;
    //if (!m_lightningPass.init(pDevice, m_rendereableTextures)) return false;
    //if (!m_luminancePass.init(pDevice, m_rendereableTextures)) return false;
    if (!m_finalPass.init(pDevice, m_rendereableTextures)) return false;
    //if (!m_computePass.init(pDevice, m_rendereableTextures)) return false;

    m_testQuaternion = Quaternion::IDENTITY;
    m_world.rotateY(Math::degToRad(13.0f));
    m_testQuaternion.setRotationMatrix(m_world.getRotationMatrix());
    return true;
  }

  void
  RenderManager::render(Vector<MeshComponent*> m_orderedList, GraphicsAPI* pApi) {
    
    Device* pDevice = pApi->getDevice();
    
    m_gbPass.render(m_orderedList, pDevice);

    //m_ssaoPass.render(createScreenAlignedQuad(pDevice), pDevice);
    //m_blurPass.render(createScreenAlignedQuad(pDevice), pDevice);
    //m_lightningPass.render(createScreenAlignedQuad(pDevice), pDevice);
    //m_luminancePass.render(createScreenAlignedQuad(pDevice), pDevice);
    m_finalPass.render(createScreenAlignedQuad(pDevice), pDevice);
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
    m->m_indexBuffer->reserve(6);
    m->m_vertexBuffer->reserve(4);

    Vertex pVertex;
    pVertex.m_position = { -1.0f,-1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,1.0f,1.0f,1.0f };
    pVertex.m_uv = { 0.0f, 1.0f };
    m->m_vertexBuffer->add(pVertex);

    pVertex.m_position = { -1.0f,1.0f,0.0f,1.0f };
    pVertex.m_color = { 1.0f,1.0f,1.0f,1.0f };
    pVertex.m_uv = { 0.0f, 0.0f };
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
    m->m_indexBuffer->add(0);
    m->m_indexBuffer->add(2);
    m->m_indexBuffer->add(3);

    m->m_indexBuffer->createHardware(pDevice->get(),0);
    m->m_vertexBuffer->createHardware(pDevice->get(),0);

    m->m_material = new MaterialComponent();
    quad->m_model->m_meshes.push_back(m);
    quad->m_model->setDevice(pDevice);
    quads.push_back(quad);

    return quads;
  }

  void
  RenderManager::update() {
    
    //m_testQuaternion.rotateAroundY(Math::degToRad(0.0001f));
    //m_world.setValues(m_testQuaternion.rotationMatrix());
    m_world.rotateY(0.0005f);
    
    m_gbPass.m_info.WorldMat = m_world;
    m_gbPass.m_info.ViewMat = CameraManager::instance().getActiveCamera()->getView();
    m_gbPass.m_info.Projection = m_projection;
    m_gbPass.m_info.fNear = CameraManager::instance().getActiveCamera()->m_near;
    m_gbPass.m_info.fFar = CameraManager::instance().getActiveCamera()->m_far;
    m_gbPass.updatePass();

    m_ssaoPass.updatePass();

    m_blurPass.updatePass();

    m_lightningPass.updatePass();

    m_luminancePass.updatePass();

    m_finalPass.updatePass();



    //constant buffer add everything
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