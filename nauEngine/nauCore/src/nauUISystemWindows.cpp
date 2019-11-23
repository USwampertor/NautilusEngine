/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauUISystemWindows.cpp
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief Windows Defined System implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauUISystemWindows.h"

#include "nauGraphicsAPI.h"
#include "nauComponent.h"
#include "nauMesh.h"
#include "nauLogger.h"
#include "nauSceneManager.h"

#include "nauInputManager.h"

namespace  nauEngineSDK {

  bool
  UISystemWindows::init(void* hwnd) {
    if (!UISystem::init(hwnd)) { return false; }
    if (!ImGui_ImplWin32_Init(hwnd)) { return false; }


    if (g_graphicsAPI->getAPIType() == APITYPE::DX11) {
      auto dev = reinterpret_cast<ID3D11Device*>(g_graphicsAPI->getDevice()->get());
      auto context = reinterpret_cast<ID3D11DeviceContext*>(g_graphicsAPI->getDevice()->getContext());

      return ImGui_ImplDX11_Init(dev, context);
    }

    return true;
  }

  void
  UISystemWindows::newFrame() {
    UISystem::newFrame();
  }

  void
  UISystemWindows::endFrame() {
    UISystem::endFrame();
    ImGui::EndFrame();
  }

  void
  UISystemWindows::render() {
    
    ////////////////////////////////////////////////////////////////////////// New Frame DX11
    if (g_graphicsAPI->getAPIType() == APITYPE::DX11) { ImGui_ImplDX11_NewFrame(); }

    ImGui_ImplWin32_NewFrame();

    UISystem::newFrame();

    UISystem::renderBaseUI();

    

    ////////////////////////////////////////////////////////////////////////// Inspector Window

  }

  void
  UISystemWindows::endRender() {
    UISystem::endRender();
    if (g_graphicsAPI->getAPIType() == APITYPE::DX11) { ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData()); }
  }

  void
  UISystemWindows::finishUI() {
    UISystem::finishUI();
  }

  bool
  UISystemWindows::updateInput() {
    

    if (ImGui::GetCurrentContext() == nullptr) { return false; }
    ImVec2 pos(g_inputManager->getMousePosition().x * g_graphicsAPI->getWindowSize().x,
               g_inputManager->getMousePosition().y * g_graphicsAPI->getWindowSize().y);
    m_ui.MousePos = pos;
    ImVec2 delta(0, g_inputManager->getScrollDelta());
    m_ui.MouseDelta = delta;

    m_accumulatedDelta += delta.y * 100.0f;

    if (g_inputManager->getMouseButtonDown(KEY::MOUSE0)) {
      m_ui.MouseDown[0] = true; 
      return false;
    }
    else { 
      m_ui.MouseDown[0] = false; 
      return false; 
    }

    if (g_inputManager->getScrollDelta() != 0.0f) {
      m_ui.MouseWheel += g_inputManager->getScrollDelta();
      return false;
    }

    return true;
  }

}
