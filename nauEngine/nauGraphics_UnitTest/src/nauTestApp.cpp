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
    ImGui::Begin("My First Window", 0, ImGuiWindowFlags_MenuBar);
    ImGui::Text("Time: %f", m_timer.asSeconds());
    m_api->render();
    ImGui::End();
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    m_api->swapBuffer();

    

  }

  bool
  TestApp::initApp(void* hwnd) {

    //API INITIALIZATION
    m_api = m_factory->createGraphicsAPI();
    //if ( g_graphicsAPI().instancePtr() == nullptr) {
    //  std::cout << "Couldnt make API" << std::endl;
    //  return false;
    //}

    if (!m_api->init(hwnd)) return false;
    
    //UI INITIALIZATION
    if (!initUI(hwnd))      return false;
    
    m_timer.restart();
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