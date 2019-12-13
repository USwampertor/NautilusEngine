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


#include "nauCameraManager.h"
#include "nauComponent.h"
#include "nauGameObject.h"
#include "nauGraphicsAPI.h"
#include "nauInputManager.h"
#include "nauLogger.h"
#include "nauMesh.h"
#include "nauSceneManager.h"

namespace nauEngineSDK {

  bool
  UISystem::init(ImGuiIO& io, void* hwnd) {
    UNREFERENCED_PARAMETER(hwnd);
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
        if (ImGui::CollapsingHeader("Position")) {
          ImGui::SliderFloat("X", &m_gameObjectPtr->m_transform.m[0][3], -99.0f, 99.0f, "ratio = %.3f");
          ImGui::SliderFloat("Y", &m_gameObjectPtr->m_transform.m[1][3], -99.0f, 99.0f, "ratio = %.3f");
          ImGui::SliderFloat("Z", &m_gameObjectPtr->m_transform.m[2][3], -99.0f, 99.0f, "ratio = %.3f");
        }
        if (ImGui::CollapsingHeader("Scale")) {
          ImGui::SliderFloat("X", &m_gameObjectPtr->m_transform.m[0][0], 0.0f, 100, "ratio = %.3f");
          ImGui::SliderFloat("Y", &m_gameObjectPtr->m_transform.m[1][1], 0.0f, 100, "ratio = %.3f");
          ImGui::SliderFloat("Z", &m_gameObjectPtr->m_transform.m[2][2], 0.0f, 100, "ratio = %.3f");
        }
        if (ImGui::CollapsingHeader("Rotation")) {

          float rotationX;
          float rotationY;
          float rotationZ;

          ImGui::SliderFloat("X", &rotationX, 0.0f, 2* Math::PI, "ratio = %.3f");
          ImGui::SliderFloat("Y", &rotationY, 0.0f, 2* Math::PI, "ratio = %.3f");
          ImGui::SliderFloat("Z", &rotationZ, 0.0f, 2* Math::PI, "ratio = %.3f");

          //m_gameObjectPtr->m_transform.rotateX(rotationX);
          //m_gameObjectPtr->m_transform.rotateY(rotationY);
          //m_gameObjectPtr->m_transform.rotateZ(rotationZ);
        }
      }
      
      if (component->getType() == COMPONENT::MESH) {
        if (ImGui::CollapsingHeader("Mesh")) {
        }
      }

      if (component->getType() == COMPONENT::ANIMATOR) {
        if (ImGui::CollapsingHeader("Animator")) {
          auto anim = reinterpret_cast<AnimatorComponent*>(component);
          if (!anim->m->isPlaying()) {
            if (ImGui::SmallButton("Play")) {
              if (anim->m->getAnimations().size() > 0) {
                if (anim->m->getCurrentAnimation() == nullptr) { anim->m->setAnimation(0); }
                anim->m->play();
              }
            }
          }
          else {
            if (ImGui::SmallButton("Stop")) { anim->m->stop(); }
          }
          ImGui::Text("Animations");
          for (auto animName : anim->m->getAnimationNames() )
            if (ImGui::SmallButton(animName.c_str())) {
              anim->m->setAnimation(animName);
            }
            ImGui::Text("\n");
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

    String enterPressed = "";
    enterPressed += "Accumulated delta: ";
    enterPressed += std::to_string(m_accumulatedDelta);
    enterPressed.append("\n");
    ImGui::Text(enterPressed.c_str());

    Vector<float> color;
    color.resize(4, 0.0f);
    Vector4 cameraColor = CameraManager::instance().getActiveCamera()->m_clearColor.toVector4F();
    color[0] = cameraColor.x;
    color[1] = cameraColor.y;
    color[2] = cameraColor.z;
    color[3] = cameraColor.w;
    ImGui::ColorEdit4("Clear Color", color.data());
    
    CameraManager::instance().getActiveCamera()->m_clearColor.setColor(static_cast<float>(color[0]),
                                                                       static_cast<float>(color[1]), 
                                                                       static_cast<float>(color[2]),
                                                                       static_cast<float>(color[3]));

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