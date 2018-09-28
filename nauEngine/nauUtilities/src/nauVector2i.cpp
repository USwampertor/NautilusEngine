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

  nauVector2i::nauVector2i(int32 nx, int32 ny) : x(nx), y(ny) {}

  int32&
  nauVector2i::operator()(uint32& index) {
    return (&x)[index];
  }

  const int32&
  nauVector2i::operator()(uint32& index) const {
    return (&x)[index];
  }

  int32&
  nauVector2i::operator[](uint32 index) {
    return (&x)[index];
  }
  
  const int32
  nauVector2i::operator[](uint32 index) const {
    return (&x)[index];
  }


  FORCEINLINE nauVector2i
  nauVector2i::operator+(const nauVector2i& v) const {
    return nauVector2i(x + v.x, y + v.y);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator-(const nauVector2i& v) const {
    return nauVector2i(x - v.x, y - v.y);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator*(const nauVector2i& v) const {
    return nauVector2i(x * v.x, y * v.y);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator/(const nauVector2i& v) const {
    return nauVector2i(x / v.x, y / v.y);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator+(int32 plus) const {
    return nauVector2i(x + plus, y + plus);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator-(int32 minus) const {
    return nauVector2i(x - minus, y - minus);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator*(int32 times) const {
    return nauVector2i(x * times, y * times);
  }

  FORCEINLINE nauVector2i
  nauVector2i::operator/(int32 under) const {
    return nauVector2i(x / under, y / under);
  }

  FORCEINLINE int32
  nauVector2i::operator|(const nauVector2i v) const {
    return x * v.x + y * v.y;
  }

  FORCEINLINE int32
  nauVector2i::operator^(const nauVector2i v) const {
    return x * v.x - y * v.y;
  }

  bool
  nauVector2i::operator==(const nauVector2i& v) const {
    return x == v.x && y == v.y;
  }

  bool
  nauVector2i::operator!=(const nauVector2i& v) const {
    return x != v.x || y != v.y;
  }

  bool
  nauVector2i::operator<(const nauVector2i& v) const {
    return x < v.x && y < v.y;
  }

  bool
  nauVector2i::operator>(const nauVector2i& v) const {
    return x > v.x && y > v.y;
  }

  bool
  nauVector2i::operator<=(const nauVector2i& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
  nauVector2i::operator>=(const nauVector2i& v) const {
    return x >= v.x && y >= v.y;
  }

  nauVector2i
  nauVector2i::operator-() const {
    return nauVector2i(-x, -y);
  }

  nauVector2i&
  nauVector2i::operator+=(const nauVector2i& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  nauVector2i&
  nauVector2i::operator-=(const nauVector2i& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  nauVector2i&
  nauVector2i::operator*=(const nauVector2i& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  nauVector2i&
  nauVector2i::operator/=(const nauVector2i& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  nauVector2i&
  nauVector2i::operator*=(int32 scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  nauVector2i&
  nauVector2i::operator/=(int32 scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

  FORCEINLINE int32
  nauVector2i::dot(const nauVector2i& a, const nauVector2i& b) {
    return a | b;
  }

  FORCEINLINE int32
  nauVector2i::cross(const nauVector2i& a, const nauVector2i& b) {
    return a ^ b;
  }

  FORCEINLINE int32
  nauVector2i::dotScale(const nauVector2i& a, const nauVector2i& b) {
    return (a | b) / a.magnitude();
  }

  FORCEINLINE int32
  nauVector2i::sqrDistance(const nauVector2i& a, const nauVector2i& b) {
    return nauMath::pow(a.x - b.x, 2) + nauMath::pow(a.y - b.y, 2);
  }

  FORCEINLINE int32
  nauVector2i::distance(const nauVector2i& a, const nauVector2i& b) {
    return nauMath::sqrt(nauMath::sqr(a.x + b.x) + nauMath::sqr(a.y + b.y));
  }

  void
  nauVector2i::setValues(int32 newX, int32 newY) {
    x = newX;
    y = newY;
  }

  void
  nauVector2i::min(const nauVector2i& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
  nauVector2i::max(const nauVector2i& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  int32
  nauVector2i::getHighest() const {
    return nauMath::max(x, y);
  }

  int32
  nauVector2i::getLowest() const {
    return nauMath::min(x, y);
  }

  int32
  nauVector2i::magnitude() const {
    return nauMath::sqrt(x*x + y * y);
  }

  int32
  nauVector2i::sqrMagnitude() const {
    return (x * x + y * y);
  }

  FORCEINLINE nauVector2i
  nauVector2i::normalized() {
    return nauVector2i(0, 0);
  }

  void
  nauVector2i::normalize() const {

  }

  bool
  nauVector2i::isZero() const {
    return 0 == x && 0 == y;
  }

  const nauVector2i nauVector2i::ZERO = nauVector2i(0, 0);

  const nauVector2i nauVector2i::ONES = nauVector2i(1, 1);

  const nauVector2i nauVector2i::ONEX = nauVector2i(1, 0);

  const nauVector2i nauVector2i::ONEY = nauVector2i(0, 1);

}
