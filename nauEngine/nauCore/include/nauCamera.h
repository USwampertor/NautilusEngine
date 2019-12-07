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

#include <nauMatrix4.h>
#include <nauQuaternion.h>

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
     * Vector3 Front axis, the default is 0,0,1. Should be orthogonal to up
     * Vector3 Up axis, the default is 0,1,0. Should be orthogonal to front
     */
    Camera(Vector3 position, 
           Vector3 objective  = Vector3::FRONT, 
           Vector3 up         = Vector3::UP, 
           float fNear        = 0.01f, 
           float fFar         = 1000.0f, 
           float fov          = Math::degToRad(90.0f)) {
     
      m_position      = position;
      m_objective     = objective;
      m_up            = up;
      m_near          = fNear;
      m_far           = fFar;
      m_fov           = fov;
      createView();
    }

    /**
     * Default destructor
     */
    ~Camera() = default;

    /**
     * @brief moves forward (or backward) the camera
     * @param float defaz, if negative, it'll go backward
     * @return 
     *
     */
    void
    moveForward(float defaz);

    /**
     * @brief moves right (or left) the camera
     * @param float defaz, if negative, it'll go left
     * @return
     *
     */
    void
    moveRight(float defaz);

    /**
     * @brief moves up (or down) the camera
     * @param float defaz, if negative, it'll go down
     * @return 
     *
     */
    void
    moveUp(float defaz);

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
    Matrix4
    getView();

    /**
     * creates the View Matrix
     */
    void
    createView();

    /**
     * @brief Rotates around a position given by rad angles
     * @param vector objective, the axis to rotate around rad angles
     * @return 
     *
     */
    void
    orbit(Vector3 objective, Vector3 axis, float rads);

    /**
     * @brief 
     * @param 
     * @return 
     *
     */

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
     * @brief Sets the objective of the camera
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
     * An objective that can be setted by 
     */
    Vector3 m_objective;

    /**
     * View Matrix
     */
    Matrix4 m_view;

    /**
     * Checks if the camera changed, if so, it tells the camera it has to recreate
     * the view matrix
     */
    bool m_dirty;

    /**
     * The far screen position
     */
    float m_far;

    /**
     * The near screen position
     */
    float m_near;

    /**
     * The FOV of the camera
     */
    float m_fov;

  };
  
}

