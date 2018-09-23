/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2i.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief point/Vector2 object with integer instead of floats
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

/**
 * #include
 */
#include "nauPrerequisitesUtil.h"
#include "nauMath.h"

namespace nauEngineSDK {
  class NAU_UTILITY_EXPORT nauVector2i {
  public:
    nauVector2i() = default;
    nauVector2i(int32 nx, int32 ny);
    explicit FORCEINLINE nauVector2i(int32 val) : x(val), y(val) {}
    const int32&
    operator()(uint32& index) const;
    
    int32&
    operator()(uint32& index);
    
    const int32
    operator[](uint32 index) const;

    int32&
    operator[](uint32 index);

    FORCEINLINE nauVector2i
    operator+(const nauVector2i& v) const;

    FORCEINLINE nauVector2i
    operator-(const nauVector2i& v) const;

    FORCEINLINE nauVector2i
    operator*(const nauVector2i& v) const;

    FORCEINLINE nauVector2i
    operator/(const nauVector2i& v) const;

    FORCEINLINE nauVector2i
    operator+(int32 plus) const;

    FORCEINLINE nauVector2i
    operator-(int32 minus) const;

    FORCEINLINE nauVector2i
    operator*(int32 times) const;

    FORCEINLINE nauVector2i
    operator/(int32 under) const;

    FORCEINLINE int32
    operator|(const nauVector2i v) const;

    FORCEINLINE int32
    operator^(const nauVector2i v) const;

    bool
    operator==(const nauVector2i& v) const;

    bool
    operator!=(const nauVector2i& v) const;

    bool
    operator<(const nauVector2i& v) const;

    bool
    operator>(const nauVector2i& v) const;

    bool
    operator<=(const nauVector2i& v) const;

    bool
    operator>=(const nauVector2i& v) const;

    FORCEINLINE nauVector2i
    operator-() const;

    FORCEINLINE nauVector2i
    operator+=(const nauVector2i& v);

    FORCEINLINE nauVector2i
    operator-=(const nauVector2i& v);

    FORCEINLINE nauVector2i
    operator*=(const nauVector2i& v);

    FORCEINLINE nauVector2i
    operator/=(const nauVector2i& v);

    FORCEINLINE nauVector2i
    operator*=(int32 scale);

    FORCEINLINE nauVector2i
    operator/=(int32 scale);

    static FORCEINLINE int32
    dot(const nauVector2i& a, const nauVector2i& b);

    static FORCEINLINE int32
    cross(const nauVector2i& a, const nauVector2i& b);

    static FORCEINLINE int32
    dotScale(const nauVector2i& a, const nauVector2i& b);

    static FORCEINLINE int32
    sqrDistance(const nauVector2i& a, const nauVector2i& b);

    static FORCEINLINE int32
    distance(const nauVector2i& a, const nauVector2i& b);

    void
    setValues(int32 newX, int32 newY);

    void
    min(const nauVector2i& v);

    void
    max(const nauVector2i& v);

    static nauVector2i
    roundFloor(nauVector2i lhs, int32 under);
    
    static nauVector2i
    roundFloor(nauVector2i lhs, nauVector2i under);

    static nauVector2i
    roundCeiln(nauVector2i lhs, int32 under);

    static nauVector2i
    roundCeiln(nauVector2i lhs, nauVector2i under);

    int32
    getHighest() const;

    int32
    getLowest() const;

    int32
    magnitude() const;

    int32
    sqrMagnitude() const;

    static FORCEINLINE nauVector2i
    normalized();

    void
    normalize() const;

    bool
    isZero() const;


    /**
     * Member declaration
     */

    int32 x;
    int32 y;

    static const nauVector2i ZERO;
    static const nauVector2i ONES;
    static const nauVector2i ONEY;
    static const nauVector2i ONEX;

  };

  /**
   * Method Implementation
   */



  FORCEINLINE nauVector2i::nauVector2i(int32 nx, int32 ny) : x(nx), y(ny) {}

  FORCEINLINE nauVector2i::nauVector2i(int32 nx, int32 ny) : x(nx), y(ny) {}
  /**
   * Overloaded operator declarations
   */
  FORCEINLINE const int32&
  nauVector2i::operator()(uint32& index) const {
    return (&x)[index];
  }
  FORCEINLINE int32&
    nauVector2i::operator()(uint32& index) {
    return (&x)[index];
  }

  FORCEINLINE int32&
  nauVector2i::operator[](uint32 index) {
    return (&x)[index];
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator+(const nauVector2i& v) const {
    return nauVector2i(x + v.x, y + v.y);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator-(const nauVector2i& v) const {
    return nauVector2i(x - v.x, y - v.y);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator*(const nauVector2i& v) const {
    return nauVector2i(x * v.x, y * v.y);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator/(const nauVector2i& v) const {
    return nauVector2i(x / v.x, y / v.y);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator+(int32 plus) const {
    return nauVector2i(x + plus, y + plus);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator-(int32 minus) const {
    return nauVector2i(x - minus, y + minus);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator*(int32 times) const {
    return nauVector2i(x * times, y * times);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator/(int32 under) const {
    return nauVector2i(x / under, y / under);
  }

  FORCEINLINE int32
    nauVector2i::operator|(const nauVector2i v) const {
    return x * v.x + y * v.y;
  }

  FORCEINLINE int32
    nauVector2i::operator^(const nauVector2i v) const {
    return x * v.x - y * v.y;
  }

  bool
    nauVector2i::operator==(const nauVector2i& v) const {
    return x == v.x && y == v.y;
  }

  bool
    nauVector2i::operator!=(const nauVector2i& v) const {
    return x != v.x || y != v.y;
  }

  bool
    nauVector2i::operator<(const nauVector2i& v) const {
    return x < v.x && y < v.y;
  }

  bool
    nauVector2i::operator>(const nauVector2i& v) const {
    return x > v.x && y > v.y;
  }

  bool
    nauVector2i::operator<=(const nauVector2i& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
    nauVector2i::operator>=(const nauVector2i& v) const {
    return x >= v.x && y >= v.y;
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator-() const {
    return nauVector2i(-x, -y);
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator+=(const nauVector2i& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator-=(const nauVector2i& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator*=(const nauVector2i& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator/=(const nauVector2i& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator*=(int32 scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  FORCEINLINE nauVector2i
    nauVector2i::operator/=(int32 scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

  FORCEINLINE int32
    nauVector2i::dot(const nauVector2i& a, const nauVector2i& b) {
    return a | b;
  }

  FORCEINLINE int32
    nauVector2i::cross(const nauVector2i& a, const nauVector2i& b) {
    return a ^ b;
  }
  FORCEINLINE int32
    nauVector2i::dotScale(const nauVector2i& a, const nauVector2i& b) {
    return (a | b) / a.magnitude();
  }
  FORCEINLINE int32
  nauVector2i::sqrDistance(const nauVector2i& a, const nauVector2i& b) {
    return nauMath::pow(a.x-b.x, 2) + nauMath::pow(a.y - b.y, 2);
  }

  FORCEINLINE int32
    nauVector2i::distance(const nauVector2i& a, const nauVector2i& b) {
    //  
  }

  void
    nauVector2i::setValues(int32 newX, int32 newY) {
    x = newX;
    y = newY;
  }

  void
    nauVector2i::min(const nauVector2i& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
    nauVector2i::max(const nauVector2i& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  void
    nauVector2i::floor() {
    //nauMath::floor(x);
    //nauMath::floor(y);
  }

  void
    nauVector2i::ceiling() {
    //nauMath::ceil(x);
    //nauMath::ceil(y);
  }

  void
    nauVector2i::round() {
    //nauMath::round(x);
    //nauMath::round(y);
  }

  void
    nauVector2i::roundHalf() {
    //nauMath::roundHalf(x);
    //nauMath::roundHalf(y);
  }

  int32
    nauVector2i::getHighest() const {
    return 0.0f;
    //return nauMath::max(x, y);
  }

  int32
    nauVector2i::getLowest() const {
    return 0.0f;
    //return nauMath::min(x, y);
  }

  int32
    nauVector2i::magnitude() const {
    return 0.0f;
    //return nauMath::sqrt(x*x + y*y);
  }

  int32
    nauVector2i::sqrMagnitude() const {
    return (x * x + y * y);
  }

  FORCEINLINE nauVector2i
    nauVector2i::normalized() {
    return nauVector2i(0, 0);
  }

  void
    nauVector2i::normalize() const {

  }

  bool
    nauVector2i::isZero() const {
    return 0.0f == x && 0.0f == y;
  }


}
