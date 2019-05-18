/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauQuaternion.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauQuaternion member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauQuaternion.h"

namespace nauEngineSDK {

  Quaternion::Quaternion(const float nx, const float ny, const float nz, const float nw) 
    : x(nx),
      y(ny),
      z(nz),
      w(nw) {}
  
  Quaternion
  Quaternion::operator+(const Quaternion& other) const {
    return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
  }
  
  Quaternion
  Quaternion::operator-(const Quaternion& other) const {
    return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
  }
  
  Quaternion
  Quaternion::operator*(const Quaternion& other) const {
    return Quaternion(x * other.x, y * other.y, z * other.z, w * other.w);
  }
  
  Quaternion
  Quaternion::operator/(const Quaternion& other) const {
    return Quaternion(x / other.x, y / other.y, z / other.z, w / other.w);
  }

  bool
  Quaternion::operator==(const Quaternion& other) {
    return x == other.x && y == other.y && z == other.z && w == other.w;
  }

  bool
  Quaternion::operator<(const Quaternion& other) {
    return x < other.x && y < other.y && z < other.z && w < other.w;
  }

  bool
  Quaternion::operator>(const Quaternion& other) {
    return x > other.x && y > other.y && z > other.z && w > other.w;
  }

  bool
  Quaternion::operator<=(const Quaternion& other) {
    return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
  }

  bool
  Quaternion::operator>=(const Quaternion& other) {
    return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
  }

  Quaternion&
  Quaternion::operator+=(const Quaternion& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }
  
  Quaternion&
  Quaternion::operator-=(const Quaternion& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }
  
  Quaternion&
  Quaternion::operator*=(const Quaternion& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
  }
  
  Quaternion&
  Quaternion::operator/=(const Quaternion& other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
  }
  
  float
  Quaternion::operator|(const Quaternion& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
  }
  
  float
  Quaternion::operator^(const Quaternion& v) const {
    return x * v.x - y * v.y - z * v.z - w * v.w;
  }
  
  void
  Quaternion::RotateX(const float& theta) {
    x += theta;
  }
  
  void
  Quaternion::RotateY(const float& theta) {
    y += theta;
  }
  
  void
  Quaternion::RotateZ(const float& theta) {
    z += theta;
  }
}
