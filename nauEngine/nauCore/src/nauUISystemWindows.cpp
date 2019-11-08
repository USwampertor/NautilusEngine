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
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();

    UISystem::newFrame();

    UISystem::renderBaseUI();

    

    ////////////////////////////////////////////////////////////////////////// Inspector Window

  }

  void
  UISystemWindows::endRender() {
    UISystem::endRender();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
  }

  void
  UISystemWindows::finishUI() {
    UISystem::finishUI();
  }

}
