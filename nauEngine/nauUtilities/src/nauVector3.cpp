/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauVector3.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauVector3 member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauVector3.h"

namespace nauEngineSDK {
  using std::isnan;
  using std::isinf;

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

  Vector3
   Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
  }

  Vector3
  Vector3::operator-(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }

  Vector3
  Vector3::operator*(const Vector3& v) const {
    return Vector3(x * v.x, y * v.y, z * v.z);
  }

  Vector3
  Vector3::operator/(const Vector3& v) const {
    return Vector3(x / v.x, y / v.y, z / v.z);
  }

  Vector3
  Vector3::operator+(float plus) const {
    return Vector3(x + plus, y + plus, z + plus);
  }

  Vector3
  Vector3::operator-(float minus) const {
    return Vector3(x - minus, y - minus, y - minus);
  }

  Vector3
  Vector3::operator*(float times) const {
    return Vector3(x * times, y * times, z * times);
  }

  Vector3
  Vector3::operator/(float under) const {
    return Vector3(x / under, y / under, z / under);
  }

  float
  Vector3::operator|(const Vector3 v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  Vector3
  Vector3::operator^(const Vector3 v) const {
    
    Vector3 tmp;

    tmp.x = (y*v.z) - (z*v.y);
    tmp.y = (z*v.x) - (x*v.z);
    tmp.z = (x*v.y) - (y*v.x);

    return tmp;
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

  Vector3
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

  float
  Vector3::dot(const Vector3& a, const Vector3& b) {
    return a | b;
  }

  Vector3
  Vector3::cross(const Vector3& a, const Vector3& b) {
    return a ^ b;
  }

  float
  Vector3::projection(const Vector3& a, const Vector3& b) {
    return (a | b) / Math::sqr(a.magnitude());
  }

  float
  Vector3::sqrDistance(const Vector3& a, const Vector3& b) {
    return Math::sqr(a.x - b.x) +
           Math::sqr(a.y - b.y) +
           Math::sqr(a.z - b.z);
  }

  float
  Vector3::distance(const Vector3& a, const Vector3& b) {
    return 
      Math::sqrt(Math::sqr(a.x - b.x) +
                 Math::sqr(a.y - b.y) +
                 Math::sqr(a.z - b.z));
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
    x = Math::floor(x);
    y = Math::floor(y);
    z = Math::floor(z);
  }

  void
  Vector3::ceiling() {
    x = Math::ceil(x);
    y = Math::ceil(y);
    z = Math::ceil(z);
  }

  void
  Vector3::round() {
    x = Math::round(x);
    y = Math::round(y);
    z = Math::round(z);
  }

  void
  Vector3::roundHalf() {
    x = Math::roundHalf(x);
    y = Math::roundHalf(y);
    z = Math::roundHalf(z);
  }

  float
  Vector3::getHighest() const {
    return Math::max3(x, y, z);
  }

  float
  Vector3::getLowest() const {
    return Math::min3(x, y, z);
  }

  float
  Vector3::magnitude() const {
    return Math::sqrt(x * x + y * y + z * z);
  }

  float
  Vector3::sqrMagnitude() const {
    return (x * x + y * y + z * z);
  }

  Vector3
  Vector3::normalized() const {

    NAU_ASSERT(!isnan(x) &&
               !isnan(y) &&
               !isnan(z) &&
               !isinf(x) &&
               !isinf(y) &&
               !isinf(z) &&
               "Value X or Y are either infinite or NAN");

    float sqr = Math::pow(x, 2.0f) + Math::pow(y, 2.0f) + Math::pow(z, 2.0f);

    NAU_ASSERT(sqr >= std::numeric_limits<float>::epsilon() &&
               "Square is less than epsilon and that shit is wack");

    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = Math::invSqrt(sqr);

    return Vector3((x * unit), (y * unit), (z * unit));
  }

  void
  Vector3::normalize() {
    NAU_ASSERT(!isnan(x) &&
               !isnan(y) &&
               !isnan(z) &&
               !isinf(x) &&
               !isinf(y) &&
               !isinf(z) &&
               "Value X or Y are either infinite or NAN");

    float sqr = Math::pow(x, 2.0f) + Math::pow(y, 2.0f) + Math::pow(z, 2.0f);

    NAU_ASSERT(sqr >= std::numeric_limits<float>::epsilon() &&
               "Square is less than epsilon and that shit is wack");

    NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = Math::invSqrt(sqr);

    x *= unit;
    y *= unit; 
    z *= unit;
  }

  bool
  Vector3::isZero() const {
    //return x == y == z == 0.0f;
    return 0.0f == x && 0.0f == y && 0.0f == z;
  }

  bool
  Vector3::isSame(const Vector3& a, const Vector3& b, float error) {
    return Math::abs(a.x - b.x) <= error &&
           Math::abs(a.y - b.y) <= error &&
           Math::abs(a.z - b.z) <= error;
  }

  String
  Vector3::toString() {

    String output;

    output += "( ";
    output += std::to_string(Math::roundp(x, 2));
    output += ", ";
    output += std::to_string(Math::roundp(y, 2));
    output += ", ";
    output += std::to_string(Math::roundp(z, 2));
    output += " )";

    return output;
  }
  
  const Vector3 Vector3::ZERO   = Vector3(0.0f, 0.0f, 0.0f);

  const Vector3 Vector3::ONES   = Vector3(1.0f, 1.0f, 1.0f);

  const Vector3 Vector3::ONEX   = Vector3(1.0f, 0.0f, 0.0f);

  const Vector3 Vector3::ONEY   = Vector3(0.0f, 1.0f, 0.0f);

  const Vector3 Vector3::ONEZ   = Vector3(0.0f, 0.0f, 1.0f);

  const Vector3 Vector3::RIGHT  = Vector3(1.0f, 0.0f, 0.0f);

  const Vector3 Vector3::UP     = Vector3(0.0f, 1.0f, 0.0f);

  const Vector3 Vector3::FRONT  = Vector3(0.0f, 0.0F, 1.0f);


}
