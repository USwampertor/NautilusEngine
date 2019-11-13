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
    //renderUI();
    UI::instance().render();
    Vector<MeshComponent*> meshes;
    for (auto obj : SceneManager::instance().getActiveScene()->m_sceneGraph->getSceneGameObjects()) {
      auto mesh = obj->getGameObject()->getComponent(COMPONENT::MESH);
      if (mesh != nullptr) {
        meshes.push_back(reinterpret_cast<MeshComponent*>(mesh));
      }
    }
    

    //ImGui::EndFrame();
    UI::instance().endFrame();
    RenderManager::instance().render(meshes, g_graphicsAPI);
    UI::instance().endRender();
    //ImGui::Render();
    //ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    g_graphicsAPI->swapBuffer();

  }

#pragma region DEPRECATED FUNCTIONS

  void
  TestApp::renderUI() {
    ////////////////////////////////////////////////////////////////////////// New Frame DX11
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();

    ////////////////////////////////////////////////////////////////////////// New Frame
    ImGui::NewFrame();

    ////////////////////////////////////////////////////////////////////////// Menu Bar
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(g_graphicsAPI->getWindowSize().x, 30));

    ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
      if (ImGui::BeginMenu("Project")) {
        if (ImGui::MenuItem("New")) {}
        ImGui::EndMenu();
      }
      ImGui::EndMenuBar();
    }
    ImGui::End();

    ////////////////////////////////////////////////////////////////////////// Scene Window
    ImGui::SetNextWindowPos(ImVec2(0, 40));
    ImGui::SetNextWindowSize(ImVec2(300, g_graphicsAPI->getWindowSize().y - 200));
    ImGui::Begin("SceneGraph", 0, ImGuiWindowFlags_MenuBar);
    ImGui::Text("Scene 1");
    Vector<MeshComponent*> meshes;
    for (auto obj : SceneManager::instance().getActiveScene()->m_sceneGraph->getSceneGameObjects()) {
      auto mesh = obj->getGameObject()->getComponent(COMPONENT::MESH);
      ImGui::Text((obj->getGameObject()->m_id).c_str());
    }
    ImGui::End();

    ////////////////////////////////////////////////////////////////////////// Information Window
    ImGui::SetNextWindowPos(ImVec2(g_graphicsAPI->getWindowSize().x - 200, 40));
    ImGui::SetNextWindowSize(ImVec2(200, 200));
    ImGui::Begin("System Information", 0, ImGuiWindowFlags_MenuBar);
    String hour = "System hour";
    hour += Clock::instance().hour();
    hour.append("\n");
    ImGui::Text(hour.c_str());

    String average = "Application average: ";
    average += std::to_string(1000.0f / ImGui::GetIO().Framerate);
    average.append("\n");
    ImGui::Text(average.c_str());

    String ms = "ms/frame: ";
    ms += std::to_string(ImGui::GetIO().Framerate);
    ms.append("\n");
    ImGui::Text(ms.c_str());

    ImGui::End();

////////////////////////////////////////////////////////////////////////// Log Window
    ImGui::SetNextWindowPos(ImVec2(0, g_graphicsAPI->getWindowSize().y - 200));
    ImGui::SetNextWindowSize(ImVec2(g_graphicsAPI->getWindowSize().x, 200));
    ImGui::Begin("Log Window", 0, ImGuiWindowFlags_MenuBar);
    for (auto logString : Logger::instance().get()) {
      ImGui::Text(logString.c_str());
    }
    ImGui::End();

////////////////////////////////////////////////////////////////////////// Inspector Window

  }


  bool
  TestApp::initUI(void* hwnd) {
    //DEARIMGUI INITIALIZATION
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    if (!ImGui_ImplWin32_Init(hwnd)) return false;

    if (g_graphicsAPI->getAPIType() == APITYPE::DX11) {
      auto dev = reinterpret_cast<ID3D11Device*>(g_graphicsAPI->getDevice()->get());
      auto context = reinterpret_cast<ID3D11DeviceContext*>(g_graphicsAPI->getDevice()->getContext());

      return ImGui_ImplDX11_Init(dev, context);
    }

    return true;
  }


#pragma endregion
  
  bool
  TestApp::initApp(void* hwnd) {

    //LOGGER INITIALIZATION
    Logger::startUp();
    Logger::instance().init();

    //CLOCK INITIALIZATION
    Clock::startUp();
    Clock::instance().init();
    
    //API INITIALIZATION
    DLLoader::startUp();
    DLLoader::instance().init();

    String pathDXAPI = "nauGraphicsDX";
    String pathGAAPI = "nauGAInput";

    g_graphicsAPI = reinterpret_cast<GraphicsAPI*>(DLLoader::instance().load(pathDXAPI, "createPluginAPI"));
    g_inputManager = reinterpret_cast<InputManager*>(DLLoader::instance().load(pathGAAPI, "createPluginAPI"));
    
    if (!g_graphicsAPI) {
      Logger::instance().toIDE("Couldn't load default Graphics API... Closing now",
                               LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(991);
    }
    if (!g_inputManager) {
      Logger::instance().toIDE("Couldn't load default Input Manager... Closing now",
                               LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(992);
    }

    g_graphicsAPI->init(hwnd);

    //RESOURCE MANAGER INITIALIZATION
    ResourceManager::startUp();
    ResourceManager::instance().init(g_graphicsAPI->getDevice());
    
    //UI INITIALIZATION
    UI::startUp<UISystemWindows>();
    UI::instance().init(hwnd);

    //if (!initUI(hwnd))      return false;


    //RENDER MANAGER INITIALIZATION
    RenderManager::startUp();
    if (!RenderManager::instance().init(g_graphicsAPI->getDevice())) return false;


    //SCENEGRAPH INITIALIZATION
    SceneManager::startUp();
    SceneManager::instance().init();

    //m_sceneGraph.init();

    //ANIMATION MANAGER
    AnimationManager::startUp();
    AnimationManager::instance().init();

    //INPUT MANAGER
    g_inputManager->init();

#pragma region TestObject

    ///TESTING MODEL

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
    SceneManager::instance().getActiveScene()->m_sceneGraph->set(model);

#pragma endregion

    return true;

  }

  void
  TestApp::shutDown() {
    UI::instance().finishUI();
    //ImGui::DestroyContext();
  }

  void
  TestApp::close() {

  }
}