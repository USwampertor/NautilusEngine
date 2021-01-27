/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauComponent.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief member definition of several components
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauComponent.h"

namespace  nauEngineSDK {

  COMPONENT::E
  Component::getType() {
    return m_type;
  }

  Texture*
  MaterialComponent::getMaterial(MATERIAL_FLAG::E material) {
    return m_TextureMap[material];
  }

  void
  MaterialComponent::setMaterial(Texture* texture, MATERIAL_FLAG::E material) {
    m_TextureMap.insert(std::make_pair(material, texture));

    if (MATERIAL_FLAG::BASECOLOR == material) {
      m_base = true;
    }
    else if (MATERIAL_FLAG::NORMAL == material) {
      m_normal = true;
    }
    else if (MATERIAL_FLAG::EMISSIVE == material) {
      m_emissive = true;
    }
    else if (MATERIAL_FLAG::ROUGHNESS == material) {
      m_roughness = true;
    }
    else if (MATERIAL_FLAG::AMBIENT == material) {
      m_ambient = true;
    }
    else if (MATERIAL_FLAG::SPECULAR == material) {
      m_specular = true;
    }
    else if (MATERIAL_FLAG::METAL == material) {
      m_metal = true;
    }
    else {
      m_base = true;
    }

  }
}