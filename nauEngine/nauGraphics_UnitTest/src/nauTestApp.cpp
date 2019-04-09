#include "nauTestApp.h"

namespace nauEngineSDK {
  void
  TestApp::start() {
    
  }

  void
  TestApp::update() {
    m_renderManager->update();

  }

  void
  TestApp::render() {
    

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGui::SetNextWindowPos(ImVec2(30, 10));
    ImGui::SetNextWindowSize(ImVec2(300, m_api->getWindowSize().y - 200));
    ImGui::Begin("SceneGraph", 0, ImGuiWindowFlags_MenuBar);
    ImGui::Text("Scene 1");
    Vector<MeshComponent*> meshes;
    for (auto obj : m_sceneGraph.getSceneGameObjects()) {
      auto mesh = obj->getGameObject()->getComponent(COMPONENT::MESH);
      if (mesh != nullptr) {
        meshes.push_back(reinterpret_cast<MeshComponent*>(mesh));
      }
      ImGui::Text((obj->getGameObject()->m_id).c_str());
    }
    ImGui::End();
    
    ImGui::SetNextWindowPos(ImVec2(m_api->getWindowSize().x - 100,
                                   10));
    ImGui::Begin("Hour", 0, ImGuiWindowFlags_MenuBar);
    ImGui::Text("%f", m_timer.asSeconds());
    ImGui::End();
    ImGui::EndFrame();

    

    m_renderManager->render(meshes, m_api->getDevice());
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    m_api->swapBuffer();

    

  }

  bool
  TestApp::initApp(void* hwnd) {

    //API INITIALIZATION
    m_api = m_factory->createGraphicsAPI();
    m_renderManager = new RenderManager();
    if (!m_api->init(hwnd)) return false;
    //UI INITIALIZATION
    if (!initUI(hwnd))      return false;
    

    m_sceneGraph.init();

    if (!m_renderManager->init(m_api->getDevice())) return false;
    //Last object to initiate should be the clock
    m_timer.restart();

    ///TESTING MODEL
    int i = 0;
    
    Node* model = new Node();
    
    GameObject* testModel = new GameObject(); 
    testModel->m_id = "Vela";
    MeshComponent* com = new MeshComponent();
    com->m_model = new Model();
    com->m_model->setDevice(m_api->getDevice());
    com->m_model->loadFromFile("resources/Vela.FBX");
    
    Material* mat1 = new Material();
    Texture* pGunsTexture = m_api->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_BaseColor.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::BASECOLOR);
    pGunsTexture = m_api->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Metallic.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::METAL);
    pGunsTexture = m_api->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Normal.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::NORMAL);
    pGunsTexture = m_api->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Roughness.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[0])->m_material = mat1;
    
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_BaseColor.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::BASECOLOR);
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Metallic.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::METAL);
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Normal.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::NORMAL);
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Roughness.tga", m_api->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[1])->m_material = mat1;

    Material* mat2 = new Material();
    Texture* pLegsTexture = m_api->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_BaseColor.tga", m_api->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::BASECOLOR);
    pLegsTexture = m_api->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_Metallic.tga", m_api->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::METAL);
    pLegsTexture = m_api->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_Normal.tga", m_api->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::NORMAL);
    pLegsTexture = m_api->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_Roughness.tga", m_api->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[2])->m_material = mat2;

    
    Material* mat3 = new Material();
    Texture* pMechTexture = m_api->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_BaseColor.tga", m_api->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::BASECOLOR);
    pMechTexture = m_api->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_Metallic.tga", m_api->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::METAL);
    pMechTexture = m_api->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_Normal.tga", m_api->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::NORMAL);
    pMechTexture = m_api->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_Roughness.tga", m_api->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[3])->m_material = mat3;

    Material* mat4 = new Material();
    Texture* pCharTexture = m_api->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_BaseColor.tga", m_api->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::BASECOLOR);
    pCharTexture = m_api->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_Metallic.tga", m_api->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::METAL);
    pCharTexture = m_api->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_Normal.tga", m_api->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::NORMAL);
    pCharTexture = m_api->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_Roughness.tga", m_api->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[4])->m_material = mat4;
    
    Material* mat5 = new Material();
    Texture* pPlateTexture = m_api->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_BaseColor.tga", m_api->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::BASECOLOR);
    pPlateTexture = m_api->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_Metallic.tga", m_api->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::METAL);
    pPlateTexture = m_api->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_Normal.tga", m_api->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::NORMAL);
    pPlateTexture = m_api->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_Roughness.tga", m_api->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[5])->m_material = mat5;

    Material* mat6 = new Material();
    Texture* pEyesTexture = m_api->getDevice()->createTexture();
    pEyesTexture->loadFromFile("resources/Vela/Vela_EyeCornea_BaseColor.tga", m_api->getDevice());
    mat6->setMaterial(pEyesTexture, MATERIAL_FLAG::BASECOLOR);
    pEyesTexture = m_api->getDevice()->createTexture();
    pEyesTexture->loadFromFile("resources/Vela/Vela_EyeCornea_Metallic.tga", m_api->getDevice());
    mat6->setMaterial(pEyesTexture, MATERIAL_FLAG::METAL);
    pEyesTexture = m_api->getDevice()->createTexture();
    pEyesTexture->loadFromFile("resources/Vela/Vela_EyeCornea_Normal.tga", m_api->getDevice());
    mat6->setMaterial(pEyesTexture, MATERIAL_FLAG::NORMAL);
    pEyesTexture = m_api->getDevice()->createTexture();
    pEyesTexture->loadFromFile("resources/Vela/Vela_EyeCornea_Roughness.tga", m_api->getDevice());
    mat6->setMaterial(pEyesTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[6])->m_material = mat6;

    testModel->addComponent(com);
    model->setGameObject(testModel);
    m_sceneGraph.set(model);
    return true;

  }

  bool
  TestApp::initUI(void* hwnd) {
    //DEARIMGUI INITIALIZATION
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    if (!ImGui_ImplWin32_Init(hwnd)) return false;


    auto dev     = reinterpret_cast<ID3D11Device*>(m_api->getDevice()->get());
    auto context = reinterpret_cast<ID3D11DeviceContext*>(m_api->getDevice()->getContext());

    return ImGui_ImplDX11_Init(dev, context);
  }

  void
  TestApp::shutDown() {
    ImGui::DestroyContext();
  }

  void
  TestApp::close() {

  }
}