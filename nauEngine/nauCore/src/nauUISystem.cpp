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


#include "nauComponent.h"
#include "nauGraphicsAPI.h"
#include "nauInputManager.h"
#include "nauLogger.h"
#include "nauMesh.h"
#include "nauSceneManager.h"
#include "nauGameObject.h"

namespace nauEngineSDK {

  bool
  UISystem::init(ImGuiIO& io, void* hwnd) {
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO();
    m_ui = &io;
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
        if (ImGui::MenuItem("New")) {  }
        ImGui::EndMenu();
      }
      ImGui::EndMenuBar();
    }
    ImGui::End();
  }

  void
  UISystem::renderInspector() {
    for (auto component : m_gameObjectPtr->m_properties) {
      if (ImGui::CollapsingHeader("Transform")) {
        ImGui::SliderFloat("X", &m_gameObjectPtr->m_transform.m[3][0], 0.0f, 9999.0f, "ratio = %.3f");
        ImGui::SliderFloat("Y", &m_gameObjectPtr->m_transform.m[3][1], 0.0f, 9999.0f, "ratio = %.3f");
        ImGui::SliderFloat("Z", &m_gameObjectPtr->m_transform.m[3][2], 0.0f, 9999.0f, "ratio = %.3f");
      }
      if (component->getType() == COMPONENT::MESH) {
        if (ImGui::CollapsingHeader("Mesh")) {
        }
      }

      if (component->getType() == COMPONENT::ANIMATOR) {
        if (ImGui::CollapsingHeader("Animator")) {
          if (ImGui::SmallButton("Play")) {

          }
        }
      }
    }
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
      if (ImGui::Button((obj->getGameObject()->m_id).c_str())) { 
        m_inspector = true;
        m_gameObjectPtr = obj->getGameObject();
      }
      //ImGui::Text((obj->getGameObject()->m_id).c_str());
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

    String mousePos = "Mouse position: ";
    Vector2 pos(m_ui->MousePos.x, m_ui->MousePos.y);
    mousePos += std::to_string(pos.x);
    mousePos.append("\n");
    mousePos += "                ";
    mousePos += std::to_string(pos.y);
    mousePos.append("\n");
    ImGui::Text(mousePos.c_str());

    String mouseDelta = "Mouse delta: ";
    Vector2 delta = g_inputManager->getMouseDelta();
    mouseDelta += std::to_string(delta.x);
    mouseDelta.append("\n");
    mouseDelta += "             ";
    mouseDelta += std::to_string(delta.y);
    mouseDelta.append("\n");
    ImGui::Text(mouseDelta.c_str());

    String enterPressed = "Click pressed: ";
    m_ui->MouseDown[0] ? enterPressed += "true" : enterPressed += "false";
    enterPressed.append("\n");
    enterPressed += "Accumulated delta: ";
    enterPressed += std::to_string(m_accumulatedDelta);
    enterPressed.append("\n");
    ImGui::Text(enterPressed.c_str());

    ImGui::End();

    ////////////////////////////////////////////////////////////////////////// Inspector
    if (m_inspector) {
      ImGui::SetNextWindowPos(ImVec2(g_graphicsAPI->getWindowSize().x - 200, 300));
      ImGui::SetNextWindowSize(ImVec2(200, 200));
      ImGui::Begin("Inspector");
      renderInspector();
      ImGui::End();
    }

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