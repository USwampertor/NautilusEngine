#include "nauTestApp.h"

namespace nauEngineSDK {
  void
  TestApp::start() {
    
  }

  void
  TestApp::update() {
    RenderManager::instance().update();
    Clock::instance().update();

  }

  void
  TestApp::render() {
    

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGui::SetNextWindowPos(ImVec2(30, 10));
    ImGui::SetNextWindowSize(ImVec2(300, g_graphicsAPI->getWindowSize().y - 200));
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
    
    ImGui::SetNextWindowPos(ImVec2(g_graphicsAPI->getWindowSize().x - 100,
                                   10));
    ImGui::Begin("Current Hour", 0, ImGuiWindowFlags_MenuBar);
    ImGui::Text(Clock::instance().hour().c_str());
    ImGui::End();
    ImGui::EndFrame();

    

    RenderManager::instance().render(meshes, g_graphicsAPI);
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    g_graphicsAPI->swapBuffer();

    

  }

  bool
  TestApp::initApp(void* hwnd) {

    //LOGGER INITIALIZATION
    Logger::startUp();
    Logger::instance().init();

    //API INITIALIZATION

    g_graphicsAPI = m_factory->createGraphicsAPI();
    g_graphicsAPI->init(hwnd);

    //RESOURCE MANAGER INITIALIZATION
    ResourceManager::startUp();
    ResourceManager::instance().init(g_graphicsAPI->getDevice());
    
    //UI INITIALIZATION
    if (!initUI(hwnd))      return false;

    //RENDER MANAGER INITIALIZATION
    RenderManager::startUp();
    if (!RenderManager::instance().init(g_graphicsAPI->getDevice())) return false;

    //CLOCK INITIALIZATION
    Clock::startUp();
    Clock::instance().init();

    //SCENEGRAPH INITIALIZATION
    m_sceneGraph.init();

    //ANIMATION MANAGER
    AnimationManager::startUp();


    ///TESTING MODEL
    int i = 0;
    
    Node* model = new Node();
    
    GameObject* testModel = new GameObject(); 
    testModel->m_id = "Vela";
    MeshComponent* com = new MeshComponent();
    com->m_model = new Model();
    com->m_model->setDevice(g_graphicsAPI->getDevice());
    com->m_model->loadFromFile("resources/VelaAnimated.FBX");
    
    MaterialComponent* mat1 = new MaterialComponent();
    Texture* pGunsTexture = g_graphicsAPI->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_BaseColor.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::BASECOLOR);
    pGunsTexture = g_graphicsAPI->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Metallic.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::METAL);
    pGunsTexture = g_graphicsAPI->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Normal.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::NORMAL);
    pGunsTexture = g_graphicsAPI->getDevice()->createTexture();
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Roughness.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[0])->m_material = mat1;
    
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_BaseColor.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::BASECOLOR);
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Metallic.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::METAL);
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Normal.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::NORMAL);
    pGunsTexture->loadFromFile("resources/Vela/Vela_Gun_Roughness.tga", g_graphicsAPI->getDevice());
    mat1->setMaterial(pGunsTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[1])->m_material = mat1;

    MaterialComponent* mat2 = new MaterialComponent();
    Texture* pLegsTexture = g_graphicsAPI->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_BaseColor.tga", g_graphicsAPI->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::BASECOLOR);
    pLegsTexture = g_graphicsAPI->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_Metallic.tga", g_graphicsAPI->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::METAL);
    pLegsTexture = g_graphicsAPI->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_Normal.tga", g_graphicsAPI->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::NORMAL);
    pLegsTexture = g_graphicsAPI->getDevice()->createTexture();
    pLegsTexture->loadFromFile("resources/Vela/Vela_Legs_Roughness.tga", g_graphicsAPI->getDevice());
    mat2->setMaterial(pLegsTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[2])->m_material = mat2;

    
    MaterialComponent* mat3 = new MaterialComponent();
    Texture* pMechTexture = g_graphicsAPI->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_BaseColor.tga", g_graphicsAPI->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::BASECOLOR);
    pMechTexture = g_graphicsAPI->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_Metallic.tga", g_graphicsAPI->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::METAL);
    pMechTexture = g_graphicsAPI->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_Normal.tga", g_graphicsAPI->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::NORMAL);
    pMechTexture = g_graphicsAPI->getDevice()->createTexture();
    pMechTexture->loadFromFile("resources/Vela/Vela_Mechanical_Roughness.tga", g_graphicsAPI->getDevice());
    mat3->setMaterial(pMechTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[3])->m_material = mat3;

    MaterialComponent* mat4 = new MaterialComponent();
    Texture* pCharTexture = g_graphicsAPI->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_BaseColor.tga", g_graphicsAPI->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::BASECOLOR);
    pCharTexture = g_graphicsAPI->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_Metallic.tga", g_graphicsAPI->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::METAL);
    pCharTexture = g_graphicsAPI->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_Normal.tga", g_graphicsAPI->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::NORMAL);
    pCharTexture = g_graphicsAPI->getDevice()->createTexture();
    pCharTexture->loadFromFile("resources/Vela/Vela_Char_Roughness.tga", g_graphicsAPI->getDevice());
    mat4->setMaterial(pCharTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[4])->m_material = mat4;
    
    MaterialComponent* mat5 = new MaterialComponent();
    Texture* pPlateTexture = g_graphicsAPI->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_BaseColor.tga", g_graphicsAPI->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::BASECOLOR);
    pPlateTexture = g_graphicsAPI->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_Metallic.tga", g_graphicsAPI->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::METAL);
    pPlateTexture = g_graphicsAPI->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_Normal.tga", g_graphicsAPI->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::NORMAL);
    pPlateTexture = g_graphicsAPI->getDevice()->createTexture();
    pPlateTexture->loadFromFile("resources/Vela/Vela_Plate_Roughness.tga", g_graphicsAPI->getDevice());
    mat5->setMaterial(pPlateTexture, MATERIAL_FLAG::ROUGHNESS);
    (com->m_model->m_meshes[5])->m_material = mat5;

    MaterialComponent* mat6 = new MaterialComponent();
    Texture* pEyesTexture = g_graphicsAPI->getDevice()->createTexture();
    pEyesTexture->loadFromFile("resources/Vela/Vela_EyeCornea_BaseColor.tga", g_graphicsAPI->getDevice());
    mat6->setMaterial(pEyesTexture, MATERIAL_FLAG::BASECOLOR);
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


    auto dev     = reinterpret_cast<ID3D11Device*>(g_graphicsAPI->getDevice()->get());
    auto context = reinterpret_cast<ID3D11DeviceContext*>(g_graphicsAPI->getDevice()->getContext());

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