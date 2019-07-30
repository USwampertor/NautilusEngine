/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauQuaternion.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauMatrix4.h"

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
   * @brief Copy constructor based up on another quaternion
   * @param the other quaternion to copy
   * @return 
   *
   */
  Quaternion(const Quaternion& matrix) {
    *this = matrix;
  }

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
   * @brief / operator overload
   * @param b the other matrix to divide
   * @return a vector division of *this divided by v
   *
   */
  Quaternion
  operator/(const Quaternion& other) const;
  
  /**
   * @brief == operator overload
   * @param the other vector to compare
   * @return true if this components are == to v components
   *
   */
  bool
  operator==(const Quaternion& other);

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
   * @brief /= operator overload
   * @param the other vector to divide
   * @return *this / v components
   *
   */
  Quaternion&
  operator/=(const Quaternion& other);
  
  /**
  * @brief ^ operator overload for cross product
  * @param the other vector
  * @return cross product
  *
  */
  float
  operator^(const Quaternion& v) const;
  
  /**
   * @brief | operator overload for dot product
   * @param the other vector
   * @return dot product
   *
   */
  float
  operator|(const Quaternion& v) const;
  
  /**
   * @brief Rotation in X axis
   * @param theta angle to rotate
   * @return
   *
   */
  void
  RotateX(const float& theta);
  
  /**
   * @brief Rotation in Y axis
   * @param theta angle to rotate
   * @return
   *
   */
  void
  RotateY(const float& theta);
  
  /**
   * @brief Rotation in Z axis
   * @param theta angle to rotate
   * @return 
   * 
   */
  void
  RotateZ(const float& theta);
 
  /**
   * @brief Sets the quaternion based in Euler Degrees
   * @param float x degree
   * @param float y degree
   * @param float z degree
   * @return 
   *
   */
  void
  setEulerDegrees(float x, float y, float z);

  /**
   * @brief Sets the quaternion based in Euler Radians
   * @param float x radians
   * @param float y radians
   * @param float z radians
   * @return 
   *
   */
  void
  setEulerRadians(float x, float y, float z);

 public:

  /**
    * x component of the vector
    */
  float x;

  /**
   * y component of the vector
   */
  float y;

  /**
   * z component of the vector
   */
  float z;

  /**
   * w component of the vector
   */
  float w;

};

}