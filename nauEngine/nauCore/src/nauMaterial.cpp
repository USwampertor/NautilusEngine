/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMaterial.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/03 2019
 * @brief Material 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauMaterial.h"

namespace nauEngineSDK {

  void
  Material::load(String path) {

  }

  void
  Material::parse() {

  }

  Sptr<Texture>
  Material::getMap(MATERIAL_FLAG::E material) {
    return m_map[material];
  }

  void
  Material::setMap(Sptr<Texture> texture, MATERIAL_FLAG::E material) {

    if (m_map.find(material) != m_map.end()) {
      m_map.insert(std::make_pair(material, texture));
    }
    else {
      m_map[material] = texture;
    }
  }
}