/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector4.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauVector4 member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauVector4.h"

namespace nauEngineSDK {
  
  /**
   * Method Implementation
   */
    
  /**
   * Overloaded operator declarations
   */
  float&
  nauVector4::operator[](uint32 index) {
    return (&x)[index];

  }

  float
  nauVector4::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE nauVector4
  nauVector4::operator+(const nauVector4& v) const {
    return nauVector4(x + v.x, y + v.y, z + v.z, w + v.w);
  }

  FORCEINLINE nauVector4
  nauVector4::operator-(const nauVector4& v) const {
    return nauVector4(x - v.x, y - v.y, z - v.z, w - v.w);
  }

  FORCEINLINE nauVector4
  nauVector4::operator*(const nauVector4& v) const {
    return nauVector4(x * v.x, y * v.y, z * v.z, w * v.w);
  }

  FORCEINLINE nauVector4
  nauVector4::operator/(const nauVector4& v) const {
    return nauVector4(x / v.x, y / v.y, z / v.z, w / v.z);
  }

  FORCEINLINE nauVector4
  nauVector4::operator+(float plus) const {
    return nauVector4(x + plus, y + plus, z + plus, w + plus);
  }

  FORCEINLINE nauVector4
  nauVector4::operator-(float minus) const {
    return nauVector4(x - minus, y - minus, y - minus, w - minus);
  }

  FORCEINLINE nauVector4
  nauVector4::operator*(float times) const {
    return nauVector4(x * times, y * times, z * times, w * times);
  }

  FORCEINLINE nauVector4
  nauVector4::operator/(float under) const {
    return nauVector4(x / under, y / under, z / under, w / under);
  }

  FORCEINLINE float
  nauVector4::operator|(const nauVector4 v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
  }

  FORCEINLINE float
  nauVector4::operator^(const nauVector4 v) const {
    return x * v.x - y * v.y - z * v.z - w * v.w;
  }

  bool
  nauVector4::operator==(const nauVector4& v) const {
    return x == v.x && y == v.y && z == v.z && w == v.w;
  }

  bool
  nauVector4::operator!=(const nauVector4& v) const {
    return x != v.x || y != v.y || z == v.z || w == v.w;
  }

  bool
  nauVector4::operator<(const nauVector4& v) const {
    return x < v.x && y < v.y && z < v.z && w < v.w;
  }

  bool
  nauVector4::operator>(const nauVector4& v) const {
    return x > v.x && y > v.y && z > v.z && w > v.w;
  }

  bool
  nauVector4::operator<=(const nauVector4& v) const {
    return x <= v.x && y <= v.y && z <= v.z && w <= v.w;
  }

  bool
  nauVector4::operator>=(const nauVector4& v) const {
    return x >= v.x && y >= v.y && z >= v.z && w >= v.w;
  }

  FORCEINLINE nauVector4
  nauVector4::operator-() const {
    return nauVector4(-x, -y, -z, -w);
  }

  nauVector4&
  nauVector4::operator+=(const nauVector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
  }

  nauVector4&
  nauVector4::operator-=(const nauVector4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
  }

  nauVector4&
  nauVector4::operator*=(const nauVector4& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
  }

  nauVector4&
  nauVector4::operator/=(const nauVector4& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w /= v.w;
    return *this;
  }

  nauVector4&
  nauVector4::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
    return *this;
  }

  nauVector4&
  nauVector4::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    w /= scale;
    return *this;
  }

  FORCEINLINE float
  nauVector4::dot3(const nauVector4& a, const nauVector4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  FORCEINLINE float
  nauVector4::cross(const nauVector4& a, const nauVector4& b) {
    return a ^ b;
  }

  FORCEINLINE float
  nauVector4::dot4(const nauVector4& a, const nauVector4& b) {
    return a | b;
  }

  FORCEINLINE float
  nauVector4::dotScale(const nauVector4& a, const nauVector4& b) {
    return (a | b) / nauMath::sqr(a.magnitude());
  }

  FORCEINLINE float
  nauVector4::sqrDistance(const nauVector4& a, const nauVector4& b) {
    return  nauMath::pow(a.x - b.x, 2.0f) +
            nauMath::pow(a.y - b.y, 2.0f) +
            nauMath::pow(a.z - b.z, 2.0f) +
            nauMath::pow(a.w - b.w, 2.0f);

  }

  FORCEINLINE float
  nauVector4::distance(const nauVector4& a, const nauVector4& b) {
    return nauMath::sqrt(nauMath::sqr(a.x - b.x) +
                         nauMath::sqr(a.y - b.y) +
                         nauMath::sqr(a.z - b.z) +
                         nauMath::sqr(a.w - b.w));
  }

  void
  nauVector4::setValues(float newX, float newY, float newZ, float newW) {
    x = newX;
    y = newY;
    z = newZ;
    w = newW;
  }

  void
  nauVector4::min(const nauVector4& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
    if (v.z < z) z = v.z;
    if (v.w < w) w = v.w;
  }

  void
  nauVector4::max(const nauVector4& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
    if (v.z > z) z = v.z;
    if (v.w > w) w = v.w;
  }

  void
  nauVector4::floor() {
    x = nauMath::floor(x);
    y = nauMath::floor(y);
    z = nauMath::floor(z);
    w = nauMath::floor(w);
  }

  void
  nauVector4::ceiling() {
    x = nauMath::ceil(x);
    y = nauMath::ceil(y);
    z = nauMath::ceil(z);
    w = nauMath::ceil(w);
  }

  void
  nauVector4::round() {
    x = nauMath::round(x);
    y = nauMath::round(y);
    z = nauMath::round(z);
    w = nauMath::round(w);
  }

  void
  nauVector4::roundHalf() {
    x = nauMath::roundHalf(x);
    y = nauMath::roundHalf(y);
    z = nauMath::roundHalf(z);
    w = nauMath::roundHalf(w);
  }

  float
  nauVector4::getHighest() const {
    return nauMath::max3(x, y, nauMath::max(z, w));
  }

  float
  nauVector4::getLowest() const {
    return nauMath::max3(x, y, nauMath::max(z, w));
  }

  float
  nauVector4::magnitude() const {
    return nauMath::sqrt(x * x + y * y + z * z + w * w);
  }

  float
  nauVector4::sqrMagnitude() const {
    return (x * x + y * y + z * z + w * w);
  }

  float
  nauVector4::magnitude3() const {
    return nauMath::sqrt(x * x + y * y + z * z);
  }

  float
  nauVector4::sqrMagnitude3() const {
    return (x * x + y * y + z * z);
  }

  nauVector4
  nauVector4::normalized3() {
    //return nauVector4(0, 0, 0, 0);
    float unit = nauMath::invSqrt(x*x + y * y + z * z);
    return nauVector4((x * unit),
                      (y * unit),
                      (z * unit),
                      w);
  }

  void
  nauVector4::normalize3() const {
  }

  bool
  nauVector4::isZero() const {
    return 0.0f == x && 0.0f == y && 0.0f == z && w == 0.0f;
  }

  const nauVector4 nauVector4::ZERO = nauVector4(0.0f, 0.0f, 0.0f, 0.0f);

  const nauVector4 nauVector4::ONES = nauVector4(1.0f, 1.0f, 1.0f, 1.0f);

  const nauVector4 nauVector4::ONEX = nauVector4(1.0f, 1.0f, 0.0f, 0.0f);

  const nauVector4 nauVector4::ONEY = nauVector4(0.0f, 1.0f, 0.0f, 0.0f);

  const nauVector4 nauVector4::ONEZ = nauVector4(0.0f, 0.0f, 1.0f, 0.0f);

  const nauVector4 nauVector4::ONEW = nauVector4(0.0f, 0.0f, 0.0f, 1.0f);
}