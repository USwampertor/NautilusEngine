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
  

}