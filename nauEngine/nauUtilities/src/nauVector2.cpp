/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief the cpp from the vector object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauVector2.h"
#include "nauVector3.h"


//TODO: CREATE LIMIT FILES AND DELETE THIS 



namespace nauEngineSDK {
  using std::isnan;
  using std::isinf;

  /**
   * Method implementation
   */

  Vector2::Vector2(float nx, float ny) : x(nx), y(ny) {}

  inline Vector2::Vector2(const Vector3& v): x(v.x),y(v.y) {}
  
  float&
  Vector2::operator[](uint32 index) {
    return (&x)[index];
  }

  float
  Vector2::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE Vector2
  Vector2::operator+(const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
  }

  FORCEINLINE Vector2
  Vector2::operator-(const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
  }

  FORCEINLINE Vector2
  Vector2::operator*(const Vector2& v) const {
    return Vector2(x * v.x, y * v.y);
  }

  FORCEINLINE Vector2
  Vector2::operator/(const Vector2& v) const {
    return Vector2(x / v.x, y / v.y);
  }

  FORCEINLINE Vector2
  Vector2::operator+(float plus) const {
    return Vector2(x + plus, y + plus);
  }

  FORCEINLINE Vector2
  Vector2::operator-(float minus) const {
    return Vector2(x - minus, y - minus);
  }

  FORCEINLINE Vector2
  Vector2::operator*(float times) const {
    return Vector2(x * times, y * times);
  }

  FORCEINLINE Vector2
  Vector2::operator/(float under) const {
    return Vector2(x / under, y / under);
  }

  FORCEINLINE float
  Vector2::operator|(const Vector2 v) const {
    return x * v.x + y * v.y;
  }

  FORCEINLINE float
  Vector2::operator^(const Vector2 v) const {
    return x * v.x - y * v.y;
  }

  bool
  Vector2::operator==(const Vector2& v) const {
    return x == v.x && y == v.y;
  }

  bool
  Vector2::operator!=(const Vector2& v) const {
    return x != v.x || y != v.y;
  }

  bool
  Vector2::operator<(const Vector2& v) const {
    return x < v.x && y < v.y;
  }

  bool
  Vector2::operator>(const Vector2& v) const {
    return x > v.x && y > v.y;
  }

  bool
  Vector2::operator<=(const Vector2& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
  Vector2::operator>=(const Vector2& v) const {
    return x >= v.x && y >= v.y;
  }

  Vector2
  Vector2::operator-() const {
    return Vector2(-x, -y);
  }

  Vector2&
  Vector2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vector2&
  Vector2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  Vector2&
  Vector2::operator*=(const Vector2& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  Vector2&
  Vector2::operator/=(const Vector2& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  Vector2&
  Vector2::operator*=(float scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  Vector2&
  Vector2::operator/=(float scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

  FORCEINLINE float
  Vector2::dot(const Vector2& a, const Vector2& b) {
    return a | b;
  }

  FORCEINLINE float
  Vector2::cross(const Vector2& a, const Vector2& b) {
    return a ^ b;
  }

  FORCEINLINE float
  Vector2::dotScale(const Vector2& a, const Vector2& b) {
    return (a | b) / a.magnitude();
  }

  FORCEINLINE float
  Vector2::sqrDistance(const Vector2& a, const Vector2& b) {
    return Math::pow(a.x - b.x, 2.0f) + Math::pow(a.y - b.y, 2.0f);
  }

  FORCEINLINE float
  Vector2::distance(const Vector2& a, const Vector2& b) {
    return Math::sqrt(Math::sqr(a.x + b.x) + Math::sqr(a.y + b.y));
  }

  void
  Vector2::setValues(float newX, float newY) {
    x = newX;
    y = newY;
  }

  void
  Vector2::min(const Vector2& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
  Vector2::max(const Vector2& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  void
  Vector2::floor() {
    x = Math::floor(x);
    y = Math::floor(y);
  }

  void
  Vector2::ceiling() {
    x = Math::ceil(x);
    y = Math::ceil(y);
  }

  void
  Vector2::round() {
    x = Math::round(x);
    y = Math::round(y);
  }

  void
  Vector2::roundHalf() {
   x = Math::roundHalf(x);
   y = Math::roundHalf(y);
  }

  float
  Vector2::getHighest() const {
    return Math::max(x, y);
  }

  float
  Vector2::getLowest() const {
    return Math::min(x, y);
  }

  float
  Vector2::magnitude() const {
    return Math::sqrt(x * x + y * y);
  }

  float
  Vector2::sqrMagnitude() const {
    return (x * x + y * y);
  }

  Vector2
  Vector2::normalized() const {

    NAU_ASSERT(!isnan(x) &&
               !isnan(y) &&
               !isinf(x) &&
               !isinf(y) &&
               "Value X or Y are either infinite or NAN");

    float sqr = Math::pow(x, 2.0f) + Math::pow(y, 2.0f);
    
    NAU_ASSERT(sqr >= std::numeric_limits<float>::epsilon() &&
               "Square is less than epsilon and that shit is wack");
    
    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = Math::invSqrt(sqr);
    return Vector2((x * unit), (y * unit));
  }
  
  void
  Vector2::normalize() {
    NAU_ASSERT(!isnan(x) &&
               !isnan(y) &&
               !isinf(x) &&
               !isinf(y) &&
               "Value X or Y are either infinite or NAN");

    float sqr = Math::pow(x, 2.0f) + Math::pow(y, 2.0f);

    NAU_ASSERT(sqr >= std::numeric_limits<float>::epsilon() &&
               "Square is less than epsilon and that shit is wack");

    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = Math::invSqrt(sqr);

    x *= unit;
    y *= unit;
  }

  bool
  Vector2::isZero() const {
    return 0.0f == x && 0.0f == y;
  }

  bool
  Vector2::isSame(const Vector2& a, const Vector2& b, float error) {
    int same = 0;
    if (Math::abs(a.x - b.x) >= error) { ++same; }
    if (Math::abs(a.y - b.y) >= error) { ++same; }
    if (2 == same) { return true; }
    return false;
  }

  String
  Vector2::toString() {
    String output;

    output += "( ";
    output += std::to_string(Math::roundp(x, 2));
    output += ", ";
    output += std::to_string(Math::roundp(y, 2));
    output += " )";

    return output;
  }

  const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
  
  const Vector2 Vector2::ONES = Vector2(1.0f, 1.0f);
  
  const Vector2 Vector2::ONEX = Vector2(1.0f, 0.0f);

  const Vector2 Vector2::ONEY = Vector2(0.0f, 1.0f);
  
  const Vector2 Vector2::UP = Vector2(0.0f, 1.0f);

  const Vector2 Vector2::RIGHT = Vector2(1.0f, 0.0f);

}
