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
#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
//#include "nauVector3.h"

/**
* Description:
*   This is our simple vector2f, nothing to special about it. Its a nice point
* Sample usage:
* 	Vector2 foo (2.0f, 3.0f);
*/
namespace nauEngineSDK {
  //forward declaration
  //class nauVector3;

  class nauVector2 {
   public:
    /**
     * Constructors
     */

    /**
     * @brief the simple default constructor
     */
    FORCEINLINE nauVector2() = default;

    /**
     * @brief Constructor 0.0f
     */
    FORCEINLINE nauVector2(float nx, float ny);
    /**
     * @brief Constructor based on a Vector3
     */
    //explicit inline nauVector2(const nauVector3& v);


    /**
     * Overloaded operator declarations
     */
    float& operator[](uint32 index);

    float operator[](uint32 index) const;
    
    FORCEINLINE nauVector2 
    operator+(const nauVector2& v) const;

    FORCEINLINE nauVector2 
    operator-(const nauVector2& v) const;

    FORCEINLINE nauVector2 
    operator*(const nauVector2& v) const;

    FORCEINLINE nauVector2 
    operator/(const nauVector2& v) const;

    FORCEINLINE nauVector2 
    operator+(float plus) const;

    FORCEINLINE nauVector2 
    operator-(float minus) const;

    FORCEINLINE nauVector2 
    operator*(float times) const;

    FORCEINLINE nauVector2 
    operator/(float under) const;

    FORCEINLINE float 
    operator|(const nauVector2 v) const;

    FORCEINLINE float 
    operator^(const nauVector2 v) const;

    bool 
    operator==(const nauVector2& v) const;

    bool 
    operator!=(const nauVector2& v) const;

    bool 
    operator<(const nauVector2& v) const;

    bool 
    operator>(const nauVector2& v) const;

    bool 
    operator<=(const nauVector2& v) const;

    bool 
    operator>=(const nauVector2& v) const;

    FORCEINLINE nauVector2 
    operator-() const;

    FORCEINLINE nauVector2
    operator+=(const nauVector2& v);

    FORCEINLINE nauVector2
    operator-=(const nauVector2& v);

    FORCEINLINE nauVector2
    operator*=(const nauVector2& v);

    FORCEINLINE nauVector2
    operator/=(const nauVector2& v);
    
    FORCEINLINE nauVector2
    operator*=(float scale);

    FORCEINLINE nauVector2
    operator/=(float scale);

    static FORCEINLINE float 
    dot(const nauVector2& a, const nauVector2& b);

    static FORCEINLINE float
    cross(const nauVector2& a, const nauVector2& b);

    static FORCEINLINE float
    dotScale(const nauVector2& a, const nauVector2& b);
    
    static FORCEINLINE float
    sqrDistance(const nauVector2& a, const nauVector2& b);

    static FORCEINLINE float
    distance(const nauVector2& a, const nauVector2& b);

    void
    setValues(float newX, float newY);

    void
    min(const nauVector2& v);

    void
    max(const nauVector2& v);

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

    static FORCEINLINE nauVector2
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

    static const nauVector2 ZERO;
    
    static const nauVector2 ONES;
    
    static const nauVector2 ONEY;
    
    static const nauVector2 ONEX;

  };
  /**
   * Method Implementation
   */



  FORCEINLINE nauVector2::nauVector2(float nx, float ny) : x(nx), y(ny) {}

  /**
   * Overloaded operator declarations
   */
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
    return nauVector2(x+v.x, y+v.y);
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

  FORCEINLINE nauVector2
  nauVector2::operator-() const {
    return nauVector2(-x,-y);
  }

  FORCEINLINE nauVector2
  nauVector2::operator+=(const nauVector2& v) {
    x += v.x; 
    y += v.y; 
    return *this;
  }

  FORCEINLINE nauVector2
    nauVector2::operator-=(const nauVector2& v) {
    x -= v.x; 
    y -= v.y; 
    return *this;
  }

  FORCEINLINE nauVector2
  nauVector2::operator*=(const nauVector2& v) {
    x *= v.x; 
    y *= v.y; 
    return *this;
  }

  FORCEINLINE nauVector2
  nauVector2::operator/=(const nauVector2& v) {
    x /= v.x; 
    y /= v.y; 
    return *this;
  }

  FORCEINLINE nauVector2
  nauVector2::operator*=(float scale) {
    x *= scale; 
    y *= scale; 
    return *this;
  }

  FORCEINLINE nauVector2
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
    return (a|b)/a.magnitude();
  }

  FORCEINLINE float
  nauVector2::sqrDistance(const nauVector2& a, const nauVector2& b) {
    return nauMath::pow(a.x-b.x, 2.0f) + nauMath::pow(a.y - b.y, 2.0f);
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
    nauMath::floor(x);
    nauMath::floor(y);
  }

  void
  nauVector2::ceiling() {
    nauMath::ceil(x);
    nauMath::ceil(y);
  }

  void
  nauVector2::round() {
    nauMath::round(x);
    nauMath::round(y);
  }

  void
  nauVector2::roundHalf() {
    nauMath::roundHalf(x);
    nauMath::roundHalf(y);
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
   return nauVector2(0,0);
  }

  void
  nauVector2::normalize() const {

  }

  bool
  nauVector2::isZero() const {
    return 0.0f == x && 0.0f == y;
  }
}
