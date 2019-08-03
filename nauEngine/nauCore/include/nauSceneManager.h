/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSceneManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/08/01 2019
 * @brief Scene Manager instance object to manage load and save scenes
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauLogger.h"
#include "nauModule.h"
#include "nauScene.h"

namespace nauEngineSDK {
class SceneManager : public Module<SceneManager>
{
public:
  /**
   * Default constructor
   */
  SceneManager() = default;

  /**
   * Default destructor
   */
  ~SceneManager() = default;

  /**
   * @brief Initializes the Scene Manager
   * @param 
   * @return 
   *
   */
  void
  init();

  /**
   * @brief Returns the ID of the scene of the TO-BE-COMPILED vector of scenes
   * @param 
   * @return uint32 the scene ID
   *
   */
  uint32
  getActiveSceneID();

  /**
   * @brief Returns the name of the active scene
   * @param 
   * @return 
   *
   */
  String
  getActiveSceneName(); 

  /**
   * @brief Loads a scene with a given name
   * @param String name of the scene
   * @return 
   *
   */
  bool
  loadScene(String name);

  /**
   * @brief Loads a scene with a given ID
   * @param ID of the Scene in the TO-BE-COMPILED list
   * @return true if able to load
   *
   */
  bool
  loadScene(uint32 ID);

private:

  /**
   * The active scene being loaded and managed
   */
  Sptr<Scene> m_activeScene;

  /**
   * Vector of all scenes loaded in the project
   */
  Vector<Sptr<Scene>> m_projectScenes;

  /**
   * Vector of TO-BE-COMPILED scenes
   */
  Vector<Sptr<Scene>> m_compilableScenes;

};
}
