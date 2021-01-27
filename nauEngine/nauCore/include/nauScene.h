/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauScene.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief Scene object similar to those in Unity or Unreal
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauSceneGraph.h"

#include "nauResource.h"

namespace nauEngineSDK {
class Scene : public Resource
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
   * Copy constructor
   */
  Scene(const Scene& other) 
    : m_sceneGraph(other.m_sceneGraph),
      m_name(other.m_name) {}

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
   * @return String name of the scene
   *
   */
  String
  getName();

  virtual RESOURCETYPE::E
  getType() override { return RESOURCETYPE::SCENE; }

  virtual bool
  load(String path) override;

public:

  SceneGraph* m_sceneGraph = nullptr;

private:
  String m_name;

};
}


