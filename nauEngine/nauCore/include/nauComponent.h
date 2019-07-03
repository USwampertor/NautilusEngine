/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauComponent.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/26 2019
 * @brief Component class for gameObjects
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauMesh.h"
#include "nauModel.h"
#include "nauTexture.h"
#include "nauMaterial.h"

#include <nauMath.h>

namespace nauEngineSDK {

  namespace COMPONENT
  {
    enum E
    {
      MESH,
      COLLIDER,
      SOURCE
    };
  }

   /**
    * Component
    * Description:
    * 	A component is basically a gameObject Property. This helps define what
    *   things has a gameObject, from mesh, to collider, etc.
    * Sample usage:
    * 	A collider component for a box
    */
  class NAU_CORE_EXPORT Component
  {
   public:
    /**
     * Default constructor
     */
    Component() = default;
  
    /**
     * Default destructor
     */
    virtual ~Component() {}

    COMPONENT::E
    getType();

   private:

    /**
     * Component flag
     */
    COMPONENT::E m_type;

  };
  
  /**
   * Material
   * Description:
   *   Material Component for Meshes and GameObjects
   * Sample usage:
   *   Material.baseColor
   */
  class NAU_CORE_EXPORT MaterialComponent : public Component
  {
  public:
    /**
     * Default constructor
     */
    MaterialComponent() = default;

    /**
     * Default destructor
     */
    ~MaterialComponent() = default;

    /**
     * @brief retrieves the Texture of the Material given by the flag
     * @param
     * @return
     *
     */
    Texture*
    getMaterial(MATERIAL_FLAG::E material);

    /**
     * @brief Sets a Texture of the Material, if the object already has one, it
     *        replaces it
     * @param Texture* texture, MATERIAL_FLAG defining which texture
     * @return
     *
     */
    void
    setMaterial(Texture* texture, MATERIAL_FLAG::E material = MATERIAL_FLAG::DEFAULT);

    bool m_base, m_normal, m_emissive, m_roughness, m_ambient, m_specular, m_metal;
  
   private:

    /**
     * Map for storing all
     */
    Map<MATERIAL_FLAG::E, Texture*> m_TextureMap;

  };



  /**
   * MeshComponent
   * Description:
   *   A mesh in a gameObject
   * Sample usage:
   * 	Mesh can have any model or skeleton
   */
  class MeshComponent : public Component
  {
  public:

    /**
     * Default constructor
     */
    MeshComponent() = default;

    /**
     * Default destructor
     */
    ~MeshComponent() = default;

    /**
     * A mesh list, which is a model
     */
    Model* m_model;

  };

  class Collider : public Component
  {
   public:

    /**
     * Default constructor
     */
     Collider() = default;

    /**
     * Default destructor
     */
    ~Collider() = default;
  };

  class BoxCollider : public Collider
  {
    /**
     * Default constructor
     */
    BoxCollider() = default;

    /**
     * Default destructor
     */
    ~BoxCollider() = default;

    
  };


}

