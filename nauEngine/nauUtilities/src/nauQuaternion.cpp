/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauQuaternion.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauQuaternion member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauQuaternion.h"

namespace nauEngineSDK {

  float&
  Quaternion::operator[](uint32 index) {
    return (&x)[index];
  }

  float
  Quaternion::operator[](uint32 index) const {
    return (&x)[index];
  }

  Quaternion
  Quaternion::operator+(const Quaternion& other) const {
    return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
  }
  
  Quaternion
  Quaternion::operator-(const Quaternion& other) const {
    return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
  }
  
  Quaternion
  Quaternion::operator*(const Quaternion& other) const {
    
    Vector3 oldImaginary = Vector3(x, y, z);
    Vector3 otherImaginary = Vector3(other.x, other.y, other.z);
    float nW = w * other.w - (oldImaginary | otherImaginary);

    Vector3 newImaginary = otherImaginary * w + 
                           oldImaginary * other.w + 
                           oldImaginary ^ newImaginary;
    return Quaternion(nW, newImaginary);
  }
  
  Quaternion
  Quaternion::operator/(const float& scale) const {
    return Quaternion(x / scale, y / scale, z / scale, w / scale);
  }

  Quaternion
  Quaternion::operator*(const float& scale) const {
    return Quaternion(x * scale, y * scale, z * scale, w * scale);
  }

  bool
  Quaternion::operator==(const Quaternion& other) {
    return x == other.x && y == other.y && z == other.z && w == other.w;
  }

  bool
  Quaternion::operator!=(const Quaternion& other) {
    return x != other.x && y != other.y && z != other.z && w != other.w;
  }

  bool
  Quaternion::operator<(const Quaternion& other) {
    return x < other.x && y < other.y && z < other.z && w < other.w;
  }

  bool
  Quaternion::operator>(const Quaternion& other) {
    return x > other.x && y > other.y && z > other.z && w > other.w;
  }

  Quaternion
  Quaternion::operator-() const {
    return Quaternion(-x, -y, -z, -w);
  }

  bool
  Quaternion::operator<=(const Quaternion& other) {
    return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
  }

  bool
  Quaternion::operator>=(const Quaternion& other) {
    return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
  }

  Quaternion&
  Quaternion::operator+=(const Quaternion& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }
  
  Quaternion&
  Quaternion::operator-=(const Quaternion& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }
  
  Quaternion&
  Quaternion::operator*=(const Quaternion& other) {
    Vector3 oldImaginary = Vector3(x, y, z);
    Vector3 otherImaginary = Vector3(other.x, other.y, other.z);
    float nW = w * other.w - (oldImaginary | otherImaginary);

    Vector3 newImaginary = otherImaginary * w + 
                           oldImaginary * other.w + 
                           oldImaginary ^ newImaginary;
    *this = Quaternion(nW, newImaginary);
  }
  
  Quaternion&
  Quaternion::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
  }

  Quaternion&
  Quaternion::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    w /= scale;
  }

  float
  Quaternion::operator|(const Quaternion& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
  }

  float
  Quaternion::dot(const Quaternion& a, const Quaternion& b) {
    return (a.x*b.x) + (a.y*b.y) + (a.z*b.z) + (a.w * b.w);
  }
  
  float
  Quaternion::dotScale(const Quaternion& a, const Quaternion& b) {
    return a | b / a.sqrMagnitude();
  }

  float
  Quaternion::angularDifferenceRad(const Quaternion& a, const Quaternion& b) {
    return a | b / a.magnitude() * b.magnitude();
  }

  float
  Quaternion::angularDifferenceDeg(const Quaternion& a, const Quaternion& b) {
    Math::radToDeg(Quaternion::angularDifferenceRad(a, b));
  }

  void
  Quaternion::setValues(float newX, float newY, float newZ, float newW) {
    x = newX;
    y = newY;
    z = newZ;
    w = newW;
  }

  void
  Quaternion::setValues(float newW, Vector3 newImaginary) {
    x = newImaginary.x;
    y = newImaginary.y;
    z = newImaginary.z;
    w = newW;
  }

  Quaternion
  Quaternion::conjugated() const {
    return Quaternion(-Vector3(x, y, z), w);
  }

  void
  Quaternion::conjugate() {
    x *= -1;
    y *= -1;
    z *= -1;
  }

  float
  Quaternion::magnitude() const {
    return Math::sqrt(x * x + y * y + z * z + w * w);
  }

  float
  Quaternion::sqrMagnitude() const {
    return (x * x + y * y + z * z + w * w);
  }

  Quaternion
  Quaternion::normalized() const {

    NAU_ASSERT(this->sqrMagnitude() >= std::numeric_limits<float>::epsilon() &&
              "Square is less than epsilon and that shit is wack");

    return *this / this->magnitude();
  }

  void
  Quaternion::normalize() {
    NAU_ASSERT(this->sqrMagnitude() >= std::numeric_limits<float>::epsilon() &&
              "Square is less than epsilon and that shit is wack");
    
    *this = *this / this->magnitude();
  }

  Quaternion
  Quaternion::NormRotator() {

    float halfAngle = Math::degToRad(w) * 0.5f;
    Vector3 imaginary = { x,y,z };

    return Quaternion(w * Math::cos(halfAngle), imaginary * Math::sin(halfAngle));
  }

  void
  Quaternion::toNormRotator() {
    float halfAngle = Math::degToRad(w) * 0.5f;
    x *= Math::sin(halfAngle);
    y *= Math::sin(halfAngle);
    z *= Math::sin(halfAngle);
    w *= Math::cos(halfAngle);
  }

  Quaternion
  Quaternion::inversed() {
    return this->conjugated() / this->sqrMagnitude();
  }

  void
  Quaternion::inverse() {
    *this = this->conjugated() / this->sqrMagnitude();
  }

  bool
  Quaternion::isPure() {
    return w == 0;
  }

  bool
  Quaternion::isReal() {
    return x == 0 && y == 0 && z == 0;
  }

  bool
  Quaternion::isSame(const Quaternion& a, const Quaternion& b, float error) {
    return Math::abs(a.x - b.x) <= error &&
           Math::abs(a.y - b.y) <= error &&
           Math::abs(a.z - b.z) <= error;
  }

  void
  Quaternion::RotateX(const float& theta) {
    x += theta;
  }
  
  void
  Quaternion::RotateY(const float& theta) {
    y += theta;
  }
  
  void
  Quaternion::RotateZ(const float& theta) {
    z += theta;
  }

  void
  Quaternion::setEulerDegrees(float x, float y, float z) {

  }

  void
  Quaternion::setEulerRadians(float x, float y, float z) {

  }

  const Quaternion Quaternion::ZERO   = Quaternion(0.0f);
  
  const Quaternion Quaternion::PURE   = Quaternion(0.0f);
  
  const Quaternion Quaternion::REAL   = Quaternion(Vector3(0.0f, 0.0f, 0.0f));
  
  const Quaternion Quaternion::RIGHT  = Quaternion(Vector3(1.0f, 0.0f, 0.0f));
  
  const Quaternion Quaternion::UP     = Quaternion(Vector3(0.0f, 1.0f, 0.0f));
  
  const Quaternion Quaternion::FRONT  = Quaternion(Vector3(0.0f, 0.0f, 1.0f));

}
