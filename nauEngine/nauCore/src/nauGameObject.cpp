/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauGameObject.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/02/22 2019
 * @brief GameObject implementation
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauGameObject.h"

namespace nauEngineSDK {

  GameObject::GameObject(const GameObject& other) {
    for (int i = 0; i < other.m_properties.size(); ++i) {
      m_properties.push_back(other.m_properties[i]);
    }
  }

}