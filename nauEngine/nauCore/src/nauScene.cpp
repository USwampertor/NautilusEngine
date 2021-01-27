/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauScene.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauScene.h"


namespace nauEngineSDK {

  void
  Scene::init() {
    m_sceneGraph = new SceneGraph();
    m_sceneGraph->init();
  }

  SceneGraph*
  Scene::getSceneGraph() {
    return m_sceneGraph;
  }

  void
  Scene::saveScene(String path) {

  }

  String
  Scene::getName() {
    return m_name;
  }

  void
  Scene::setName(String newName) {
    m_name = newName;
  }

  bool
  Scene::load(String path) {


    return true;
  }

}