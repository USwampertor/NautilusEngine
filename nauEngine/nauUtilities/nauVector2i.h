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
#include "nauPrerequisitesUtilh.h"
#include "nauMath.h"

namespace nauEngineSDK {
  class NAU_UTILITY_EXPORT Vector2i {
  public:
    Vector2i() = default;
    Vector2i(int32 nx, int32 ny);
    explicit FORCEINLINE Vector2i(int32 val) : x(val), y(val) {}
    const int32&
    operator()(uint32& index) const;
    
    int32&
    operator()(uint32& index);
    
    const int32
    operator[](uint32 index) const;

    int32&
    operator[](uint32 index);

    FORCEINLINE Vector2i
    operator+(const Vector2i& v) const;

    FORCEINLINE Vector2i
    operator-(const Vector2i& v) const;

    FORCEINLINE Vector2i
    operator*(const Vector2i& v) const;

    FORCEINLINE Vector2i
    operator/(const Vector2i& v) const;

    FORCEINLINE Vector2i
    operator+(int32 plus) const;

    FORCEINLINE Vector2i
    operator-(int32 minus) const;

    FORCEINLINE Vector2i
    operator*(int32 times) const;

    FORCEINLINE Vector2i
    operator/(int32 under) const;

    FORCEINLINE int32
    operator|(const Vector2i v) const;

    FORCEINLINE int32
    operator^(const Vector2i v) const;

    bool
    operator==(const Vector2i& v) const;

    bool
    operator!=(const Vector2i& v) const;

    bool
    operator<(const Vector2i& v) const;

    bool
    operator>(const Vector2i& v) const;

    bool
    operator<=(const Vector2i& v) const;

    bool
    operator>=(const Vector2i& v) const;

    FORCEINLINE Vector2i
    operator-() const;

    FORCEINLINE Vector2i
    operator+=(const Vector2i& v);

    FORCEINLINE Vector2i
    operator-=(const Vector2i& v);

    FORCEINLINE Vector2i
    operator*=(const Vector2i& v);

    FORCEINLINE Vector2i
    operator/=(const Vector2i& v);

    FORCEINLINE Vector2i
    operator*=(int32 scale);

    FORCEINLINE Vector2i
    operator/=(int32 scale);

    static FORCEINLINE int32
    dot(const Vector2i& a, const Vector2i& b);

    static FORCEINLINE int32
    cross(const Vector2i& a, const Vector2i& b);

    static FORCEINLINE int32
    dotScale(const Vector2i& a, const Vector2i& b);

    static FORCEINLINE int32
    sqrDistance(const Vector2i& a, const Vector2i& b);

    static FORCEINLINE int32
    distance(const Vector2i& a, const Vector2i& b);

    void
    setValues(int32 newX, int32 newY);

    void
    min(const Vector2i& v);

    void
    max(const Vector2i& v);

    static Vector2i
    roundFloor(Vector2i lhs, int32 under);
    
    static Vector2i
    roundFloor(Vector2i lhs, Vector2i under);

    static Vector2i
    roundCeiln(Vector2i lhs, int32 under);

    static Vector2i
    roundCeiln(Vector2i lhs, Vector2i under);

    int32
    getHighest() const;

    int32
    getLowest() const;

    int32
    magnitude() const;

    int32
    sqrMagnitude() const;

    static FORCEINLINE Vector2i
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

    static const Vector2i ZERO;
    static const Vector2i ONES;
    static const Vector2i ONEY;
    static const Vector2i ONEX;

  };

  /**
   * Method Implementation
   */



  FORCEINLINE Vector2i::Vector2i(int32 nx, int32 ny) : x(nx), y(ny) {}

  FORCEINLINE Vector2i::Vector2i(int32 nx, int32 ny) : x(nx), y(ny) {}
  /**
   * Overloaded operator declarations
   */
  FORCEINLINE const int32&
  Vector2i::operator()(uint32& index) const {
    return (&x)[index];
  }
  FORCEINLINE int32&
    Vector2i::operator()(uint32& index) {
    return (&x)[index];
  }

  FORCEINLINE int32&
  Vector2i::operator[](uint32 index) {
    return (&x)[index];
  }

  FORCEINLINE Vector2i
    Vector2i::operator+(const Vector2i& v) const {
    return Vector2i(x + v.x, y + v.y);
  }

  FORCEINLINE Vector2i
    Vector2i::operator-(const Vector2i& v) const {
    return Vector2i(x - v.x, y - v.y);
  }

  FORCEINLINE Vector2i
    Vector2i::operator*(const Vector2i& v) const {
    return Vector2i(x * v.x, y * v.y);
  }

  FORCEINLINE Vector2i
    Vector2i::operator/(const Vector2i& v) const {
    return Vector2i(x / v.x, y / v.y);
  }

  FORCEINLINE Vector2i
    Vector2i::operator+(int32 plus) const {
    return Vector2i(x + plus, y + plus);
  }

  FORCEINLINE Vector2i
    Vector2i::operator-(int32 minus) const {
    return Vector2i(x - minus, y + minus);
  }

  FORCEINLINE Vector2i
    Vector2i::operator*(int32 times) const {
    return Vector2i(x * times, y * times);
  }

  FORCEINLINE Vector2i
    Vector2i::operator/(int32 under) const {
    return Vector2i(x / under, y / under);
  }

  FORCEINLINE int32
    Vector2i::operator|(const Vector2i v) const {
    return x * v.x + y * v.y;
  }

  FORCEINLINE int32
    Vector2i::operator^(const Vector2i v) const {
    return x * v.x - y * v.y;
  }

  bool
    Vector2i::operator==(const Vector2i& v) const {
    return x == v.x && y == v.y;
  }

  bool
    Vector2i::operator!=(const Vector2i& v) const {
    return x != v.x || y != v.y;
  }

  bool
    Vector2i::operator<(const Vector2i& v) const {
    return x < v.x && y < v.y;
  }

  bool
    Vector2i::operator>(const Vector2i& v) const {
    return x > v.x && y > v.y;
  }

  bool
    Vector2i::operator<=(const Vector2i& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
    Vector2i::operator>=(const Vector2i& v) const {
    return x >= v.x && y >= v.y;
  }

  FORCEINLINE Vector2i
    Vector2i::operator-() const {
    return Vector2i(-x, -y);
  }

  FORCEINLINE Vector2i
    Vector2i::operator+=(const Vector2i& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  FORCEINLINE Vector2i
    Vector2i::operator-=(const Vector2i& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  FORCEINLINE Vector2i
    Vector2i::operator*=(const Vector2i& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  FORCEINLINE Vector2i
    Vector2i::operator/=(const Vector2i& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  FORCEINLINE Vector2i
    Vector2i::operator*=(int32 scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  FORCEINLINE Vector2i
    Vector2i::operator/=(int32 scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

  FORCEINLINE int32
    Vector2i::dot(const Vector2i& a, const Vector2i& b) {
    return a | b;
  }

  FORCEINLINE int32
    Vector2i::cross(const Vector2i& a, const Vector2i& b) {
    return a ^ b;
  }
  FORCEINLINE int32
    Vector2i::dotScale(const Vector2i& a, const Vector2i& b) {
    return (a | b) / a.magnitude();
  }
  FORCEINLINE int32
    Vector2i::sqrDistance(const Vector2i& a, const Vector2i& b) {
    //return nauMath::pow(a.x-b.x, 2) + nauMath(a.y - b.y, 2);
  }

  FORCEINLINE int32
    Vector2i::distance(const Vector2i& a, const Vector2i& b) {
    //  
  }

  void
    Vector2i::setValues(int32 newX, int32 newY) {
    x = newX;
    y = newY;
  }

  void
    Vector2i::min(const Vector2i& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
    Vector2i::max(const Vector2i& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  void
    Vector2i::floor() {
    //nauMath::floor(x);
    //nauMath::floor(y);
  }

  void
    Vector2i::ceiling() {
    //nauMath::ceil(x);
    //nauMath::ceil(y);
  }

  void
    Vector2i::round() {
    //nauMath::round(x);
    //nauMath::round(y);
  }

  void
    Vector2i::roundHalf() {
    //nauMath::roundHalf(x);
    //nauMath::roundHalf(y);
  }

  int32
    Vector2i::getHighest() const {
    return 0.0f;
    //return nauMath::max(x, y);
  }

  int32
    Vector2i::getLowest() const {
    return 0.0f;
    //return nauMath::min(x, y);
  }

  int32
    Vector2i::magnitude() const {
    return 0.0f;
    //return nauMath::sqrt(x*x + y*y);
  }

  int32
    Vector2i::sqrMagnitude() const {
    return (x * x + y * y);
  }

  FORCEINLINE Vector2i
    Vector2i::normalized() {
    return Vector2i(0, 0);
  }

  void
    Vector2i::normalize() const {

  }

  bool
    Vector2i::isZero() const {
    return 0.0f == x && 0.0f == y;
  }


}
