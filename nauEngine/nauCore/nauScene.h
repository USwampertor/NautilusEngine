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
class nauScene
{

public:
  /**
   * Default constructor
   */
  nauScene() = default;
  
  /**
   * Default destructor
   */
  ~nauScene() = default;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  SceneGraph*
  getSceneGraph() {
    return m_sceneGraph;
  }

private:

  SceneGraph* m_sceneGraph;

};

}


