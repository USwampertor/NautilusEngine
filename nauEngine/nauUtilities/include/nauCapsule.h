/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCapsule.h
 * @author Marco "Swampy" Millan
 * @date 6/11/2020
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"

namespace nauEngineSDK {

  /**
   * 
   * Description:
   * 	
   * Sample usage:
   * 	
   */
  class NAU_UTILITY_EXPORT Capsule
  {
  public:
    /**
     * Default Constructor
     */
    Capsule() = default;


    /**
     * Default destructor
     */
    ~Capsule() = default;


    /**
     * @brief Capsule with member definition
     * @param Vector3 a position of capsule sphere
     * @param Vector3 b position of capsule sphere
     * @param float distance between them
     * @return -
     *
     */
    Capsule(const Vector3& pointA, const Vector3& pointB, const float& radius);

    /**
     * @brief Constructor with other capsule reference
     * @param Capsule the reference
     * @return -
     *
     */
    Capsule(const Capsule& other);


    bool
    collidingCapsule(const Capsule& other);

    /**
     * Member definition
     */
  public:

    /**
     * Point A of the capsule
     */
    Vector3 m_A;

    /**
     * Point B of the capsule
     */
    Vector3 m_B;

    /**
     * The radius of the spheres
     */
    float m_radius;


  };

}