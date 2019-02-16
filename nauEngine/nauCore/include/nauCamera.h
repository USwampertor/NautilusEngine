/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCamera.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauMatrix4.h"

namespace nauEngineSDK {

   /**
    * nauCamera
    * Description:
    * 	a nice camera for world implementation
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT Camera
  {
  public:
    /**
     * Default constructor
     */
    Camera() = default;
  
    /**
     * Constructor with parameters
     * Vector3 position of camera
     * Vector3 Direction of camera
     * Vector3 Up axis, the default is 0,1,0
     */
    Camera(Vector3 position, Vector3 direction, Vector3 up = Vector3::UP);

    /**
     * Default destructor
     */
    ~Camera() {}

    /**
     * @brief moves forward (or backward) the camera
     * @param float defaz, if negative, it'll go backward
     * @return 
     *
     */
    void
    moveForward(float defaz);

    /**
     * @brief rotates the view matrix in a specific axis and angle
     * @param vector axis to rotate, float angle in rads
     * @return 
     *
     */
    void
    rotate(Vector3 axis, float rads);

    /**
     * gets the View Matrix, and if theres no matrix, it builds it
     */
    void
    getView();

    /**
     * @brief Rotates around a position given by rad angles
     * @param vector objective, rad angles
     * @return 
     *
     */
    void
    orbit(Vector3 objective, float rads);

    /**
     * @brief Sets the position of the camera
     * @param Vector3 position
     * @return 
     *
     */
    void
    setPosition(Vector3 position);

    /**
     * @brief Sets the position of the camera
     * @param float x, float y and float z position in world
     * @return 
     *
     */
    void
    setPosition(float x, float y, float z);

    /**
     * @brief Sets the objective of the camera
     * @param Vector3 objective
     * @return
     *
     */
    void
    setObjective(Vector3 position);

    /**
     * @brief Sets the objetive of the camera
     * @param float x, float y and float z objective in world
     * @return
     *
     */
    void
    setObjective(float x, float y, float z);



  public:

    /**
     * Vector3 position
     */
    Vector3 m_position;

    /**
     * Vector3 right vector
     */
    Vector3 m_right;

    /**
     * Vector3 front vector
     */
    Vector3 m_front;

    /**
     * Vector3 up vector
     */
    Vector3 m_up;

    /**
     * View Matrix
     */
    Matrix4 m_view;
  };
  
}

