/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauComponent.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/26 2019
 * @brief Component class for gameObjects
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauAnimator.h"
#include "nauMaterial.h"
#include "nauMesh.h"
#include "nauModel.h"
#include "nauResourceManager.h"
#include "nauTexture.h"
#include "nauCamera.h"
#include "nauTransform.h"

#include <nauMath.h>

namespace nauEngineSDK {

  namespace COMPONENT
  {
    enum E
    {
      TRANSFORM,
      MESH,
      COLLIDER,
      SOURCE,
      ANIMATOR,
      MATERIAL,
      CAMERA
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

    virtual COMPONENT::E
    getType() = 0;

   private:

    /**
     * Component flag
     */
    COMPONENT::E m_type;

  };

  class NAU_CORE_EXPORT TransformComponent : public Component
  {
  public:

    Vector3
    getLocalPosition();

    Vector3
    getWorldPosition();

    Quaternion
    getWorldRotation();

    Quaternion
    getLocalRotation();

    Vector3
    getLocalScale();

    Vector3
    getWorldScale();

    /**
     * Default constructor
     */
    TransformComponent() = default;

    /**
     * Default destructor
     */
    ~TransformComponent() = default;

    Transform* m;


    virtual COMPONENT::E
    getType() override { return COMPONENT::TRANSFORM; }
  };

  class NAU_CORE_EXPORT CameraComponent : public Component
  {
  public:
    /**
     * Default constructor
     */
    CameraComponent() = default;

    /**
     * Default destructor
     */
    ~CameraComponent() = default;

    Camera* m_camera;

    virtual COMPONENT::E
    getType() override { return COMPONENT::CAMERA; }

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
  
    virtual COMPONENT::E
    getType() override { return COMPONENT::MATERIAL; }
   
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

    virtual COMPONENT::E
    getType() override { return COMPONENT::MESH; }

  };

  class AnimatorComponent : public Component
  {
  public:
    AnimatorComponent() = default;

    ~AnimatorComponent() = default;

    Sptr<Animachine> m;

    virtual COMPONENT::E
    getType() override { return COMPONENT::ANIMATOR; }
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

    virtual COMPONENT::E
    getType() override { return COMPONENT::COLLIDER; }
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

