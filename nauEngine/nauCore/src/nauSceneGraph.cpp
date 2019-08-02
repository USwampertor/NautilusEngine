/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSceneGraph.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/01 2019
 * @brief Scenegraph member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauSceneGraph.h"



namespace nauEngineSDK {

  Node*
  SceneGraph::findChild(String id) {
    
    Vector<Node*> openList;
    Node* actualNode = new Node();

    bool searching = true;

    openList = m_sceneRoot->getChildren();
    //This while is for checking if we are still searching

    while (searching) {
      if (!openList.empty()) {
        actualNode = openList.front();
        openList.erase(openList.begin());

        if (id == actualNode->getGameObject()->m_id) return actualNode;
        openList.insert(openList.end(),
                        actualNode->getChildren().begin(),
                        actualNode->getChildren().end());
      }
      else { searching = false; }
    }
    return nullptr;
  }

  /**
     * Sets a new child to the root
     */
  void
  SceneGraph::set(Node* mNew) {
    m_sceneRoot->addChild(mNew);
  }

  /**
   * Sets a child at a given location
   */
  void
  SceneGraph::setAt(Node* newNode, String referenceId, uint32 childLocation) {
    Vector<Node*> openList;
    Node* actualNode = new Node();

    bool searching = true;

    openList = m_sceneRoot->getChildren();
    //This while is for checking if we are still searching

    while (searching) {
      if (!openList.empty()) {
        actualNode = openList.front();
        openList.erase(openList.begin());

        if (referenceId == actualNode->getGameObject()->m_id) {
          actualNode->addChildAt(newNode, childLocation);
          return;
        }
        openList.insert(openList.end(),
                        actualNode->getChildren().begin(),
                        actualNode->getChildren().end());
      }
      else { searching = false; }
    }
    if (!searching) { throw::std::exception("Didn't find the given object"); }
  }

  void
  SceneGraph::init() {
    m_sceneRoot = new Node();
    m_sceneRoot->setGameObject(nullptr);
  }

  Vector<Node*>
  SceneGraph::getSceneGameObjects() {
    return m_sceneRoot->getAllChildren();
  }

  Vector<Node*>
  SceneGraph::getFiltered() {
    return m_sceneRoot->getAllChildren();
  }

}