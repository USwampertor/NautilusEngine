/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauQuaternion.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesUtil.h"

#include "nauMath.h"
#include "nauMatrix4.h"
#include "nauVector3.h"

namespace nauEngineSDK {
class NAU_UTILITY_EXPORT Quaternion {

 public:
  
  /**
   * Default constructor
   */
  Quaternion() = default;

  /**
   * @brief Constructor setting values x y z w
   * @param x component for the quaternion
   * @param y component for the quaternion
   * @param z component for the quaternion
   * @param w component for the quaternion
   * @return 
   * 
   */
  Quaternion(const float nx, const float ny, const float nz, const float nw) 
    : x(nx),
      y(ny),
      z(nz),
      w(nw) {}

  /**
   * @brief Constructor setting values w and x y z
   * @param float scale (w part of the quaternion)
   * @param Vector3 imaginary part. DEFAULT IS ZERO GIVING A REAL QUATERNION
   * @return 
   *
   */
  Quaternion(const float scale, const Vector3& imaginary = Vector3::ZERO)
    : x(imaginary.x),
      y(imaginary.y),
      z(imaginary.z),
      w(scale) {}

  /**
   * @brief Constructor setting values w and x y z
   * @param Vector3 imaginary part
   * @param float scale. DEFAULT IS ZERO GIVING A PURE QUATERNION
   * @return 
   *
   */
  Quaternion(const Vector3& imaginary, const float scale = 0.0f)
    : x(imaginary.x),
      y(imaginary.y),
      z(imaginary.z),
      w(scale) {}

  /**
   * @brief Copy constructor based up on another quaternion
   * @param the other quaternion to copy
   * @return 
   *
   */
  Quaternion(const Quaternion& other) {
    *this = other;
  }

  /**
   * @brief [] operator overload, will return the value at a given position
   * @param index of the object we wanna get
   * @return value at given index
   *
   */
  float&
  operator[](uint32 index);

  /**
   * @brief const [] operator overload, will return the value at a given position
   * @param index of the object we wanna get
   * @return value at given index
   *
   */
  float
  operator[](uint32 index) const;

  /**
   * @brief + operator overload
   * @param b the other matrix to add
   * @return a vector sum of *this and v
   *
   */
  Quaternion
  operator+(const Quaternion& other) const;
  
  /**
   * @brief - operator overload
   * @param b the other matrix to subtract
   * @return a vector difference of *this and v
   *
   */
  Quaternion
  operator-(const Quaternion& other) const;
  
  /**
   * @brief * operator overload
   * @param b the other matrix to multiply
   * @return a vector multiplication of *this times v
   *
   */
  Quaternion
  operator*(const Quaternion& other) const;
  
  /**
   * @brief / operator overload with quaternions
   * @param the quaternion to divide
   * @return a quaternion divided by another quaternion
   *
   */
  Quaternion
  operator/(const Quaternion& other) const;

  /**
   * @brief / operator overload
   * @param the scale to divide
   * @return a quaternion divided by scale
   *
   */
  Quaternion
  operator/(const float& scale) const;

  /**
   * @brief / operator overload
   * @param float the scale to multiply
   * @return a vector scaled by scale
   *
   */
  Quaternion
  operator*(const float& scale) const;
  
  /**
   * @brief == operator overload
   * @param the other vector to compare
   * @return true if this is == to v components
   *
   */
  bool
  operator==(const Quaternion& other);

  /**
   * @brief != operator overload
   * @param the other vector to compare
   * @return true if this is != to v components
   *
   */
  bool
  operator!=(const Quaternion& other);

  /**
   * @brief < operator overload
   * @param the other vector to compare
   * @return true if this components are < to v components
   *
   */
  bool
  operator<(const Quaternion& other);

  /**
   * @brief > operator overload
   * @param the other vector to compare
   * @return true if this components are > to v components
   *
   */
  bool
  operator>(const Quaternion& other);

  /**
   * @brief <= operator overload
   * @param the other vector to compare
   * @return true if this components are <= to v components
   *
   */
  bool
  operator<=(const Quaternion& other);

  /**
   * @brief >= operator overload
   * @param the other vector to compare
   * @return true if this components are >= to v components
   *
   */
  bool
  operator>=(const Quaternion& other);
  
  /**
   * @brief negates the whole quaternion
   * @param 
   * @return 
   *
   */
  Quaternion
  operator-() const;

  /**
   * @brief += operator overload
   * @param the other vector to add
   * @return *this + v components
   *
   */
  Quaternion&
  operator+=(const Quaternion& other);
  
  /**
   * @brief -= operator overload
   * @param the other vector to subtract
   * @return *this - v components
   *
   */
  Quaternion&
  operator-=(const Quaternion& other);
  
  /**
   * @brief *= operator overload
   * @param the other vector to multiply
   * @return *this * v components
   *
   */
  Quaternion&
  operator*=(const Quaternion& other);

  /**
   * @brief /= operator overload with quaternions
   * @param the other quaternion to divide
   * @return *this / q components
   *
   */
  Quaternion&
  operator/=(const Quaternion& other);

  /**
   * @brief *= operator overload
   * @param the float to scale the quaternion
   * @return *this * v components
   *
   */
  Quaternion&
  operator*=(float scale);
  
  /**
   * @brief /= operator overload
   * @param the float to scale the quaternion
   * @return *this / v components
   *
   */
  Quaternion&
  operator/=(float scale);
  
  /**
   * @brief | operator overload for dot product
   * @param the other vector
   * @return dot product
   *
   */
  float
  operator|(const Quaternion& v) const;
  
  /**
   * @brief returns the dot product of two quaternions
   * @param const Quaternion A
   * @param const Quaternion B
   * @return the float dot product of A and B
   *
   */
  static float
  dot(const Quaternion& a, const Quaternion& b);

  /**
   * @brief returns the scale of B over A
   * @param const Quaternion A
   * @param const Quaternion B
   * @return scale of B in A
   *
   */
  static float
  dotScale(const Quaternion& a, const Quaternion& b);

  /**
   * @brief gets the angle in radians between two quaternions
   * @param const Quaternion A
   * @param const Quaternion B
   * @return the angle in radians
   *
   */
  static float
  angularDifferenceRad(const Quaternion& a, const Quaternion& b);

  /**
   * @brief gets the angle in radians between two quaternions
   * @param const Quaternion A
   * @param const Quaternion B
   * @return the angle in radians
   *
   */
  static float
  angularDifferenceDeg(const Quaternion& a, const Quaternion& b);

  /**
   * @brief sets the values of the quaternion
   * @param float x
   * @param float y
   * @param float z
   * @param float w
   * @return 
   *
   */
  void
  setValues(float newX, float newY, float newZ, float newW);

  /**
   * @brief sets the value of the quaternion
   * @param float new W real side
   * @param Vector3 new imaginary side
   * @return 
   *
   */
  void
  setValues(float newW, Vector3 newImaginary);

  /**
   * @brief returns the conjugated version of the quaternion
   * @param 
   * @return the conjugated quaternion
   *
   */
  Quaternion
  conjugated() const;

  /**
   * @brief conjugates the quaternion
   * @param 
   * @return 
   *
   */
  void
  conjugate();

  /**
   * @brief gets the magnitude of the quaternion
   * @param 
   * @return float magnitude
   *
   */
  float
  magnitude() const;

  /**
   * @brief gets the square magnitude of the quaternion
   * @param 
   * @return float magnitude
   *
   */
  float
  sqrMagnitude() const;

  /**
   * @brief gets the normalized version of the quaternion
   * @param
   * @return the normalized quaternion
   *
   */
  Quaternion
  normalized() const;

  /**
   * @brief normalizes the quaternion
   * @param
   * @return
   *
   */
  void
  normalize();

  /**
   * @brief Converts the quaternion to a rotator quaternion
   * @param 
   * @return 
   *
   */
  void
  toNormRotator();

  /**
   * @brief Returns the normalized rotator version of the quaternion
   * @param 
   * @return the normalized rotator version
   *
   */
  Quaternion
  NormRotator();

  /**
   * @brief Returns the inverse of the quaternion
   * @param 
   * @return the inversed version of the quaternion
   *
   */
  Quaternion
  inversed();

  /**
   * @brief Inverses the quaternion
   * @param 
   * @return 
   *
   */
  void
  inverse();

  /**
   * @brief checks if the quaternion is pure
   *        a real quaternion is defined as a zero term real quaternion
   *        q = [x, y, z, w = 0]
   * @param 
   * @return true if pure
   *
   */
  bool
  isPure();

  /**
   * @brief checks if the quaternion is real
   *        a real quaternion is defined as a zero term imaginary quaternion
   *        q = [x = 0, y = 0, z = 0, w]
   * @param 
   * @return true if real
   *
   */
  bool
  isReal();

  /**
   * @brief Checks if the quaternion is (almost) the same as another quaternion
   * @param the quaternion A
   * @param the quaternion B
   * @param the quaternion the threshold. Default is Math::SMALLNUMBER
   * @return true if, given the threshold, are the same
   *
   */
  static bool
  isSame(const Quaternion& a, const Quaternion& b, float error = Math::SMALLNUMBER);

  /**
   * @brief Rotates an amount of rad angles around a given axis
   * @param theta angle to rotate
   * @param Vector3 vector to rotate
   * @param Vector3 around what axis
   * @return Vector3 rotated over axis
   * 
   */
  static Vector3
  rotateAroundDegrees(const float& theta, Vector3 toRotate, Vector3 axis);

  /**
   * @brief Rotates THIS quaternion over an axis
   * @param theta Degrees to rotate
   * @param axis over which it will rotate
   * @return
   *
   */
  void
  rotateAroundDegrees(const float& theta, Vector3 axis);

  /**
   * @brief Rotates THIS quaternion over an axis
   * @param theta Radians to rotate
   * @param axis over which it will rotate
   * @return 
   *
   */
  void
  rotateAroundRadians(const float& theta, Vector3 axis);

  /**
   * @brief Rotates an amount of rad angles around a given axis
   * @param theta angle to rotate
   * @param Vector3 vector to rotate
   * @param Vector3 around what axis
   * @return Vector3 rotated over axis
   * 
   */
  static Vector3
  rotateAroundRadians(const float& theta, Vector3 toRotate, Vector3 axis);

  /**
   * @brief Rotates an amount of x y z radians over the axis x y and z
   * @param Vector3 to rotate around those angles
   * @param float x radian angle to rotate over X axis
   * @param float y radian angle to rotate over Y axis
   * @param float z radian angle to rotate over Z axis
   * @return Vector3 rotated over the angles given
   *
   */
  static Vector3
  rotateEulerDegrees(Vector3 toRotate, float xAngle, float yAngle, float zAngle);

  /**
   * @brief Rotates an amount of x y z radians over the axis x y and z
   * @param Vector3 to rotate around those angles
   * @param float x radian angle to rotate over X axis
   * @param float y radian angle to rotate over Y axis
   * @param float z radian angle to rotate over Z axis
   * @return Vector3 rotated over the angles given
   *
   */
  static Vector3
  rotateEulerRadians(Vector3 toRotate, float xAngle, float yAngle, float zAngle);

  /**
   * @brief Creates a rotator quaternion to rotate a vector around it based on degrees
   * @param float x degree
   * @param float y degree
   * @param float z degree
   * @return 
   *
   */
  void
  setEulerDegrees(float newX, float newY, float newZ);

  /**
   * @brief Creates a rotator quaternion to rotate a vector around it based on radians
   * @param float x radians
   * @param float y radians
   * @param float z radians
   * @return 
   *
   */
  void
  setEulerRadians(float newX, float newY, float newZ);

  /**
   * @brief returns a vector filled with degrees in x y and z from the quaternion
   * @param 
   * @return 
   *
   */
  Vector3
  toEulerDegrees();

  /**
   * @brief returns a vector filled with degrees in x y and z from the quaternion
   * @param 
   * @return 
   *
   */
  Vector3
  toEulerRadians();

  /**
   * @brief returns the quaternion as a rotation Matrix
   * @param 
   * @return Matrix3 rotation Matrix 
   *
   */
  Matrix3
  rotationMatrix();

#ifdef PURE
# undef PURE
#endif

  /**
   * Pure quaternion definition
   */
  static const Quaternion PURE;

  /**
   * Real quaternion definition
   */
  static const Quaternion REAL;

  /**
   * Zero defined quaternion
   */
  static const Quaternion ZERO;

  /**
     * Vector3 that has x value 1
     */
  static const Quaternion RIGHT;

  /**
   * Vector3 with y value 1
   */
  static const Quaternion UP;

  /**
   * Vector3 with z value 1
   */
  static const Quaternion FRONT;

 public:

  /**
    * x (imaginary) component of the vector
    */
  float x;

  /**
   * y (imaginary) component of the vector
   */
  float y;

  /**
   * z (imaginary) component of the vector
   */
  float z;

  /**
   * w (real) component of the vector
   */
  float w;

};

}