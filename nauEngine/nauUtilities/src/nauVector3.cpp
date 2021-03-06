/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauVector3.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauVector3 member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "nauVector3.h"

namespace nauEngineSDK {

  /**
   * Method Implementation
   */

  nauVector3::nauVector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

  float&
  nauVector3::operator[](uint32 index) {
    return (&x)[index];
  }

  float
  nauVector3::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE nauVector3
   nauVector3::operator+(const nauVector3& v) const {
    return nauVector3(x + v.x, y + v.y, z + v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator-(const nauVector3& v) const {
    return nauVector3(x - v.x, y - v.y, z - v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator*(const nauVector3& v) const {
    return nauVector3(x * v.x, y * v.y, z * v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator/(const nauVector3& v) const {
    return nauVector3(x / v.x, y / v.y, z / v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator+(float plus) const {
    return nauVector3(x + plus, y + plus, z + plus);
  }

  FORCEINLINE nauVector3
  nauVector3::operator-(float minus) const {
    return nauVector3(x - minus, y - minus, y - minus);
  }

  FORCEINLINE nauVector3
  nauVector3::operator*(float times) const {
    return nauVector3(x * times, y * times, z * times);
  }

  FORCEINLINE nauVector3
  nauVector3::operator/(float under) const {
    return nauVector3(x / under, y / under, z / under);
  }

  FORCEINLINE float
  nauVector3::operator|(const nauVector3 v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  FORCEINLINE float
  nauVector3::operator^(const nauVector3 v) const {
    return x * v.x - y * v.y - z * v.z;
  }

  bool
  nauVector3::operator==(const nauVector3& v) const {
    return x == v.x && y == v.y && z == v.z;
  }

  bool
  nauVector3::operator!=(const nauVector3& v) const {
    return x != v.x || y != v.y || z == v.z;
  }

  bool
  nauVector3::operator<(const nauVector3& v) const {
    return x < v.x && y < v.y && z < v.z;
  }

  bool
  nauVector3::operator>(const nauVector3& v) const {
    return x > v.x && y > v.y && z > v.z;
  }

  bool
  nauVector3::operator<=(const nauVector3& v) const {
    return x <= v.x && y <= v.y && z <= v.z;
  }

  bool
  nauVector3::operator>=(const nauVector3& v) const {
    return x >= v.x && y >= v.y && z >= v.z;
  }

  FORCEINLINE nauVector3
  nauVector3::operator-() const {
    return nauVector3(-x, -y, -z);
  }

  nauVector3&
  nauVector3::operator+=(const nauVector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  nauVector3&
  nauVector3::operator-=(const nauVector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  
  nauVector3&
  nauVector3::operator*=(const nauVector3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  nauVector3&
  nauVector3::operator/=(const nauVector3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  nauVector3&
  nauVector3::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
  }

  nauVector3&
  nauVector3::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    return *this;
  }

  FORCEINLINE float
  nauVector3::dot(const nauVector3& a, const nauVector3& b) {
    return a | b;
  }

  FORCEINLINE float
  nauVector3::cross(const nauVector3& a, const nauVector3& b) {
    return a ^ b;
  }

  FORCEINLINE float
  nauVector3::dotScale(const nauVector3& a, const nauVector3& b) {
    return (a | b) / nauMath::sqr(a.magnitude());
  }

  float
  nauVector3::sqrDistance(const nauVector3& a, const nauVector3& b) {
    return nauMath::sqr(a.x - b.x) +
           nauMath::sqr(a.y - b.y) +
           nauMath::sqr(a.z - b.z);
  }

  FORCEINLINE float
  nauVector3::distance(const nauVector3& a, const nauVector3& b) {
    return 
      nauMath::sqrt(nauMath::sqr(a.x - b.x) +
                    nauMath::sqr(a.y - b.y) +
                    nauMath::sqr(a.z - b.z));
  }

  void
  nauVector3::setValues(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
  }

  void
  nauVector3::min(const nauVector3& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
    if (v.z < z) z = v.z;
  }

  void
  nauVector3::max(const nauVector3& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
    if (v.z > z) z = v.z;
  }

  void
  nauVector3::floor() {
    x = nauMath::floor(x);
    y = nauMath::floor(y);
    z = nauMath::floor(z);
  }

  void
  nauVector3::ceiling() {
    x = nauMath::ceil(x);
    y = nauMath::ceil(y);
    z = nauMath::ceil(z);
  }

  void
  nauVector3::round() {
    x = nauMath::round(x);
    y = nauMath::round(y);
    z = nauMath::round(z);
  }

  void
  nauVector3::roundHalf() {
    x = nauMath::roundHalf(x);
    y = nauMath::roundHalf(y);
    z = nauMath::roundHalf(z);
  }

  float
  nauVector3::getHighest() const {
    return nauMath::max3(x, y, z);
  }

  float
  nauVector3::getLowest() const {
    return nauMath::min3(x, y, z);
  }

  float
  nauVector3::magnitude() const {
    return nauMath::sqrt(x * x + y * y + z * z);
  }

  float
  nauVector3::sqrMagnitude() const {
    return (x * x + y * y + z * z);
  }

  FORCEINLINE nauVector3
  nauVector3::normalized() {
    float unit = nauMath::invSqrt(x*x + y * y + z * z);
    return nauVector3((x * unit), (y * unit), (z * unit));
  }

  void
  nauVector3::normalize() const {

  }

  bool
  nauVector3::isZero() const {
    return 0.0f == x && 0.0f == y && 0.0f == z;
  }
  
  const nauVector3 nauVector3::ZERO = nauVector3(0.0f, 0.0f, 0.0f);

  const nauVector3 nauVector3::ONES = nauVector3(1.0f, 1.0f, 1.0f);

  const nauVector3 nauVector3::ONEX = nauVector3(1.0f, 0.0f, 0.0f);

  const nauVector3 nauVector3::ONEY = nauVector3(0.0f, 1.0f, 0.0f);

  const nauVector3 nauVector3::ONEZ = nauVector3(0.0f, 0.0f, 1.0f);

}
