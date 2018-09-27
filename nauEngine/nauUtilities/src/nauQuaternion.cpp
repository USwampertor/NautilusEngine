#include "nauQuaternion.h"
namespace nauEngineSDK {

  nauQuaternion::nauQuaternion(const float nx, const float ny, const float nz, const float nw) 
    : x(nx),
      y(ny),
      z(nz),
      w(nw) {}
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator+(const nauQuaternion& other) const {
    return nauQuaternion(x + other.x, y + other.y, z + other.z, w + other.w);
  }
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator-(const nauQuaternion& other) const {
    return nauQuaternion(x - other.x, y - other.y, z - other.z, w - other.w);
  }
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator*(const nauQuaternion& other) const {
    return nauQuaternion(x * other.x, y * other.y, z * other.z, w * other.w);
  }
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator/(const nauQuaternion& other) const {
    return nauQuaternion(x / other.x, y / other.y, z / other.z, w / other.w);
  }

  FORCEINLINE bool
  nauQuaternion::operator==(const nauQuaternion& other) {
    return x == other.x && y == other.y && z == other.z && w == other.w;
  }

  FORCEINLINE bool
  nauQuaternion::operator<(const nauQuaternion& other) {
    return x < other.x && y < other.y && z < other.z && w < other.w;
  }

  FORCEINLINE bool
  nauQuaternion::operator>(const nauQuaternion& other) {
    return x > other.x && y > other.y && z > other.z && w > other.w;
  }

  FORCEINLINE bool
  nauQuaternion::operator<=(const nauQuaternion& other) {
    return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
  }

  FORCEINLINE bool
  nauQuaternion::operator>=(const nauQuaternion& other) {
    return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
  }

  FORCEINLINE nauQuaternion
  nauQuaternion::operator+=(const nauQuaternion& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator-=(const nauQuaternion& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator*=(const nauQuaternion& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
  }
  
  FORCEINLINE nauQuaternion
  nauQuaternion::operator/=(const nauQuaternion& other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
  }
  
  FORCEINLINE float
  nauQuaternion::operator|(const nauQuaternion& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
  }
  
  FORCEINLINE float
  nauQuaternion::operator^(const nauQuaternion& v) const {
    return x * v.x - y * v.y - z * v.z - w * v.w;
  }
  
  void
  nauQuaternion::RotateX(const float& theta) {
    x += theta;
  }
  
  void
  nauQuaternion::RotateY(const float& theta) {
    y += theta;
  }
  
  void
  nauQuaternion::RotateZ(const float& theta) {
    z += theta;
  }
}
