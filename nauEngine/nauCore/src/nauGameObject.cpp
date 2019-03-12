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

}