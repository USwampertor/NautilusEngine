/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNode.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/01 2019
 * @brief Node implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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


  Node*
  Node::getChild(int pos) {
    return m_children[pos];
  }


  
}

