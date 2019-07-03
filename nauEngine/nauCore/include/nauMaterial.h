/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMaterial.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/03 2019
 * @brief Material core object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauTexture.h"

namespace nauEngineSDK {


/**
 * The system to control how the textures are loaded
 */
namespace MATERIAL_FLAG {
  enum NAU_CORE_EXPORT E {
    BASECOLOR = 0,              // Base Color (Albedo) Lightning
    NORMAL = 1,              // Normal Mapping
    EMISSIVE = 2,              // Emissive Lightning
    ROUGHNESS = 3,              // Roughness Lightning
    AMBIENT = 4,              // Ambient Lightning
    METAL = 5,              // Metal mapping
    SPECULAR = 6,              // Specular mapping
    DEFAULT = BASECOLOR,      // Default should redirect to Base color
  };
}

class Material
{
public:

  /**
   * Default constructor
   */
  Material() = default;

  /**
   * Default destructor
   */
  ~Material() = default;

  /**
   * @brief   loads a material in a given path, it will try to find all textures 
   *          of the material
   * @param   String path of the material
   * @return  the material with as much textures it could find, 
   *          null if it didn't find a material
   */
  void
  load(String path);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  parse();

  Sptr<Texture>
  getMap(MATERIAL_FLAG::E map);

  void
  setMap(Sptr<Texture> texture, MATERIAL_FLAG::E map = MATERIAL_FLAG::DEFAULT);

private:
  Map<MATERIAL_FLAG::E, Sptr<Texture>> m_map;
};
}


