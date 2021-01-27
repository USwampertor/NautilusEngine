/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauSceneGraph.h
 * @author Marco "Swampy" Millan
 * @date 2019/04/01 2019
 * @brief Scenegraph manages all gameObjects ingame
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#pragma once
#include "nauPrerequisitesCore.h"

#include "nauModule.h"
#include "nauNode.h"

namespace nauEngineSDK {
  class NAU_CORE_EXPORT SceneGraph : public Module<SceneGraph>
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
     * @brief initiates the SceneGraph
     * @param 
     * @return 
     *
     */
    void 
    init();

    /**
     * @brief Gets a Node with a specific Name of the gameObject
     * @param String ID
     * @return the Node with the GameObject
     *
     */
    Node*
    findChild(String id);
  
    /**
     * Sets a new child to the root
     */
    void
    set(Node* mNew);

    /**
     * @brief Sets a new node in the scene graph at a given location
     * @param newNode to insert, reference of Node to put, position to put it
     * @return 
     *
     */
    void
    setAt(Node* newNode, String referenceId, uint32 childLocation = 0);

    /**
     * @brief Returns all objects in the scene graph
     * @param 
     * @return Vector<Node*> all children GameObjects in nodes
     *
     */
    Vector<Node*>
    getSceneGameObjects();

    /**
     * @brief Gets all gameObject children in scene with a given parameter
     * @param Parameter type of filter
     * @return Vector<Node*> all filtered children GameObjects in nodes
     *
     */
    Vector<Node*>
    getFiltered();

  private:

    Node* m_sceneRoot = nullptr;

  };

}


