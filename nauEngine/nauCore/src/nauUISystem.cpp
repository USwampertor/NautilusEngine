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


#include "nauGraphicsAPI.h"
#include "nauComponent.h"
#include "nauMesh.h"
#include "nauLogger.h"
#include "nauSceneManager.h"

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
    renderBaseUI();
  }

  void
  UISystem::endRender() {
    ImGui::Render();
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
  }

  void
  UISystem::renderInspector() {

  }

  void
  UISystem::renderBaseUI() {
    renderProjectMenu();
    ////////////////////////////////////////////////////////////////////////// Scene Window
    ImGui::SetNextWindowPos(ImVec2(0, 40));
    ImGui::SetNextWindowSize(ImVec2(300, g_graphicsAPI->getWindowSize().y - 200));
    ImGui::Begin("SceneGraph", 0, ImGuiWindowFlags_MenuBar);
    ImGui::Text(SceneManager::instance().getActiveScene()->getName().c_str());
    Vector<MeshComponent*> meshes;
    for (auto obj : SceneManager::instance().getActiveScene()->m_sceneGraph->getSceneGameObjects()) {
      ImGui::Text((obj->getGameObject()->m_id).c_str());
    }
    ImGui::End();

    ////////////////////////////////////////////////////////////////////////// Information Window
    ImGui::SetNextWindowPos(ImVec2(g_graphicsAPI->getWindowSize().x - 200, 40));
    ImGui::SetNextWindowSize(ImVec2(200, 200));
    ImGui::Begin("System Information", 0, ImGuiWindowFlags_MenuBar);
    String hour = "System hour: ";
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
  }

  void
  UISystem::finishUI() {
    ImGui::DestroyContext();
  }

}