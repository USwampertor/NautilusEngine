/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauGameObject.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/22 2019
 * @brief GameObject, also known as actor, asset, etc.
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#pragma once
#include "nauPrerequisitesCore.h"
#include "nauComponent.h"

#include <nauVector3.h>

namespace nauEngineSDK {
   /**
    * GameObject
    * Description:
    * 	the objects placed in the world
    * Sample usage:
    * 	gameobject can be a mesh
    */
  class NAU_CORE_EXPORT GameObject
  {
   public:
    /**
     * Default Constructor
     */
    GameObject() = default;

    /**
     * @brief GameObject constructor based in a copy 
     * @param GameObject other
     * @return 
     *
     */
    GameObject(const GameObject& other);


    /**
     * Default destructor
     */
    ~GameObject() = default;
  
  public:

    /**
     * Position of the gameObject in world space
     */
    Vector3 m_position;

    /**
     * The vector that saves the properties of the gameObject
     */
    Vector<Component*> m_properties;

  };
  
}

