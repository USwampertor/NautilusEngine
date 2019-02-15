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
  using std::isnan;
  using std::isinf;

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

  Vector4
  Vector4::operator+(const Vector4& v) const {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
  }

  Vector4
  Vector4::operator-(const Vector4& v) const {
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
  }

  Vector4
  Vector4::operator*(const Vector4& v) const {
    return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
  }

  Vector4
  Vector4::operator/(const Vector4& v) const {
    return Vector4(x / v.x, y / v.y, z / v.z, w / v.z);
  }

  Vector4
  Vector4::operator+(float plus) const {
    return Vector4(x + plus, y + plus, z + plus, w + plus);
  }

  Vector4
  Vector4::operator-(float minus) const {
    return Vector4(x - minus, y - minus, y - minus, w - minus);
  }

  Vector4
  Vector4::operator*(float times) const {
    return Vector4(x * times, y * times, z * times, w * times);
  }

  Vector4
  Vector4::operator/(float under) const {
    return Vector4(x / under, y / under, z / under, w / under);
  }

  float
  Vector4::operator|(const Vector4 v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
  }

  float
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

  Vector4
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

  float
  Vector4::dot3(const Vector4& a, const Vector4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  float
  Vector4::cross(const Vector4& a, const Vector4& b) {
    return a ^ b;
  }

  float
  Vector4::dot4(const Vector4& a, const Vector4& b) {
    return a | b;
  }

  float
  Vector4::dotScale(const Vector4& a, const Vector4& b) {
    return (a | b) / Math::sqr(a.magnitude());
  }

  float
  Vector4::sqrDistance(const Vector4& a, const Vector4& b) {
    return  Math::pow(a.x - b.x, 2.0f) +
            Math::pow(a.y - b.y, 2.0f) +
            Math::pow(a.z - b.z, 2.0f) +
            Math::pow(a.w - b.w, 2.0f);

  }

  float
  Vector4::distance(const Vector4& a, const Vector4& b) {
    return Math::sqrt(Math::sqr(a.x - b.x) +
                         Math::sqr(a.y - b.y) +
                         Math::sqr(a.z - b.z) +
                         Math::sqr(a.w - b.w));
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
    x = Math::floor(x);
    y = Math::floor(y);
    z = Math::floor(z);
    w = Math::floor(w);
  }

  void
  Vector4::ceiling() {
    x = Math::ceil(x);
    y = Math::ceil(y);
    z = Math::ceil(z);
    w = Math::ceil(w);
  }

  void
  Vector4::round() {
    x = Math::round(x);
    y = Math::round(y);
    z = Math::round(z);
    w = Math::round(w);
  }

  void
  Vector4::roundHalf() {
    x = Math::roundHalf(x);
    y = Math::roundHalf(y);
    z = Math::roundHalf(z);
    w = Math::roundHalf(w);
  }

  float
  Vector4::getHighest() const {
    return Math::max3(x, y, Math::max(z, w));
  }

  float
  Vector4::getLowest() const {
    return Math::max3(x, y, Math::max(z, w));
  }

  float
  Vector4::magnitude() const {
    return Math::sqrt(x * x + y * y + z * z + w * w);
  }

  float
  Vector4::sqrMagnitude() const {
    return (x * x + y * y + z * z + w * w);
  }

  float
  Vector4::magnitude3() const {
    return Math::sqrt(x * x + y * y + z * z);
  }

  float
  Vector4::sqrMagnitude3() const {
    return (x * x + y * y + z * z);
  }

  Vector4
  Vector4::normalized3() const {
    NAU_ASSERT(!isnan(x) &&
               !isnan(y) &&
               !isnan(z) &&
               !isinf(x) &&
               !isinf(y) &&
               !isinf(z) &&
               "Value X or Y are either infinite or NAN");

    float sqr = Math::pow(x, 2.0f) + Math::pow(y, 2.0f) + Math::pow(z, 2.0f);

    NAU_ASSERT(sqr <= std::numeric_limits<float>::epsilon() &&
               "Square is less than epsilon and that shit is wack");

    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = Math::invSqrt(sqr);

    return Vector4((x * unit), (y * unit), (z * unit), w);
  }

  void
  Vector4::normalize3() {
    NAU_ASSERT(!isnan(x) &&
               !isnan(y) &&
               !isnan(z) &&
               !isinf(x) &&
               !isinf(y) &&
               !isinf(z) &&
               "Value X or Y are either infinite or NAN");

    float sqr = Math::pow(x, 2.0f) + Math::pow(y, 2.0f) + Math::pow(z, 2.0f);

    NAU_ASSERT(sqr <= std::numeric_limits<float>::epsilon() &&
               "Square is less than epsilon and that shit is wack");

    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = Math::invSqrt(sqr);

    x *= unit;
    y *= unit;
    z *= unit;
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