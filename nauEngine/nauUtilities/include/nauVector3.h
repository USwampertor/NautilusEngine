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

#ifndef _INC_VECTOR3_H_
# define _INC_VECTOR3_H_
#endif

#include "nauMath.h"
#include "nauPrerequisitesUtil.h"

/**
 * TODO
 * normalize and normalized
 */

namespace nauEngineSDK {

  class NAU_UTILITY_EXPORT nauVector3 {
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

    FORCEINLINE nauVector3
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
  
}
