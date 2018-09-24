#pragma once


#ifndef _INC_VECTOR4_H_
# define _INC_VECTOR4_H_
#endif

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"

namespace nauEngineSDK {

  class nauVector4
  {
    /**
    * Constructors
    */
    
    /**
     * @brief the simple default constructor
     */
    FORCEINLINE nauVector4() = default;

    /**
     * @brief Constructor 0.0f
     */
    FORCEINLINE nauVector4(float nx, float ny, float nz, float nw);

    /**
     * Overloaded operator declarations
     */
    float& operator[](uint32 index);

    float operator[](uint32 index) const;

    FORCEINLINE nauVector4
    operator+(const nauVector4& v) const;

    FORCEINLINE nauVector4
    operator-(const nauVector4& v) const;

    FORCEINLINE nauVector4
    operator*(const nauVector4& v) const;

    FORCEINLINE nauVector4
    operator/(const nauVector4& v) const;

    FORCEINLINE nauVector4
    operator+(float plus) const;

    FORCEINLINE nauVector4
    operator-(float minus) const;

    FORCEINLINE nauVector4
    operator*(float times) const;

    FORCEINLINE nauVector4
    operator/(float under) const;

    FORCEINLINE float
    operator|(const nauVector4 v) const;

    FORCEINLINE float
    operator^(const nauVector4 v) const;

    bool
    operator==(const nauVector4& v) const;

    bool
    operator!=(const nauVector4& v) const;

    bool
    operator<(const nauVector4& v) const;

    bool
    operator>(const nauVector4& v) const;

    bool
    operator<=(const nauVector4& v) const;

    bool
    operator>=(const nauVector4& v) const;

    FORCEINLINE nauVector4
    operator-() const;

    FORCEINLINE nauVector4
    operator+=(const nauVector4& v);

    FORCEINLINE nauVector4
    operator-=(const nauVector4& v);

    FORCEINLINE nauVector4
    operator*=(const nauVector4& v);

    FORCEINLINE nauVector4
    operator/=(const nauVector4& v);

    FORCEINLINE nauVector4
    operator*=(float scale);

    FORCEINLINE nauVector4
    operator/=(float scale);

    static FORCEINLINE float
    dot3(const nauVector4& a, const nauVector4& b);

    static FORCEINLINE float
    dot4(const nauVector4& a, const nauVector4& b);

    static FORCEINLINE float
    cross(const nauVector4& a, const nauVector4& b);

    static FORCEINLINE float
    dotScale(const nauVector4& a, const nauVector4& b);

    static FORCEINLINE float
    sqrDistance(const nauVector4& a, const nauVector4& b);

    static FORCEINLINE float
    distance(const nauVector4& a, const nauVector4& b);

    void
    setValues(float newX, float newY, float newZ, float newW);

    void
    min(const nauVector4& v);

    void
    max(const nauVector4& v);

    void
    floor();

    void
    ceiling();

    void
    round();

    void
    roundHalf();

    float
    getHighest() const;

    float
    getLowest() const;

    float
    magnitude() const;

    float
    sqrMagnitude() const;

    float
    magnitude3() const;

    float
    sqrMagnitude3() const;

    FORCEINLINE nauVector4
    normalized3();

    void
    normalize3() const;

    bool
    isZero() const;


    /**
     * Member declaration
     */
  public:
    float x;
    float y;
    float z;
    float w;

    static const nauVector4 ZERO;

    static const nauVector4 ONES;

    static const nauVector4 ONEY;

    static const nauVector4 ONEX;

    static const nauVector4 ONEZ;

    static const nauVector4 ONEW;

  };
  /**
   * Method Implementation
   */



  FORCEINLINE nauVector4::nauVector4(float nx, float ny, float nz, float nw) 
  : 
  x(nx), 
  y(ny), 
  z(nz),
  w(nw) {}

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
    return nauVector4(x + v.x, y + v.y, z + v.z,w + v.w);
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

  FORCEINLINE nauVector4
  nauVector4::operator+=(const nauVector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
  }

  FORCEINLINE nauVector4
  nauVector4::operator-=(const nauVector4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
  }

  FORCEINLINE nauVector4
  nauVector4::operator*=(const nauVector4& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
  }

  FORCEINLINE nauVector4
  nauVector4::operator/=(const nauVector4& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w /= v.w;
    return *this;
  }

  FORCEINLINE nauVector4
  nauVector4::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
    return *this;
  }

  FORCEINLINE nauVector4
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
    return nauMath::sqrt(
      nauMath::sqr(a.x - b.x) +
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
    nauMath::floor(x);
    nauMath::floor(y);
    nauMath::floor(z);
    nauMath::floor(w);
  }

  void
  nauVector4::ceiling() {
    nauMath::ceil(x);
    nauMath::ceil(y);
    nauMath::ceil(z);
    nauMath::ceil(w);
  }

  void
  nauVector4::round() {
    nauMath::round(x);
    nauMath::round(y);
    nauMath::round(z);
    nauMath::round(w);
  }

  void
  nauVector4::roundHalf() {
    nauMath::roundHalf(x);
    nauMath::roundHalf(y);
    nauMath::roundHalf(z);
    nauMath::roundHalf(w);
  }

  float
  nauVector4::getHighest() const {
    return nauMath::max3(x, y,nauMath::max(z, w));
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
    float unit = nauMath::invSqrt(x*x+y*y+z*z);
    return nauVector4(
                      (x * unit ),
                      (y * unit ),
                      (z * unit ),
                       w);
  }

  void
  nauVector4::normalize3() const {
  }

  bool
  nauVector4::isZero() const {
    return 0.0f == x && 0.0f == y && 0.0f == z && w == 0.0f;
  }

}