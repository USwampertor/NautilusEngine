/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauScene.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief Scene object similar to those in Unity or Unreal
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauSceneGraph.h"

namespace nauEngineSDK {
class Scene
{

public:
  /**
   * Default constructor
   */
  Scene() = default;
  
  /**
   * Default destructor
   */
  ~Scene() = default;

  /**
   * @brief Initializes the scene
   * @param 
   * @return 
   *
   */
  void
  init();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  SceneGraph*
  getSceneGraph();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  loadScene(String path);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  saveScene(String path);

  /**
   * @brief Sets the name of the scene
   * @param String name of the scene
   * @return 
   *
   */
  void
  setName(String newName);

  /**
   * @brief Returns the name of the scene
   * @param 
   * @return String nameof the scene
   *
   */
  String
  getName();

private:

  SceneGraph* m_sceneGraph = nullptr;

  String m_name;

};
}


