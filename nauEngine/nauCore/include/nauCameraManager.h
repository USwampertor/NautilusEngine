/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCameraManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/01/31 2019
 * @brief The camera manager of the application
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "nauPrerequisitesCore.h"
#include "nauCamera.h"
#include <nauModule.h>

namespace nauEngineSDK {
   /**
    * CameraManager
    * Description:
    * 	Manages, stores and keeps up with the cameras in the session
    * Sample usage:
    * 	You can make a nice interpolation with this
    */
  class NAU_CORE_EXPORT CameraManager : public Module<CameraManager>
  {
  public:

    /**
     * Default Constructor
     */
    CameraManager() = default;

    /**
     * Default destructor
     */
    ~CameraManager() = default;

    /**
     * @brief Interpolates from A Camera to B Camera in an amount of time
     * @param Camera Origin, Camera Destiny, time to interpolate
     * @return 
     *
     */
    void
    transition(Camera* originCam, Camera* destinyCam, float time);

    /**
     * @brief Gets the view matrix of the active camera, its a getViewMatrix but
     * static
     * @param 
     * @return the view matrix of the active camera 
     *
     */
    Matrix4
    getActiveView();

    /**
     * @brief Gets the view Matrix of any camera stored in the camera manager
     * @param the ID of the camera
     * @return the view matrix of ID camera
     *
     */
    Matrix4
    getViewMatrix( String id);

  private:

    /**
     * List of all generated cameras in the session
     */
    Vector<Camera> m_cameraList;

    /**
     * Pointer to active camera
     */
    Camera* m_activeCamera;

    /**
     * Pointer to initial camera
     */
    Camera* m_initialCamera;

    /**
     *´Pointer to objective Camera
     */
    Camera* m_objectiveCamera;

    /**
     * Pointer to DEBUG camera
     */
    Camera* m_debugCamera;

  };
}
