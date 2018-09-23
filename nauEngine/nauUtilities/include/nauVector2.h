/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief Vector2 object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#ifndef _INC_VECTOR2_H_
# define _INC_VECTOR2_H_
#endif
/**
 * #include
 */
#include "nauPrerequisitesUtilh.h"
#include "nauMath.h"
/**
* Description:
*   This is out simple vector2f, nothing to special about it
* Sample usage:
* 	Vector2 foo (2.0f, 3.0f);
*/
namespace nauEngineSDK {
  //forward declaration
  class Vector3;

  class Vector2 {
   public:
    /**
     * Constructors
     */

    /**
     * @brief the simple default constructor
     */
    FORCEINLINE Vector2() = default;

    /**
     * @brief Constructor 0.0f
     */
    FORCEINLINE Vector2(float nx, float ny);
    /**
     * @brief Constructor based on a Vector3
     */
    explicit inline Vector2(const Vector3& v);


    /**
     * Overloaded operator declarations
     */
    float& operator[](uint32 index);

    float& operator[](uint32 index) const;
    
    FORCEINLINE Vector2 
    operator+(const Vector2& v) const;

    FORCEINLINE Vector2 
    operator-(const Vector2& v) const;

    FORCEINLINE Vector2 
    operator*(const Vector2& v) const;

    FORCEINLINE Vector2 
    operator/(const Vector2& v) const;

    FORCEINLINE Vector2 
    operator+(float plus) const;

    FORCEINLINE Vector2 
    operator-(float minus) const;

    FORCEINLINE Vector2 
    operator*(float times) const;

    FORCEINLINE Vector2 
    operator/(float under) const;

    FORCEINLINE float 
    operator|(const Vector2 v) const;

    FORCEINLINE float 
    operator^(const Vector2 v) const;

    bool 
    operator==(const Vector2& v) const;

    bool 
    operator!=(const Vector2& v) const;

    bool 
    operator<(const Vector2& v) const;

    bool 
    operator>(const Vector2& v) const;

    bool 
    operator<=(const Vector2& v) const;

    bool 
    operator>=(const Vector2& v) const;

    FORCEINLINE Vector2 
    operator-() const;

    FORCEINLINE Vector2
    operator+=(const Vector2& v);

    FORCEINLINE Vector2
    operator-=(const Vector2& v);

    FORCEINLINE Vector2
    operator*=(const Vector2& v);

    FORCEINLINE Vector2
    operator/=(const Vector2& v);
    
    FORCEINLINE Vector2
    operator*=(float scale);

    FORCEINLINE Vector2
    operator/=(float scale);

    static FORCEINLINE float 
    dot(const Vector2& a, const Vector2& b);

    static FORCEINLINE float
    cross(const Vector2& a, const Vector2& b);

    static FORCEINLINE float
    dotScale(const Vector2& a, const Vector2& b);
    
    static FORCEINLINE float
    sqrDistance(const Vector2& a, const Vector2& b);

    static FORCEINLINE float
    distance(const Vector2& a, const Vector2& b);

    void
    setValues(float newX, float newY);

    void
    min(const Vector2& v);

    void
    max(const Vector2& v);

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

    static FORCEINLINE Vector2
    normalized();
    
    void
    normalize() const;

    bool
    isZero() const;

    
    /**
     * Member declaration
     */

    float x;
    float y;

    static const Vector2 ZERO;
    static const Vector2 ONES;
    static const Vector2 ONEY;
    static const Vector2 ONEX;

  };
  /**
   * Method Implementation
   */



  FORCEINLINE Vector2::Vector2(float nx, float ny) : x(nx), y(ny) {}

  FORCEINLINE Vector2::Vector2(float nx, float ny) : x(nx), y(ny) {}
  /**
   * Overloaded operator declarations
   */
  float&
    Vector2::operator[](uint32 index) {
  }

  float&
    Vector2::operator[](uint32 index) const {

  }
  
  FORCEINLINE Vector2
  Vector2::operator+(const Vector2& v) const {
    return Vector2(x+v.x, y+v.y);
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
    return Vector2(x - minus, y + minus);
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

  FORCEINLINE Vector2
  Vector2::operator-() const {
    return Vector2(-x,-y);
  }

  FORCEINLINE Vector2
  Vector2::operator+=(const Vector2& v) {
    x += v.x; 
    y += v.y; 
    return *this;
  }

  FORCEINLINE Vector2
    Vector2::operator-=(const Vector2& v) {
    x -= v.x; 
    y -= v.y; 
    return *this;
  }

  FORCEINLINE Vector2
  Vector2::operator*=(const Vector2& v) {
    x *= v.x; 
    y *= v.y; 
    return *this;
  }

  FORCEINLINE Vector2
  Vector2::operator/=(const Vector2& v) {
    x /= v.x; 
    y /= v.y; 
    return *this;
  }

  FORCEINLINE Vector2
  Vector2::operator*=(float scale) {
    x *= scale; 
    y *= scale; 
    return *this;
  }

  FORCEINLINE Vector2
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
    return (a|b)/a.magnitude();
  }
  FORCEINLINE float
  Vector2::sqrDistance(const Vector2& a, const Vector2& b) {
    //return nauMath::pow(a.x-b.x, 2) + nauMath(a.y - b.y, 2);
  }

  FORCEINLINE float
  Vector2::distance(const Vector2& a, const Vector2& b) {
    //  
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
    //nauMath::floor(x);
    //nauMath::floor(y);
  }

  void
  Vector2::ceiling() {
    //nauMath::ceil(x);
    //nauMath::ceil(y);
  }

  void
  Vector2::round() {
    //nauMath::round(x);
    //nauMath::round(y);
  }

  void
  Vector2::roundHalf() {
    //nauMath::roundHalf(x);
    //nauMath::roundHalf(y);
  }

  float
  Vector2::getHighest() const {
    return 0.0f;
    //return nauMath::max(x, y);
  }

  float
  Vector2::getLowest() const {
    return 0.0f;
    //return nauMath::min(x, y);
  }

  float
  Vector2::magnitude() const {
    return 0.0f;
    //return nauMath::sqrt(x*x + y*y);
  }

  float
  Vector2::sqrMagnitude() const {
    return (x * x + y * y);
  }

  FORCEINLINE Vector2
  Vector2::normalized() {
   return Vector2(0,0);
  }

  void
  Vector2::normalize() const {

  }

  bool
  Vector2::isZero() const {
    return 0.0f == x && 0.0f == y;
  }

  


}