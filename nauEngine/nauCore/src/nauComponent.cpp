/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauComponent.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/06 2019
 * @brief member definition of several components
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauComponent.h"

namespace  nauEngineSDK {

  COMPONENT::E
  Component::getType() {
    return m_type;
  }

  Texture*
  Material::getMaterial(MATERIAL_FLAG::E material) {
    return m_TextureMap[material];
  }

  void
  Material::setMaterial(Texture* texture, MATERIAL_FLAG::E material) {
    m_TextureMap.insert(std::make_pair(material, texture));
  }
}