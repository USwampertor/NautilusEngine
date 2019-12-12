/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGameObject.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/22 2019
 * @brief GameObject, also known as actor, asset, etc.
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesCore.h"
#include "nauComponent.h"

#include <nauMatrix4.h>
#include <nauQuaternion.h>

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
  
    /**
     * @brief This function acts when the gameObject is created. You should 
     *        initialize things here
     * @param 
     * @return 
     *
     */
    virtual void
    init() {}

    /**
     * @brief Adds a component to the properties of the gameObject
     * @param The new Component in the vector
     * @return 
     *
     */
    void
    addComponent(Component* component);

    /**
     * @brief Gets a specific Component
     * @param COMPONENT FLAG
     * @return the component
     *
     */
    Component*
    getComponent(COMPONENT::E component);

    /**
     * @brief Creates a component from a specified type
     * @param COMPONENT::E Component
     * @return 
     *
     */
    void
    createComponent(COMPONENT::E type);

    /**
     * @brief Updates the game Object
     * @param deltaTime
     * @return 
     *
     */
    void
    update(float deltaTime);

  public:

    /**
     * Position of the gameObject in world space
     */
    Matrix4 m_transform;

    /**
     * The vector that saves the properties of the gameObject
     */
    Vector<Component*> m_properties;

    /**
     * Object Name
     */
    String m_id;

  };
  
}

