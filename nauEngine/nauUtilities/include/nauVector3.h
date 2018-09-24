/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector3.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/24 2018
 * @brief 3D point
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#ifndef _INC_VECTOR2_H_
# define _INC_VECTOR2_H_
#endif

#include "nauMath.h"
#include "nauPrerequisitesUtil.h"

/**
 * TODO
 * normalize and normalized
 */

namespace nauEngineSDK {
  class nauVector3 {
   public:
    /**
     * Constructors
     */

    /**
     * @brief the simple default constructor
     */
    FORCEINLINE nauVector3() = default;

    /**
     * @brief Constructor 0.0f
     */
    FORCEINLINE nauVector3(float nx, float ny, float nz);
   
    /**
     * Overloaded operator declarations
     */
    float& operator[](uint32 index);

    float operator[](uint32 index) const;

    FORCEINLINE nauVector3
    operator+(const nauVector3& v) const;

    FORCEINLINE nauVector3
    operator-(const nauVector3& v) const;

    FORCEINLINE nauVector3
    operator*(const nauVector3& v) const;

    FORCEINLINE nauVector3
    operator/(const nauVector3& v) const;

    FORCEINLINE nauVector3
    operator+(float plus) const;

    FORCEINLINE nauVector3
    operator-(float minus) const;

    FORCEINLINE nauVector3
    operator*(float times) const;

    FORCEINLINE nauVector3
    operator/(float under) const;

    FORCEINLINE float
    operator|(const nauVector3 v) const;

    FORCEINLINE float
    operator^(const nauVector3 v) const;

    bool
    operator==(const nauVector3& v) const;

    bool
    operator!=(const nauVector3& v) const;

    bool
    operator<(const nauVector3& v) const;

    bool
    operator>(const nauVector3& v) const;

    bool
    operator<=(const nauVector3& v) const;

    bool
    operator>=(const nauVector3& v) const;

    FORCEINLINE nauVector3
    operator-() const;

    FORCEINLINE nauVector3
    operator+=(const nauVector3& v);

    FORCEINLINE nauVector3
    operator-=(const nauVector3& v);

    FORCEINLINE nauVector3
    operator*=(const nauVector3& v);

    FORCEINLINE nauVector3
    operator/=(const nauVector3& v);

    FORCEINLINE nauVector3
    operator*=(float scale);

    FORCEINLINE nauVector3
    operator/=(float scale);

    static FORCEINLINE float
    dot(const nauVector3& a, const nauVector3& b);

    static FORCEINLINE float
    cross(const nauVector3& a, const nauVector3& b);

    static FORCEINLINE float
    dotScale(const nauVector3& a, const nauVector3& b);

    static FORCEINLINE float
    sqrDistance(const nauVector3& a, const nauVector3& b);

    static FORCEINLINE float
    distance(const nauVector3& a, const nauVector3& b);

    void
    setValues(float newX, float newY, float newZ);

    void
    min(const nauVector3& v);

    void
    max(const nauVector3& v);

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

    static FORCEINLINE nauVector3
    normalized();

    void
    normalize() const;

    bool
    isZero() const;


    /**
     * Member declaration
     */
   public:
    float x;
    float y;
    float z;

    static const nauVector3 ZERO;

    static const nauVector3 ONES;
    
    static const nauVector3 ONEY;
    
    static const nauVector3 ONEX;

    static const nauVector3 ONEZ;
  };
  /**
   * Method Implementation
   */



  FORCEINLINE nauVector3::nauVector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz){}

  /**
   * Overloaded operator declarations
   */
  float&
  nauVector3::operator[](uint32 index) {
    return (&x)[index];

  }

  float
  nauVector3::operator[](uint32 index) const {
    return (&x)[index];
  }

  FORCEINLINE nauVector3
  nauVector3::operator+(const nauVector3& v) const {
    return nauVector3(x + v.x, y + v.y, z + v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator-(const nauVector3& v) const {
    return nauVector3(x - v.x, y - v.y, z - v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator*(const nauVector3& v) const {
    return nauVector3(x * v.x, y * v.y, z * v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator/(const nauVector3& v) const {
    return nauVector3(x / v.x, y / v.y, z / v.z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator+(float plus) const {
    return nauVector3(x + plus, y + plus, z + plus);
  }

  FORCEINLINE nauVector3
  nauVector3::operator-(float minus) const {
    return nauVector3(x - minus, y - minus, y - minus);
  }

  FORCEINLINE nauVector3
  nauVector3::operator*(float times) const {
    return nauVector3(x * times, y * times, z * times);
  }

  FORCEINLINE nauVector3
  nauVector3::operator/(float under) const {
    return nauVector3(x / under, y / under, z / under);
  }

  FORCEINLINE float
  nauVector3::operator|(const nauVector3 v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  FORCEINLINE float
  nauVector3::operator^(const nauVector3 v) const {
    return x * v.x - y * v.y - z * v.z;
  }

  bool
  nauVector3::operator==(const nauVector3& v) const {
    return x == v.x && y == v.y && z == v.z;
  }

  bool
  nauVector3::operator!=(const nauVector3& v) const {
    return x != v.x || y != v.y || z == v.z;
  }

  bool
  nauVector3::operator<(const nauVector3& v) const {
    return x < v.x && y < v.y && z < v.z;
  }

  bool
  nauVector3::operator>(const nauVector3& v) const {
    return x > v.x && y > v.y && z > v.z;
  }

  bool
  nauVector3::operator<=(const nauVector3& v) const {
    return x <= v.x && y <= v.y && z <= v.z;
  }

  bool
  nauVector3::operator>=(const nauVector3& v) const {
    return x >= v.x && y >= v.y && z >= v.z;
  }

  FORCEINLINE nauVector3
  nauVector3::operator-() const {
    return nauVector3(-x, -y, -z);
  }

  FORCEINLINE nauVector3
  nauVector3::operator+=(const nauVector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  FORCEINLINE nauVector3
  nauVector3::operator-=(const nauVector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  FORCEINLINE nauVector3
  nauVector3::operator*=(const nauVector3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  FORCEINLINE nauVector3
  nauVector3::operator/=(const nauVector3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  FORCEINLINE nauVector3
  nauVector3::operator*=(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
  }

  FORCEINLINE nauVector3
  nauVector3::operator/=(float scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    return *this;
  }

  FORCEINLINE float
  nauVector3::dot(const nauVector3& a, const nauVector3& b) {
    return a | b;
  }

  FORCEINLINE float
  nauVector3::cross(const nauVector3& a, const nauVector3& b) {
    return a ^ b;
  }

  FORCEINLINE float
  nauVector3::dotScale(const nauVector3& a, const nauVector3& b) {
    return (a | b) / nauMath::sqr(a.magnitude());
  }

  FORCEINLINE float
  nauVector3::sqrDistance(const nauVector3& a, const nauVector3& b) {
    return  nauMath::pow(a.x - b.x, 2.0f) + 
            nauMath::pow(a.y - b.y, 2.0f) + 
            nauMath::pow(a.z - b.z, 2.0f);
  }

  FORCEINLINE float
  nauVector3::distance(const nauVector3& a, const nauVector3& b) {
    return nauMath::sqrt(
                          nauMath::sqr(a.x - b.x) + 
                          nauMath::sqr(a.y - b.y) +
                          nauMath::sqr(a.z - b.z));
  }

  void
  nauVector3::setValues(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
  }

  void
  nauVector3::min(const nauVector3& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
    if (v.z < z) z = v.z;
  }

  void
  nauVector3::max(const nauVector3& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
    if (v.z > z) z = v.z;
  }

  void
  nauVector3::floor() {
    nauMath::floor(x);
    nauMath::floor(y);
    nauMath::floor(z);
  }

  void
  nauVector3::ceiling() {
    nauMath::ceil(x);
    nauMath::ceil(y);
    nauMath::ceil(z);
  }

  void
  nauVector3::round() {
    nauMath::round(x);
    nauMath::round(y);
    nauMath::round(z);
  }

  void
  nauVector3::roundHalf() {
    nauMath::roundHalf(x);
    nauMath::roundHalf(y);
    nauMath::roundHalf(z);
  }

  float
  nauVector3::getHighest() const {
    return nauMath::max3(x, y, z);
  }

  float
  nauVector3::getLowest() const {
    return nauMath::min3(x, y, z);
  }

  float
  nauVector3::magnitude() const {
    return nauMath::sqrt(x * x + y * y + z * z);
  }

  float
  nauVector3::sqrMagnitude() const {
    return (x * x + y * y + z * z);
  }

  FORCEINLINE nauVector3
  nauVector3::normalized() {
    return nauVector3(0, 0, 0);
  }

  void
  nauVector3::normalize() const {

  }

  bool
  nauVector3::isZero() const {
    return 0.0f == x && 0.0f == y && 0.0f == z;
  }
}

