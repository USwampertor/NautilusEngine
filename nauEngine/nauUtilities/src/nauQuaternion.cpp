/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauQuaternion.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauQuaternion member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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
                           oldImaginary ^ otherImaginary;
    return Quaternion(nW, newImaginary);
  }
  
  Quaternion
  Quaternion::operator/(const Quaternion& other) const {
    
    float divider = Math::sqr(other.x) + 
                    Math::sqr(other.y) + 
                    Math::sqr(other.z) +
                    Math::sqr(other.w);

    return Quaternion((other.w * x - other.x * w - other.y * z + other.z * y) / divider,
                      (other.w * y + other.x * z - other.y * w - other.z * x) / divider,
                      (other.w * z - other.x * y + other.y * x - other.z * w) / divider,
                      (other.w * w + other.x * x + other.y * y + other.z * z) / divider);
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
                           oldImaginary ^ otherImaginary;

    *this = Quaternion(nW, newImaginary);
    return *this;
  }
  
  Quaternion&
  Quaternion::operator/=(const Quaternion& other) {

    float divider = Math::sqr(other.x) +
                    Math::sqr(other.y) +
                    Math::sqr(other.z) +
                    Math::sqr(other.w);

    *this = Quaternion((other.w * x - other.x * w - other.y * z + other.z * y) / divider,
                       (other.w * y + other.x * z - other.y * w - other.z * x) / divider,
                       (other.w * z - other.x * y + other.y * x - other.z * w) / divider,
                       (other.w * w + other.x * x + other.y * y + other.z * z) / divider);
    return *this;
  }

  Quaternion&
  Quaternion::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
    return *this;
  }

  Quaternion&
  Quaternion::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    w /= scale;
    return *this;
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
    return Math::radToDeg(Quaternion::angularDifferenceRad(a, b));
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

    float halfAngle = w * 0.5f;
    Vector3 imaginary = { x,y,z };

    return Quaternion(w * Math::cos(halfAngle), 
                      imaginary.normalized() * Math::sin(halfAngle));
  }

  void
  Quaternion::toNormRotator() {
    float halfAngle = w * 0.5f;
    Vector3 imaginary(x, y, z);
    imaginary.normalize();

    w = Math::cos(halfAngle);
    imaginary *= Math::sin(halfAngle);

    x = imaginary.x;
    y = imaginary.y;
    z = imaginary.z;
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
    return Math::isNearSame(a.x, b.x, error) &&
           Math::isNearSame(a.y, b.y, error) &&
           Math::isNearSame(a.z, b.z, error);
  }
  
  Vector3
  Quaternion::rotateAroundRadians(const float& theta, Vector3 toRotate, Vector3 axis) {
    Quaternion p = { toRotate.x, toRotate.y, toRotate.z, 0 };
    Vector3 axisToRotate = axis.normalized();
    Quaternion q = { theta,axisToRotate };

    q.toNormRotator();

    Quaternion qInverse = q.inversed();

    Quaternion result = q * p * qInverse;
    return Vector3(result.x, result.y, result.z);
  }

  void
  Quaternion::rotateAroundRadians(const float& theta, Vector3 axis) {
    Quaternion p = *this;
    Vector3 axisToRotate = axis.normalized();
    Quaternion q = { theta, axisToRotate };

    q.toNormRotator();

    Quaternion qInverse = q.inversed();

    Quaternion result = q * p * qInverse;
    *this = result;
  }

  void
  Quaternion::rotateAroundDegrees(const float& theta, Vector3 axis) {
    float radians = Math::degToRad(theta);
    rotateAroundRadians(radians, axis);
  }

  Vector3
  Quaternion::rotateAroundDegrees(const float& theta, Vector3 toRotate, Vector3 axis) {
    float radians = Math::radToDeg(theta);
    return rotateAroundRadians(radians, toRotate, axis);
  }

  Vector3
  Quaternion::rotateEulerRadians(Vector3 toRotate, float xAngle, float yAngle, float zAngle) {
    Quaternion p = { toRotate.x, toRotate.y, toRotate.z, 0 };

    Quaternion qX = { xAngle, Vector3::RIGHT };
    Quaternion qY = { yAngle, Vector3::UP };
    Quaternion qZ = { zAngle, Vector3::FRONT };
  
    qX.toNormRotator();
    qY.toNormRotator();
    qZ.toNormRotator();

    Quaternion qInverseX = qX.inversed();
    Quaternion qInverseY = qY.inversed();
    Quaternion qInverseZ = qZ.inversed();

    Quaternion resultX = qX * p       * qInverseX;
    Quaternion resultY = qY * resultX * qInverseY;
    Quaternion resultZ = qZ * resultY * qInverseZ;

    return Vector3(resultZ.x, resultZ.y, resultZ.z);
  }

  Vector3
  Quaternion::rotateEulerDegrees(Vector3 toRotate, float xAngle, float yAngle, float zAngle) {
    return rotateEulerRadians(toRotate,
                              Math::degToRad(xAngle), 
                              Math::degToRad(yAngle), 
                              Math::degToRad(zAngle));
  }

  void
  Quaternion::rotateAroundX(const float& theta) {
    Quaternion q = Quaternion::RIGHT;
    q.w = theta;
    q.toNormRotator();

    Quaternion qInverse = q.inversed();
    Quaternion result = q * *this *qInverse;
  }

  void
  Quaternion::rotateAroundY(const float& theta) {
    Quaternion q = Quaternion::UP;
    q.w = theta;
    q.toNormRotator();

    Quaternion qInverse = q.inversed();
    Quaternion result = q * *this *qInverse;
  }

  void
  Quaternion::rotateAroundZ(const float& theta) {

    Quaternion q = Quaternion::FRONT;
    q.w = theta;
    q.toNormRotator();

    Quaternion qInverse = q.inversed();
    Quaternion result = q * *this *qInverse;
    *this = result;
  }

  void
  Quaternion::setEulerRadians(float newX, float newY, float newZ) {

    float sinX = Math::sin(newX * 0.5f);
    float sinY = Math::sin(newY * 0.5f);
    float sinZ = Math::sin(newZ * 0.5f);

    float cosX = Math::cos(newX * 0.5f);
    float cosY = Math::cos(newY * 0.5f);
    float cosZ = Math::cos(newZ * 0.5f);

    w = (cosX * cosY * cosZ) + (sinX * sinY * sinZ);
    x = (sinX * cosY * cosZ) - (cosX * sinY * sinZ);
    y = (cosX * sinY * cosZ) + (sinX * cosY * sinZ);
    z = (cosX * cosY * sinZ) - (sinX * sinY * cosZ);
  }

  void
  Quaternion::setEulerDegrees(float newX, float newY, float newZ) {
    setEulerRadians(Math::degToRad(newX), 
                    Math::degToRad(newY), 
                    Math::degToRad(newZ));
    
  }

  Vector3
  Quaternion::toEulerDegrees() {


    Vector3 v = this->toEulerRadians();
    return Vector3(Math::radToDeg(v.x), 
                   Math::radToDeg(v.y), 
                   Math::radToDeg(v.z));
  }

  Vector3
  Quaternion::toEulerRadians() {
    
    Quaternion q = this->normalized();

    Vector3 v;
    
    
    v.x = Math::atan2(2 * ((q.w * q.x) + (q.y * q.z)),
                      1 - (2 * (Math::sqr(q.x) + Math::sqr(q.y))));
    
    v.y = Math::asin(2 * (((q.w*q.y) - (q.x * q.z))));
    
    v.z = Math::atan2(2 * ((q.w*q.z) + (q.x*q.y)),
                      1 - (2 * (Math::sqr(q.y) + Math::sqr(q.z))));
    
    return v;

  }

  Matrix3
  Quaternion::rotationMatrix() {

    Matrix3 m;

    m.m[0][0] = 1 - 2 * (y * y) - 2 * (z * z);
    m.m[1][0] =     2 * (x * y) - 2 * (z * w);
    m.m[2][0] =     2 * (x * z) + 2 * (y * w);

    m.m[0][1] =     2 * (x * y) + 2 * (z * w);
    m.m[1][1] = 1 - 2 * (x * x) - 2 * (z * z);
    m.m[2][1] =     2 * (y * z) - 2 * (x * w);
    
    m.m[0][2] =     2 * (x * z) - 2 * (y * w);
    m.m[1][2] =     2 * (y * z) + 2 * (x * w);
    m.m[2][2] = 1 - 2 * (x * x) - 2 * (y * y);

    return m;
  }


  const Quaternion Quaternion::ZERO   = Quaternion(0.0f);
  
  const Quaternion Quaternion::PURE   = Quaternion(0.0f);
  
  const Quaternion Quaternion::REAL   = Quaternion(Vector3(0.0f, 0.0f, 0.0f));
  
  const Quaternion Quaternion::RIGHT  = Quaternion(Vector3(1.0f, 0.0f, 0.0f));
  
  const Quaternion Quaternion::UP     = Quaternion(Vector3(0.0f, 1.0f, 0.0f));
  
  const Quaternion Quaternion::FRONT  = Quaternion(Vector3(0.0f, 0.0f, 1.0f));

}
