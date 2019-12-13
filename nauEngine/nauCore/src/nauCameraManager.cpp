/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCameraManager.cpp
 * @author Marco "Swampy" Millan
 * @date 12/5/2019
 * @brief Member defintion for the Camera Manager
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauCameraManager.h"

namespace nauEngineSDK {

  void
  CameraManager::init() {
    Camera* camera = new Camera(Vector3(0.0f, 100.0f, -100.0f),
                                Vector3(0.0f, 100.0f, 0.0f));
    m_cameraList.push_back(camera);
    m_activeCamera = m_cameraList[0];

    m_cameraSpeed = 4.0f;
  }

  Camera*
  CameraManager::getActiveCamera() {
    return m_activeCamera;
  }

  void
  CameraManager::addCamera(Camera* camPtr) {
    m_cameraList.push_back(camPtr);
  }

  void
  CameraManager::transition(Camera* originCam, Camera* destinyCam, float time) {
    UNREFERENCED_PARAMETER(originCam);
    UNREFERENCED_PARAMETER(destinyCam);
    UNREFERENCED_PARAMETER(time);
  }

  Matrix4
  CameraManager::getActiveView() {
    return m_activeCamera->getView();
  }

  Matrix4
  CameraManager::getViewMatrix(uint32 id) {
    if (id < m_cameraList.size()) { return m_cameraList[id]->getView(); }
    return m_activeCamera->getView();
  }

  void
  CameraManager::changeActiveCamera(uint32 id) {
    if (id < m_cameraList.size()) { m_activeCamera = m_cameraList[id]; }
  }
}