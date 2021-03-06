/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauVector2.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief the cpp from the vector object
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "nauVector2.h"
#include "nauVector3.h"

namespace nauEngineSDK {

  /**
   * Method implementation
   */

  nauVector2::nauVector2(float nx, float ny) : x(nx), y(ny) {}

  inline nauVector2::nauVector2(const nauVector3& v): x(v.x),y(v.y) {}
  
  float&
  nauVector2::operator[](uint32 index) {
    return (&x)[index];
  }

  float
  nauVector2::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE nauVector2
  nauVector2::operator+(const nauVector2& v) const {
    return nauVector2(x + v.x, y + v.y);
  }

  FORCEINLINE nauVector2
  nauVector2::operator-(const nauVector2& v) const {
    return nauVector2(x - v.x, y - v.y);
  }

  FORCEINLINE nauVector2
  nauVector2::operator*(const nauVector2& v) const {
    return nauVector2(x * v.x, y * v.y);
  }

  FORCEINLINE nauVector2
  nauVector2::operator/(const nauVector2& v) const {
    return nauVector2(x / v.x, y / v.y);
  }

  FORCEINLINE nauVector2
  nauVector2::operator+(float plus) const {
    return nauVector2(x + plus, y + plus);
  }

  FORCEINLINE nauVector2
  nauVector2::operator-(float minus) const {
    return nauVector2(x - minus, y - minus);
  }

  FORCEINLINE nauVector2
  nauVector2::operator*(float times) const {
    return nauVector2(x * times, y * times);
  }

  FORCEINLINE nauVector2
  nauVector2::operator/(float under) const {
    return nauVector2(x / under, y / under);
  }

  FORCEINLINE float
  nauVector2::operator|(const nauVector2 v) const {
    return x * v.x + y * v.y;
  }

  FORCEINLINE float
  nauVector2::operator^(const nauVector2 v) const {
    return x * v.x - y * v.y;
  }

  bool
  nauVector2::operator==(const nauVector2& v) const {
    return x == v.x && y == v.y;
  }

  bool
  nauVector2::operator!=(const nauVector2& v) const {
    return x != v.x || y != v.y;
  }

  bool
  nauVector2::operator<(const nauVector2& v) const {
    return x < v.x && y < v.y;
  }

  bool
  nauVector2::operator>(const nauVector2& v) const {
    return x > v.x && y > v.y;
  }

  bool
  nauVector2::operator<=(const nauVector2& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
  nauVector2::operator>=(const nauVector2& v) const {
    return x >= v.x && y >= v.y;
  }

  nauVector2
  nauVector2::operator-() const {
    return nauVector2(-x, -y);
  }

  nauVector2&
  nauVector2::operator+=(const nauVector2& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  nauVector2&
  nauVector2::operator-=(const nauVector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  nauVector2&
  nauVector2::operator*=(const nauVector2& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  nauVector2&
  nauVector2::operator/=(const nauVector2& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  nauVector2&
  nauVector2::operator*=(float scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  nauVector2&
  nauVector2::operator/=(float scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

  FORCEINLINE float
  nauVector2::dot(const nauVector2& a, const nauVector2& b) {
    return a | b;
  }

  FORCEINLINE float
  nauVector2::cross(const nauVector2& a, const nauVector2& b) {
    return a ^ b;
  }

  FORCEINLINE float
  nauVector2::dotScale(const nauVector2& a, const nauVector2& b) {
    return (a | b) / a.magnitude();
  }

  FORCEINLINE float
  nauVector2::sqrDistance(const nauVector2& a, const nauVector2& b) {
    return nauMath::pow(a.x - b.x, 2.0f) + nauMath::pow(a.y - b.y, 2.0f);
  }

  FORCEINLINE float
  nauVector2::distance(const nauVector2& a, const nauVector2& b) {
    return nauMath::sqrt(nauMath::sqr(a.x + b.x) + nauMath::sqr(a.y + b.y));
  }

  void
  nauVector2::setValues(float newX, float newY) {
    x = newX;
    y = newY;
  }

  void
  nauVector2::min(const nauVector2& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
  nauVector2::max(const nauVector2& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  void
  nauVector2::floor() {
    x = nauMath::floor(x);
    y = nauMath::floor(y);
  }

  void
  nauVector2::ceiling() {
    x = nauMath::ceil(x);
    y = nauMath::ceil(y);
  }

  void
  nauVector2::round() {
    x = nauMath::round(x);
    y = nauMath::round(y);
  }

  void
  nauVector2::roundHalf() {
   x = nauMath::roundHalf(x);
   y = nauMath::roundHalf(y);
  }

  float
  nauVector2::getHighest() const {
    return nauMath::max(x, y);
  }

  float
  nauVector2::getLowest() const {
    return nauMath::min(x, y);
  }

  float
  nauVector2::magnitude() const {
    return nauMath::sqrt(x * x + y * y);
  }

  float
  nauVector2::sqrMagnitude() const {
    return (x * x + y * y);
  }

  FORCEINLINE nauVector2
  nauVector2::normalized() {
    float sqr = nauMath::pow(x, 2.0f) + nauMath::pow(y, 2.0f);
    NAU_ASSERT(sqr != 0.0f && "The square of the elements is 0!!!");
    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = nauMath::invSqrt(sqr);
    return nauVector2((x * unit), (y * unit));
  }

  void
  nauVector2::normalize() const {
  
  }

  bool
  nauVector2::isZero() const {
    return 0.0f == x && 0.0f == y;
  }

  const nauVector2 nauVector2::ZERO = nauVector2(0.0f, 0.0f);
  
  const nauVector2 nauVector2::ONES = nauVector2(1.0f, 1.0f);
  
  const nauVector2 nauVector2::ONEX = nauVector2(1.0f, 0.0f);

  const nauVector2 nauVector2::ONEY = nauVector2(0.0f, 1.0f);
  

}
