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

}
