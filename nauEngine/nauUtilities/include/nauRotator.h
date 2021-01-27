/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauRotator.h
 * @author Marco "Swampy" Millan
 * @date 2019/05/18 2019
 * @brief Rotator component for quaternions
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesUtil.h"

namespace nauEngineSDK {
  
  class Quaternion;
  class Vector3;
  class Matrix4;

  /**
   * 
   * Description: A catalyst for Quaternions and quaternion rotations and etc
   * 	
   * Sample usage:
   * 	
   */
  class Rotator
  {
  public:

    Rotator() = default;

    ~Rotator() = default;

    Rotator(float newYaw, float newPitch, float newRoll)
      : m_yaw(newYaw),
        m_pitch(newPitch),
        m_roll(newRoll) {}

    Rotator(const Rotator& other);

    Rotator(const Quaternion& quaternion);



    Rotator
    operator+(const Rotator& other) const;

    Rotator
    operator-(const Rotator& other) const;

    Rotator
    operator*(float scale) const;

    bool
    operator==(const Rotator& other) const;

    bool
    operator!=(const Rotator& other) const;

    Rotator
    operator+=(const Rotator& other);

    Rotator
    operator-=(const Rotator& other);

    Rotator
    operator*=(float scale);



    void
    init();

    Vector3
    toVector3() const;

    Quaternion
    toQuaternion() const;

    Vector3
    toEuler() const;

    Rotator
    fromEuler(const Vector3& euler) const;

    Rotator
    clamp() const;

    static float
    clampAxis(float angle);

    Rotator
    normalized() const;

    void
    normalize();

    static float
    normalizeAxis(float angle);

    Rotator
    deNormalized() const;

    void
    deNormalize();

    Rotator
    inverse() const;

    Vector3
    rotate(const Vector3& vector) const;

    Vector3
    unrotate(const Vector3& vector) const;

    float
    getYaw() const;

    float
    getPitch() const;

    float
    getRoll() const;


  public:

    /**
     *
     */
    float m_roll;

    /**
     * 
     */
    float m_pitch;

    /**
     *
     */
    float m_yaw;
  };
}