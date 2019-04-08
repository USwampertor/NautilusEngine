#include "nauTestApp.h"

namespace nauEngineSDK {
  void
  TestApp::start() {
    
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

    

    m_renderManager->render(meshes, m_api);
    m_api->render();
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    m_api->swapBuffer();

    

  }

  bool
  TestApp::initApp(void* hwnd) {

    //API INITIALIZATION
    m_api = m_factory->createGraphicsAPI();

    if (!m_api->init(hwnd)) return false;
    
    //UI INITIALIZATION
    if (!initUI(hwnd))      return false;
    

    m_sceneGraph.init();

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
    Material* m = new Material();
    Texture* pTexture = m_api->getDevice()->createTexture();
    pTexture->loadFromFile("resources/Vela/Vela_Gun_BaseColor.tga", m_api->getDevice());
    m->setMaterial(pTexture, MATERIAL_FLAG::BASECOLOR);
    for (i; i < com->m_model->m_meshes.size(); ++i) {
      (com->m_model->m_meshes[0])->m_material = m;
    }

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