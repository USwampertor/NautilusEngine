/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSceneManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/08/01 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauSceneManager.h"

namespace nauEngineSDK {

  void
  SceneManager::init() {

  }

  uint32
  SceneManager::getActiveSceneID() {
    for (uint32 i = 0; i < m_compilableScenes.size(); ++i) {
      if (m_compilableScenes[i] == m_activeScene) { return i; }
    }
#if NAU_DEBUG_MODE 
    Logger::instance().toIDE("Active scene is not in the build batch scenes!!!!", 
                             LOGGER_LEVEL::ERRORED);
#endif
    Logger::instance().toConsole("Active scene is not in the build batch scenes!!!!", 
                                 LOGGER_LEVEL::ERRORED);
    return 0;
  }

  String
  SceneManager::getActiveSceneName() {
    return m_activeScene->getName();
  }

  bool
  SceneManager::loadScene(uint32 ID) {

    NAU_ASSERT(ID < m_compilableScenes.size() && "ID is way bigger than the IDs registered!");

    m_activeScene = m_compilableScenes[ID];
    m_activeScene->init();
    return true;
  }

  bool
  SceneManager::loadScene(String name) {
    for (auto scene : m_projectScenes) {
      if (name == scene->getName()) { 
        m_activeScene = scene; 
        m_activeScene->init();
        return true;
      }
    }
#if NAU_DEBUG_MODE 
    Logger::instance().toIDE("There's no scene with the given name!!!!", 
                             LOGGER_LEVEL::ERRORED);
#endif
    Logger::instance().toConsole("There's no scene with the given name!!!!", 
                                 LOGGER_LEVEL::ERRORED);
    return false;
  }


}
