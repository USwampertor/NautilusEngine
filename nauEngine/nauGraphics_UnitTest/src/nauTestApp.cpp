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
    if (!m_api->init(hwnd)) return false;

    //DEARIMGUI INITIALIZATION
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(reinterpret_cast<ID3D11Device*>(m_api->getDevice()->get()),
                        reinterpret_cast<ID3D11DeviceContext*>(m_api->getDevice()->getContext()));
    m_timer.restart();
    return true;

  }

  void
  TestApp::shutDown() {

    ImGui::DestroyContext();
  }

  void
  TestApp::close() {

  }
}