/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGameObject.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/02/22 2019
 * @brief GameObject implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauGameObject.h"

namespace nauEngineSDK {

  GameObject::GameObject(const GameObject& other) {
    m_transform = other.m_transform;
    for (uint32 i = 0; i < other.m_properties.size(); ++i) {
      m_properties.push_back(other.m_properties[i]);
    }
  }

  void
  GameObject::createComponent(COMPONENT::E type) {
    if (COMPONENT::MESH == type) {
      MeshComponent* m = new MeshComponent();
      m->m_model = new Model();
      m_properties.push_back(m);
    }
  }

  void
  GameObject::addComponent(Component* component) {
    m_properties.push_back(component);
  }

  Component*
  GameObject::getComponent(COMPONENT::E component) {
    for (auto com : m_properties) {
      if (component == com->getType()) { return com; }
    }
    return nullptr;
  }

  void
  GameObject::update(float deltaTime) {
    UNREFERENCED_PARAMETER(deltaTime);
    for (auto com : m_properties) {
      if (com->getType() == COMPONENT::MESH) {
        //reinterpret_cast<MeshComponent*>(com)->m_model->m_skeleton->m_root->m_worldPosition *= m_transform;
      }
    }
  }

}