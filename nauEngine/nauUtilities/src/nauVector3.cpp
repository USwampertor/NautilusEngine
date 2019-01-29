/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector3.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauVector3 member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauVector3.h"

namespace nauEngineSDK {

  /**
   * Method Implementation
   */

  Vector3::Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

  float&
  Vector3::operator[](uint32 index) {
    return (&x)[index];
  }

  float
  Vector3::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE Vector3
   Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
  }

  FORCEINLINE Vector3
  Vector3::operator-(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }

  FORCEINLINE Vector3
  Vector3::operator*(const Vector3& v) const {
    return Vector3(x * v.x, y * v.y, z * v.z);
  }

  FORCEINLINE Vector3
  Vector3::operator/(const Vector3& v) const {
    return Vector3(x / v.x, y / v.y, z / v.z);
  }

  FORCEINLINE Vector3
  Vector3::operator+(float plus) const {
    return Vector3(x + plus, y + plus, z + plus);
  }

  FORCEINLINE Vector3
  Vector3::operator-(float minus) const {
    return Vector3(x - minus, y - minus, y - minus);
  }

  FORCEINLINE Vector3
  Vector3::operator*(float times) const {
    return Vector3(x * times, y * times, z * times);
  }

  FORCEINLINE Vector3
  Vector3::operator/(float under) const {
    return Vector3(x / under, y / under, z / under);
  }

  FORCEINLINE float
  Vector3::operator|(const Vector3 v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  FORCEINLINE float
  Vector3::operator^(const Vector3 v) const {
    return x * v.x - y * v.y - z * v.z;
  }

  bool
  Vector3::operator==(const Vector3& v) const {
    return x == v.x && y == v.y && z == v.z;
  }

  bool
  Vector3::operator!=(const Vector3& v) const {
    return x != v.x || y != v.y || z == v.z;
  }

  bool
  Vector3::operator<(const Vector3& v) const {
    return x < v.x && y < v.y && z < v.z;
  }

  bool
  Vector3::operator>(const Vector3& v) const {
    return x > v.x && y > v.y && z > v.z;
  }

  bool
  Vector3::operator<=(const Vector3& v) const {
    return x <= v.x && y <= v.y && z <= v.z;
  }

  bool
  Vector3::operator>=(const Vector3& v) const {
    return x >= v.x && y >= v.y && z >= v.z;
  }

  FORCEINLINE Vector3
  Vector3::operator-() const {
    return Vector3(-x, -y, -z);
  }

  Vector3&
  Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vector3&
  Vector3::operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  
  Vector3&
  Vector3::operator*=(const Vector3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  Vector3&
  Vector3::operator/=(const Vector3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  Vector3&
  Vector3::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
  }

  Vector3&
  Vector3::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    return *this;
  }

  FORCEINLINE float
  Vector3::dot(const Vector3& a, const Vector3& b) {
    return a | b;
  }

  FORCEINLINE float
  Vector3::cross(const Vector3& a, const Vector3& b) {
    return a ^ b;
  }

  FORCEINLINE float
  Vector3::dotScale(const Vector3& a, const Vector3& b) {
    return (a | b) / nauMath::sqr(a.magnitude());
  }

  float
  Vector3::sqrDistance(const Vector3& a, const Vector3& b) {
    return nauMath::sqr(a.x - b.x) +
           nauMath::sqr(a.y - b.y) +
           nauMath::sqr(a.z - b.z);
  }

  FORCEINLINE float
  Vector3::distance(const Vector3& a, const Vector3& b) {
    return 
      nauMath::sqrt(nauMath::sqr(a.x - b.x) +
                    nauMath::sqr(a.y - b.y) +
                    nauMath::sqr(a.z - b.z));
  }

  void
  Vector3::setValues(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
  }

  void
  Vector3::min(const Vector3& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
    if (v.z < z) z = v.z;
  }

  void
  Vector3::max(const Vector3& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
    if (v.z > z) z = v.z;
  }

  void
  Vector3::floor() {
    x = nauMath::floor(x);
    y = nauMath::floor(y);
    z = nauMath::floor(z);
  }

  void
  Vector3::ceiling() {
    x = nauMath::ceil(x);
    y = nauMath::ceil(y);
    z = nauMath::ceil(z);
  }

  void
  Vector3::round() {
    x = nauMath::round(x);
    y = nauMath::round(y);
    z = nauMath::round(z);
  }

  void
  Vector3::roundHalf() {
    x = nauMath::roundHalf(x);
    y = nauMath::roundHalf(y);
    z = nauMath::roundHalf(z);
  }

  float
  Vector3::getHighest() const {
    return nauMath::max3(x, y, z);
  }

  float
  Vector3::getLowest() const {
    return nauMath::min3(x, y, z);
  }

  float
  Vector3::magnitude() const {
    return nauMath::sqrt(x * x + y * y + z * z);
  }

  float
  Vector3::sqrMagnitude() const {
    return (x * x + y * y + z * z);
  }

  FORCEINLINE Vector3
  Vector3::normalized() {
    float unit = nauMath::invSqrt(x*x + y * y + z * z);
    return Vector3((x * unit), (y * unit), (z * unit));
  }

  void
  Vector3::normalize() const {

  }

  bool
  Vector3::isZero() const {
    return 0.0f == x && 0.0f == y && 0.0f == z;
  }
  
  const Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);

  const Vector3 Vector3::ONES = Vector3(1.0f, 1.0f, 1.0f);

  const Vector3 Vector3::ONEX = Vector3(1.0f, 0.0f, 0.0f);

  const Vector3 Vector3::ONEY = Vector3(0.0f, 1.0f, 0.0f);

  const Vector3 Vector3::ONEZ = Vector3(0.0f, 0.0f, 1.0f);

}
