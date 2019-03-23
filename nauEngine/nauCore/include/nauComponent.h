/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauComponent.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/26 2019
 * @brief Component class for gameObjects
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauMesh.h"
#include "nauModel.h"

#include <nauMath.h>

namespace nauEngineSDK {

  enum COMP_FLAG
  {
    MESH,
    COLLIDER,
    SOURCE
  };


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
    ~Component() = default;

   public:

    /**
     * Component flag
     */
    COMP_FLAG m_type;

  };
  
  /**
   * MeshComponent
   * Description:
   *   A mesh in a gameObject
   * Sample usage:
   * 	Mesh can have any model or skeleton
   */
  class NAU_CORE_EXPORT MeshComponent : public Component
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

  class NAU_CORE_EXPORT ColliderComponent : public Component
  {
   public:

    /**
     * Default constructor
     */
     ColliderComponent() = default;

    /**
     * Default destructor
     */
    ~ColliderComponent() = default;
  };

}

