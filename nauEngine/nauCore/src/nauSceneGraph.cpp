/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauSceneGraph.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/01 2019
 * @brief Scenegraph member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
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

}