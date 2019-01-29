/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2i.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauVector2i member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauVector2i.h"

namespace nauEngineSDK {
  
  /**
   * Method Implementation
   */

  Vector2i::Vector2i(int32 nx, int32 ny) : x(nx), y(ny) {}

  int32&
  Vector2i::operator()(uint32& index) {
    return (&x)[index];
  }

  const int32&
  Vector2i::operator()(uint32& index) const {
    return (&x)[index];
  }

  int32&
  Vector2i::operator[](uint32 index) {
    return (&x)[index];
  }
  
  const int32
  Vector2i::operator[](uint32 index) const {
    return (&x)[index];
  }


  FORCEINLINE Vector2i
  Vector2i::operator+(const Vector2i& v) const {
    return Vector2i(x + v.x, y + v.y);
  }

  FORCEINLINE Vector2i
  Vector2i::operator-(const Vector2i& v) const {
    return Vector2i(x - v.x, y - v.y);
  }

  FORCEINLINE Vector2i
  Vector2i::operator*(const Vector2i& v) const {
    return Vector2i(x * v.x, y * v.y);
  }

  FORCEINLINE Vector2i
  Vector2i::operator/(const Vector2i& v) const {
    return Vector2i(x / v.x, y / v.y);
  }

  FORCEINLINE Vector2i
  Vector2i::operator+(int32 plus) const {
    return Vector2i(x + plus, y + plus);
  }

  FORCEINLINE Vector2i
  Vector2i::operator-(int32 minus) const {
    return Vector2i(x - minus, y - minus);
  }

  FORCEINLINE Vector2i
  Vector2i::operator*(int32 times) const {
    return Vector2i(x * times, y * times);
  }

  FORCEINLINE Vector2i
  Vector2i::operator/(int32 under) const {
    return Vector2i(x / under, y / under);
  }

  FORCEINLINE int32
  Vector2i::operator|(const Vector2i v) const {
    return x * v.x + y * v.y;
  }

  FORCEINLINE int32
  Vector2i::operator^(const Vector2i v) const {
    return x * v.x - y * v.y;
  }

  bool
  Vector2i::operator==(const Vector2i& v) const {
    return x == v.x && y == v.y;
  }

  bool
  Vector2i::operator!=(const Vector2i& v) const {
    return x != v.x || y != v.y;
  }

  bool
  Vector2i::operator<(const Vector2i& v) const {
    return x < v.x && y < v.y;
  }

  bool
  Vector2i::operator>(const Vector2i& v) const {
    return x > v.x && y > v.y;
  }

  bool
  Vector2i::operator<=(const Vector2i& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
  Vector2i::operator>=(const Vector2i& v) const {
    return x >= v.x && y >= v.y;
  }

  Vector2i
  Vector2i::operator-() const {
    return Vector2i(-x, -y);
  }

  Vector2i&
  Vector2i::operator+=(const Vector2i& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vector2i&
  Vector2i::operator-=(const Vector2i& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  Vector2i&
  Vector2i::operator*=(const Vector2i& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  Vector2i&
  Vector2i::operator/=(const Vector2i& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  Vector2i&
  Vector2i::operator*=(int32 scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  Vector2i&
  Vector2i::operator/=(int32 scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

  FORCEINLINE int32
  Vector2i::dot(const Vector2i& a, const Vector2i& b) {
    return a | b;
  }

  FORCEINLINE int32
  Vector2i::cross(const Vector2i& a, const Vector2i& b) {
    return a ^ b;
  }

  FORCEINLINE int32
  Vector2i::dotScale(const Vector2i& a, const Vector2i& b) {
    return (a | b) / a.magnitude();
  }

  FORCEINLINE int32
  Vector2i::sqrDistance(const Vector2i& a, const Vector2i& b) {
    return nauMath::pow(a.x - b.x, 2) + nauMath::pow(a.y - b.y, 2);
  }

  FORCEINLINE int32
  Vector2i::distance(const Vector2i& a, const Vector2i& b) {
    return nauMath::sqrt(nauMath::sqr(a.x + b.x) + nauMath::sqr(a.y + b.y));
  }

  void
  Vector2i::setValues(int32 newX, int32 newY) {
    x = newX;
    y = newY;
  }

  void
  Vector2i::min(const Vector2i& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
  Vector2i::max(const Vector2i& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  int32
  Vector2i::getHighest() const {
    return nauMath::max(x, y);
  }

  int32
  Vector2i::getLowest() const {
    return nauMath::min(x, y);
  }

  int32
  Vector2i::magnitude() const {
    return nauMath::sqrt(x*x + y * y);
  }

  int32
  Vector2i::sqrMagnitude() const {
    return (x * x + y * y);
  }

  FORCEINLINE Vector2i
  Vector2i::normalized() {
    return Vector2i(0, 0);
  }

  void
  Vector2i::normalize() const {

  }

  bool
  Vector2i::isZero() const {
    return 0 == x && 0 == y;
  }

  const Vector2i Vector2i::ZERO = Vector2i(0, 0);

  const Vector2i Vector2i::ONES = Vector2i(1, 1);

  const Vector2i Vector2i::ONEX = Vector2i(1, 0);

  const Vector2i Vector2i::ONEY = Vector2i(0, 1);

}
