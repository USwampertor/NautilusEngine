/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauNode.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/01 2019
 * @brief Node implementation
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauNode.h"

namespace nauEngineSDK {


  GameObject*
  Node::getGameObject() {
    return m_object;
  }


  void
  Node::setGameObject(GameObject* obj) {
    m_object = obj;
  }


  Vector<Node*>
  Node::getChildren() {
    return m_children;
  }


  void
  Node::addChildren(Vector<Node*> nodes) {
    m_children.insert(m_children.end(), nodes.begin(), nodes.end());
  }


  void
  Node::addChild(Node* node) {
    m_children.push_back(node);
  }

  void
  Node::addChildAt(Node* node, uint32 at) {

    if (at > m_children.size()) {
      m_children.push_back(node);
      return;
    }
    m_children.insert(m_children.begin() + at, node);
  }

  Node*
  Node::getChild(uint32 pos) {
    return m_children[pos];
  }

  Vector<Node*>
  Node::getAllChildren() {
    Vector<Node*> allChildren;
    for (auto child : m_children) {
      allChildren.push_back(child);
      Vector<Node*> thisChildChildren = child->getAllChildren();
      allChildren.insert(allChildren.end(), 
                         thisChildChildren.begin(), 
                          thisChildChildren.end());
    }
    return allChildren;
  }
  
}

