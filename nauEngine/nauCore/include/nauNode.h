/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauNode.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/30 2019
 * @brief SceneGraph Nodes are made for ordering the layers of objects in hierarchy
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauGameObject.h"


namespace nauEngineSDK {
  class Node
  {
  public:
  
    /**
     * Default constructor
     */
    Node() = default;
  
    /**
     * Default destructor
     */
    ~Node() = default;
  

    /**
     * @brief Gets the gameObject in this Node
     * @param 
     * @return the gameObject 
     *
     */
    GameObject*
    getGameObject();

    /**
     * @brief Sets the gameObject in the Node
     * @param the Object to save
     * @return 
     *
     */
    void
    setGameObject(GameObject* obj);

    /**
     * @brief Gets the vector of all the children in it
     * @param 
     * @return the vector of Nodes
     *
     */
    Vector<Node*>
    getChildren();

    /**
     * @brief Adds a vector of Nodes to the node
     * @param Vector<Node*> nodes
     * @return 
     *
     */
    void
    addChildren(Vector<Node*> nodes);

    /**
     * @brief Adds a node to the vector
     * @param Node* node
     * @return 
     *
     */
    void
    addChild(Node* node);

    /**
     * @brief Gets the children at a given position
     * @param the position of the vector
     * @return the node at the given position
     *
     */
    Node*
    getChild(int pos);

   private:
    /**
     * GameObject attached to the Node
     */
    GameObject* m_object = nullptr;

    /**
     * To save all Nodes as children
     */
    Vector<Node*> m_children;

  };
  
}

