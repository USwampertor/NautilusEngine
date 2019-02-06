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
  Vector4::operator[](uint32 index) {
    return (&x)[index];

  }

  float
  Vector4::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE Vector4
  Vector4::operator+(const Vector4& v) const {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
  }

  FORCEINLINE Vector4
  Vector4::operator-(const Vector4& v) const {
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
  }

  FORCEINLINE Vector4
  Vector4::operator*(const Vector4& v) const {
    return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
  }

  FORCEINLINE Vector4
  Vector4::operator/(const Vector4& v) const {
    return Vector4(x / v.x, y / v.y, z / v.z, w / v.z);
  }

  FORCEINLINE Vector4
  Vector4::operator+(float plus) const {
    return Vector4(x + plus, y + plus, z + plus, w + plus);
  }

  FORCEINLINE Vector4
  Vector4::operator-(float minus) const {
    return Vector4(x - minus, y - minus, y - minus, w - minus);
  }

  FORCEINLINE Vector4
  Vector4::operator*(float times) const {
    return Vector4(x * times, y * times, z * times, w * times);
  }

  FORCEINLINE Vector4
  Vector4::operator/(float under) const {
    return Vector4(x / under, y / under, z / under, w / under);
  }

  FORCEINLINE float
  Vector4::operator|(const Vector4 v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
  }

  FORCEINLINE float
  Vector4::operator^(const Vector4 v) const {
    return x * v.x - y * v.y - z * v.z - w * v.w;
  }

  bool
  Vector4::operator==(const Vector4& v) const {
    return x == v.x && y == v.y && z == v.z && w == v.w;
  }

  bool
  Vector4::operator!=(const Vector4& v) const {
    return x != v.x || y != v.y || z == v.z || w == v.w;
  }

  bool
  Vector4::operator<(const Vector4& v) const {
    return x < v.x && y < v.y && z < v.z && w < v.w;
  }

  bool
  Vector4::operator>(const Vector4& v) const {
    return x > v.x && y > v.y && z > v.z && w > v.w;
  }

  bool
  Vector4::operator<=(const Vector4& v) const {
    return x <= v.x && y <= v.y && z <= v.z && w <= v.w;
  }

  bool
  Vector4::operator>=(const Vector4& v) const {
    return x >= v.x && y >= v.y && z >= v.z && w >= v.w;
  }

  FORCEINLINE Vector4
  Vector4::operator-() const {
    return Vector4(-x, -y, -z, -w);
  }

  Vector4&
  Vector4::operator+=(const Vector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
  }

  Vector4&
  Vector4::operator-=(const Vector4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
  }

  Vector4&
  Vector4::operator*=(const Vector4& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
  }

  Vector4&
  Vector4::operator/=(const Vector4& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w /= v.w;
    return *this;
  }

  Vector4&
  Vector4::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
    return *this;
  }

  Vector4&
  Vector4::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    w /= scale;
    return *this;
  }

  FORCEINLINE float
  Vector4::dot3(const Vector4& a, const Vector4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  FORCEINLINE float
  Vector4::cross(const Vector4& a, const Vector4& b) {
    return a ^ b;
  }

  FORCEINLINE float
  Vector4::dot4(const Vector4& a, const Vector4& b) {
    return a | b;
  }

  FORCEINLINE float
  Vector4::dotScale(const Vector4& a, const Vector4& b) {
    return (a | b) / nauMath::sqr(a.magnitude());
  }

  FORCEINLINE float
  Vector4::sqrDistance(const Vector4& a, const Vector4& b) {
    return  nauMath::pow(a.x - b.x, 2.0f) +
            nauMath::pow(a.y - b.y, 2.0f) +
            nauMath::pow(a.z - b.z, 2.0f) +
            nauMath::pow(a.w - b.w, 2.0f);

  }

  FORCEINLINE float
  Vector4::distance(const Vector4& a, const Vector4& b) {
    return nauMath::sqrt(nauMath::sqr(a.x - b.x) +
                         nauMath::sqr(a.y - b.y) +
                         nauMath::sqr(a.z - b.z) +
                         nauMath::sqr(a.w - b.w));
  }

  void
  Vector4::setValues(float newX, float newY, float newZ, float newW) {
    x = newX;
    y = newY;
    z = newZ;
    w = newW;
  }

  void
  Vector4::min(const Vector4& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
    if (v.z < z) z = v.z;
    if (v.w < w) w = v.w;
  }

  void
  Vector4::max(const Vector4& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
    if (v.z > z) z = v.z;
    if (v.w > w) w = v.w;
  }

  void
  Vector4::floor() {
    x = nauMath::floor(x);
    y = nauMath::floor(y);
    z = nauMath::floor(z);
    w = nauMath::floor(w);
  }

  void
  Vector4::ceiling() {
    x = nauMath::ceil(x);
    y = nauMath::ceil(y);
    z = nauMath::ceil(z);
    w = nauMath::ceil(w);
  }

  void
  Vector4::round() {
    x = nauMath::round(x);
    y = nauMath::round(y);
    z = nauMath::round(z);
    w = nauMath::round(w);
  }

  void
  Vector4::roundHalf() {
    x = nauMath::roundHalf(x);
    y = nauMath::roundHalf(y);
    z = nauMath::roundHalf(z);
    w = nauMath::roundHalf(w);
  }

  float
  Vector4::getHighest() const {
    return nauMath::max3(x, y, nauMath::max(z, w));
  }

  float
  Vector4::getLowest() const {
    return nauMath::max3(x, y, nauMath::max(z, w));
  }

  float
  Vector4::magnitude() const {
    return nauMath::sqrt(x * x + y * y + z * z + w * w);
  }

  float
  Vector4::sqrMagnitude() const {
    return (x * x + y * y + z * z + w * w);
  }

  float
  Vector4::magnitude3() const {
    return nauMath::sqrt(x * x + y * y + z * z);
  }

  float
  Vector4::sqrMagnitude3() const {
    return (x * x + y * y + z * z);
  }

  Vector4
  Vector4::normalized3() {
    //return nauVector4(0, 0, 0, 0);
    float unit = nauMath::invSqrt(x*x + y * y + z * z);
    return Vector4((x * unit),
                      (y * unit),
                      (z * unit),
                      w);
  }

  void
  Vector4::normalize3() const {
  }

  bool
  Vector4::isZero() const {
    return 0.0f == x && 0.0f == y && 0.0f == z && w == 0.0f;
  }

  const Vector4 Vector4::ZERO = Vector4(0.0f, 0.0f, 0.0f, 0.0f);

  const Vector4 Vector4::ONES = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

  const Vector4 Vector4::ONEX = Vector4(1.0f, 1.0f, 0.0f, 0.0f);

  const Vector4 Vector4::ONEY = Vector4(0.0f, 1.0f, 0.0f, 0.0f);

  const Vector4 Vector4::ONEZ = Vector4(0.0f, 0.0f, 1.0f, 0.0f);

  const Vector4 Vector4::ONEW = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}