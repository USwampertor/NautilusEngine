/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauWindowsApp.cpp
 * @author Marco "Swampy" Millan
 * @date 11/13/2019
 * @brief Nautilus Windows App implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauWindowsApp.h"

namespace nauEngineSDK {

#pragma region INHERITED FUNCTIONS

  int32
  WindowsApp::start() {
    HACCEL hAccelTable = LoadAccelerators(m_hInst, MAKEINTRESOURCE(1));
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0)) {
      update();
      if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
      g_inputManager->handleMessage(&msg);
      render();
    }
    return static_cast<int32>(msg.wParam);
  }

  void
  WindowsApp::update() {

    g_inputManager->update();
    //UI::instance().updateInput();

    RenderManager::instance().update();
    Clock::instance().update();
  }

  void
  WindowsApp::render() {
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
  WindowsApp::renderUI() {  }
  
  bool
  WindowsApp::initUI(void* hwnd) { return true; }

  /*
  void
  WindowsApp::renderUI() {
    
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
  WindowsApp::initUI(void* hwnd) {
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

  */
#pragma endregion DEPRECATED FUNCTIONS

  bool
  WindowsApp::initApp(void* hwnd) {

    m_appName = "Nautilus Engine";
    m_windowClass = "Nautilus Class";

    //LOGGER INITIALIZATION
    Logger::startUp();
    Logger::instance().init();

    //CLOCK INITIALIZATION
    Clock::startUp();
    Clock::instance().init();

    //API INITIALIZATION
    DLLoader::startUp();
    DLLoader::instance().init();

    MyRegisterClass();
    
    if (!InitInstance()) {
      Logger::instance().toIDE("Couldn't initialize instance of Windows Class",
        LOGGER_LEVEL::ERRORED);
      Logger::instance().dump();
      exit(1001);
    }

    
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
    g_graphicsAPI->init(m_hWnd);

    //RESOURCE MANAGER INITIALIZATION
    ResourceManager::startUp();
    ResourceManager::instance().init(g_graphicsAPI->getDevice());

    //UI INITIALIZATION
    UI::startUp<UISystemWindows>();
    UI::instance().init(m_hWnd);

    //RENDER MANAGER INITIALIZATION
    RenderManager::startUp();
    if (!RenderManager::instance().init(g_graphicsAPI->getDevice())) return false;


    //SCENEGRAPH INITIALIZATION
    SceneManager::startUp();
    SceneManager::instance().init();

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
    WindowsApp::shutDown() {
    UI::instance().finishUI();
  }

  void
    WindowsApp::close() {

  }

#pragma endregion INHERITED FUNCTIONS


#pragma region WINDOWS FUNCTIONS
  
  //Windows specific functions
  INT_PTR CALLBACK 
  WindowsApp::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);

    switch (message) {
    case WM_INITDIALOG:
      return (INT_PTR)TRUE;

    case WM_COMMAND:
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
      }
      break;
    }
    return (INT_PTR)FALSE;
  }

  

  BOOL 
  WindowsApp::InitInstance() {

    //std::wstring windowClass(m_windowClass.begin(), m_windowClass.end());
    //std::wstring appName(m_appName.begin(), m_appName.end());

    WCHAR szTitle[MAX_LOADSTRING] = L"Nautilus Engine";
    WCHAR szWindowClass[MAX_LOADSTRING] = L"Nautilus Class";

    m_hWnd = CreateWindowExW(0, 
                             szWindowClass, 
                             szTitle, 
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, 
                             CW_USEDEFAULT, 
                             1280, 
                             1024, 
                             nullptr, 
                             nullptr, 
                             m_hInst, 
                             nullptr);

    if (!m_hWnd) {
      return FALSE;
    }

    ShowWindow(m_hWnd, m_commandShow);
    UpdateWindow(m_hWnd);

    return TRUE;
  }
  
  LRESULT CALLBACK 
  WindowsApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam)) return true;

    switch (message)
    {
    case WM_COMMAND:
    {
      int wmId = LOWORD(wParam);
      switch (wmId)
      {
      case IDM_ABOUT:
        DialogBoxParam(m_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), m_hWnd, About, lParam);
        break;
      case IDM_EXIT:
        DestroyWindow(hWnd);
        break;
      default:
        return DefWindowProc(hWnd, message, wParam, lParam);
      }
    }
    break;
    case WM_PAINT: {
      PAINTSTRUCT ps;
      EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
  }

  ATOM 
  WindowsApp::MyRegisterClass() {
    
    WNDCLASSEXW wcex;
    WCHAR szWindowClass[MAX_LOADSTRING] = L"Nautilus Class";

    wcex.cbSize = sizeof(WNDCLASSEXW);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIconW(m_hInst, MAKEINTRESOURCEW(IDI_GRAFICAS21));
    wcex.hCursor = LoadCursorW(nullptr, MAKEINTRESOURCEW(32512));
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GRAFICAS21);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIconW(wcex.hInstance, MAKEINTRESOURCEW(IDI_SMALL));

    return RegisterClassExW(&wcex);
  }

  void 
  WindowsApp::ImGui_ImplWin32_UpdateMousePos() {

    // Set OS mouse position if requested (rarely used, only when ImGuiConfigFlags_NavEnableSetMousePos is enabled by user)
    if (UI::instance().m_ui.WantSetMousePos) {
      POINT pos = { static_cast<int>(UI::instance().m_ui.MousePos.x), 
                    static_cast<int>(UI::instance().m_ui.MousePos.y) };
      ::ClientToScreen(m_hWnd, &pos);
      ::SetCursorPos(pos.x, pos.y);
    }

    // Set mouse position
    UI::instance().m_ui.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
    POINT pos;
    if (HWND active_window = ::GetForegroundWindow())
      if (active_window == m_hWnd || ::IsChild(active_window, m_hWnd))
        if (::GetCursorPos(&pos) && ::ScreenToClient(m_hWnd, &pos))
          UI::instance().m_ui.MousePos = ImVec2((float)pos.x, (float)pos.y);
  }

  bool 
  WindowsApp::ImGui_ImplWin32_UpdateMouseCursor() {
    
    if (UI::instance().m_ui.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange) { return false; }

    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (imgui_cursor == ImGuiMouseCursor_None || UI::instance().m_ui.MouseDrawCursor) {
      // Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
      ::SetCursor(NULL);
    }
    else {
      // Show OS mouse cursor
      LPTSTR win32_cursor = IDC_ARROW;
      switch (imgui_cursor)
      {
      case ImGuiMouseCursor_Arrow:        win32_cursor = IDC_ARROW; break;
      case ImGuiMouseCursor_TextInput:    win32_cursor = IDC_IBEAM; break;
      case ImGuiMouseCursor_ResizeAll:    win32_cursor = IDC_SIZEALL; break;
      case ImGuiMouseCursor_ResizeEW:     win32_cursor = IDC_SIZEWE; break;
      case ImGuiMouseCursor_ResizeNS:     win32_cursor = IDC_SIZENS; break;
      case ImGuiMouseCursor_ResizeNESW:   win32_cursor = IDC_SIZENESW; break;
      case ImGuiMouseCursor_ResizeNWSE:   win32_cursor = IDC_SIZENWSE; break;
      case ImGuiMouseCursor_Hand:         win32_cursor = IDC_HAND; break;
      }
      ::SetCursor(::LoadCursor(NULL, win32_cursor));
    }
    return true;
  }

  LRESULT
  WindowsApp::ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui::GetCurrentContext() == NULL)
      return 0;

    switch (msg) {
    case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK:
    case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK:
    case WM_MBUTTONDOWN: case WM_MBUTTONDBLCLK:
    case WM_XBUTTONDOWN: case WM_XBUTTONDBLCLK: {
      int button = 0;
      if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONDBLCLK) { button = 0; }
      if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONDBLCLK) { button = 1; }
      if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONDBLCLK) { button = 2; }
      if (msg == WM_XBUTTONDOWN || msg == WM_XBUTTONDBLCLK) { button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) ? 3 : 4; }
      if (!ImGui::IsAnyMouseDown() && ::GetCapture() == NULL)
        ::SetCapture(hwnd);
      UI::instance().m_ui.MouseDown[button] = true;
      return 0;
    }
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
    case WM_XBUTTONUP: {
      int button = 0;
      if (msg == WM_LBUTTONUP) { button = 0; }
      if (msg == WM_RBUTTONUP) { button = 1; }
      if (msg == WM_MBUTTONUP) { button = 2; }
      if (msg == WM_XBUTTONUP) { button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) ? 3 : 4; }
      UI::instance().m_ui.MouseDown[button] = false;
      if (!ImGui::IsAnyMouseDown() && ::GetCapture() == hwnd)
        ::ReleaseCapture();
      return 0;
    }
    case WM_MOUSEWHEEL:
      UI::instance().m_ui.MouseWheel += (float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA;
      return 0;
    case WM_MOUSEHWHEEL:
      UI::instance().m_ui.MouseWheelH += (float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA;
      return 0;
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
      if (wParam < 256)
        UI::instance().m_ui.KeysDown[wParam] = 1;
      return 0;
    case WM_KEYUP:
    case WM_SYSKEYUP:
      if (wParam < 256)
        UI::instance().m_ui.KeysDown[wParam] = 0;
      return 0;
    case WM_CHAR:
      // You can also use ToAscii()+GetKeyboardState() to retrieve characters.
      UI::instance().m_ui.AddInputCharacter((unsigned int)wParam);
      return 0;
    case WM_SETCURSOR:
      if (LOWORD(lParam) == HTCLIENT && ImGui_ImplWin32_UpdateMouseCursor())
        return 1;
      return 0;
    }
    return 0;
  }

  HINSTANCE WindowsApp::m_hInst;
  HWND WindowsApp::m_hWnd;

#pragma endregion WINDOWS FUNCTIONS


}
