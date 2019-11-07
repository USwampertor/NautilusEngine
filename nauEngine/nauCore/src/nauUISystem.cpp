/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauUISystem.cpp
 * @author Marco "Swampy" Mill嫕
 * @date 11/5/2019
 * @brief UISystem member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauUISystem.h"

namespace nauEngineSDK {

  bool
  UISystem::init(void* hwnd) {
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    m_ui = io;

    return true;
  }

  void
  UISystem::render() {

  }

  void
  UISystem::endRender() {

  }

  void
  UISystem::newFrame() {
    ImGui::NewFrame();
  }

  void
  UISystem::endFrame() {
    ImGui::EndFrame();
  }

  void
  UISystem::renderProjectMenu() {

  }

  void
  UISystem::renderInspector() {

  }

  void
  UISystem::renderBaseUI() {

  }
}