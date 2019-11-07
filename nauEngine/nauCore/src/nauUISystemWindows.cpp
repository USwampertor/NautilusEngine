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

namespace  nauEngineSDK {

  bool
  UISystemWindows::init(void* hwnd) {
    if (!init(hwnd)) { return false; }
    if (!ImGui_ImplWin32_Init(hwnd)) { return false; }

    if (g_graphicsAPI->getAPIType() == APITYPE::DX11) {

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
  }
}
