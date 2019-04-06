/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSceneGraph.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/01 2019
 * @brief Scenegraph manages all gameObjects ingame
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "nauPrerequisitesCore.h"

#include "nauModule.h"
#include "nauNode.h"

namespace nauEngineSDK {
  class SceneGraph : public Module<SceneGraph>
  {
  public:
    /**
     * Default constructor
     */
    SceneGraph() = default;
  
    /**
     * Default destructor
     */
    ~SceneGraph() = default;

    /**
   * @brief Gets a Node with a specific Name of the gameObject
   * @param String ID
   * @return the Node with the GameObject
   *
   */
    Node*
    findChild(String id);
  

  private:

    Node* m_sceneRoot = nullptr;

  };

}


