/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauRotator.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/05/18 2019
 * @brief Rotator member implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauQuaternion.h"
#include "nauVector3.h"
#include "nauRotator.h"
#include "nauMatrix4.h"

namespace nauEngineSDK {
  Rotator::Rotator(const Rotator& other) {
    m_yaw   = other.m_yaw;
    m_pitch = other.m_pitch;
    m_roll  = other.m_roll;
  }
  
  Rotator::Rotator(const Quaternion& quaternion) {
    *this = quaternion.toRotator();
  }
  
  
  
  Rotator
  Rotator::operator+(const Rotator& other) const {
    return Rotator(m_yaw + other.m_yaw, m_pitch + other.m_pitch, m_roll + other.m_roll);
  }
  
  Rotator
  Rotator::operator-(const Rotator& other) const {
    return Rotator(m_yaw + other.m_yaw, m_pitch + other.m_pitch, m_roll + other.m_roll);
  }
  
  Rotator
  Rotator::operator*(float scale) const {
    return Rotator(m_yaw * scale, m_pitch * scale, m_roll * scale);
  }
  
  bool
  Rotator::operator==(const Rotator& other) const {
    return m_yaw == other.m_yaw && m_pitch == other.m_pitch && m_roll == other.m_roll;
  }
  
  bool
  Rotator::operator!=(const Rotator& other) const {
    return m_yaw != other.m_yaw || m_pitch != other.m_pitch || m_roll != other.m_roll;
  }
  
  Rotator
  Rotator::operator+=(const Rotator& other) {
    m_yaw   += other.m_yaw;
    m_pitch += other.m_pitch;
    m_roll  += other.m_roll;
    return *this;
  }
  
  Rotator
  Rotator::operator-=(const Rotator& other) {
    m_yaw   -= other.m_yaw;
    m_pitch -= other.m_pitch;
    m_roll  -= other.m_roll;
    return *this;
  }
  
  Rotator
  Rotator::operator*=(float scale) {
    m_yaw   *= scale;
    m_pitch *= scale;
    m_roll  *= scale;
    return *this;
  }
  
  

  void
  Rotator::init() {
    m_yaw = 0.0f;
    m_pitch = 0.0f;
    m_roll = 0.0f;
  }
  
  Vector3
  Rotator::toVector3() const {

    float pitchSin = Math::sin(Math::degToRad(m_pitch));
    float pitchCos = Math::cos(Math::degToRad(m_pitch));


    float yawSin = Math::sin(Math::degToRad(m_yaw));
    float yawCos = Math::cos(Math::degToRad(m_yaw));

    return Vector3(pitchCos * yawCos, pitchCos * yawSin, pitchSin);
  }
  
  Quaternion
  Rotator::toQuaternion() const {
    float pitchSin  = Math::sin(Math::degToRad(m_pitch  * 0.5f));
    float yawSin    = Math::sin(Math::degToRad(m_yaw    * 0.5f));
    float rollSin   = Math::sin(Math::degToRad(m_roll   * 0.5f));

    float pitchCos  = Math::cos(Math::degToRad(m_pitch  * 0.5f));
    float yawCos    = Math::cos(Math::degToRad(m_yaw    * 0.5f));
    float rollCos   = Math::cos(Math::degToRad(m_roll   * 0.5f));

    Quaternion rotationQuaternion;

    rotationQuaternion.x =  rollCos * pitchSin * yawSin - rollSin * pitchCos * yawCos;
    rotationQuaternion.y = -rollCos * pitchSin * yawCos - rollSin * pitchCos * yawSin;
    rotationQuaternion.z =  rollCos * pitchCos * yawSin - rollSin * pitchSin * yawCos;
    rotationQuaternion.w =  rollCos * pitchCos * yawCos + rollSin * pitchSin * yawSin;

    return rotationQuaternion;
  }
  
  Vector3
  Rotator::toEuler() const {
    return Vector3(m_roll, m_pitch, m_yaw);
  }
  
  Rotator
  Rotator::fromEuler(const Vector3& euler) const {
    return Rotator(euler.z, euler.y, euler.x);
  }
  
  Rotator
  Rotator::clamp() const {
    return Rotator(clampAxis(m_yaw), clampAxis(m_pitch), clampAxis(m_roll));
  }

  float
  Rotator::clampAxis(float angle) {
    angle = Math::fmod(angle, 360.0f);

    return 0.0f > angle ? angle += 360.0f : angle;
  }

  Rotator
  Rotator::normalized() const {
    Rotator rotator = *this;
    rotator.normalize();
    return rotator;
  }
  
  void
  Rotator::normalize() {
    m_yaw   = normalizeAxis(m_yaw);
    m_pitch = normalizeAxis(m_pitch);
    m_roll  = normalizeAxis(m_roll);
  }

  float
  Rotator::normalizeAxis(float angle) {
    angle = clampAxis(angle);
    return 180.0f < angle ? angle -= 360.0f : angle;
  }
  
  Rotator
  Rotator::deNormalized() const {
    Rotator rotator = *this;
    rotator.deNormalize();
    return rotator;
  }
  
  void
  Rotator::deNormalize() {
    m_yaw   = clampAxis(m_yaw);
    m_pitch = clampAxis(m_pitch);
    m_roll  = clampAxis(m_roll);
  }
  
  Rotator
  Rotator::inverse() const {
    return toQuaternion().inversed().toRotator();
  }
  
  Vector3
  Rotator::rotate(const Vector3& vector) const {
    auto m = Matrix4();
    m.setTransformMatrix(Vector3::ZERO, *this);
    return m.getTransformVector(vector).toVector3();
  }
  
  Vector3
  Rotator::unrotate(const Vector3& vector) const {
    auto m = Matrix4();
    m.setTransformMatrix(Vector3::ZERO, *this);
    m.transpose();
    return m.getTransformVector(vector).toVector3();
  }
  
  float
  Rotator::getYaw() const {
    return m_yaw;
  }
  
  float
  Rotator::getPitch() const {
    return m_pitch;
  }
  
  float
  Rotator::getRoll() const {
    return m_roll;
  }
}