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
  class nauVector3;

  class NAU_UTILITY_EXPORT nauVector2 {
   public:
    /**
     * Constructors
     */

    /**
     * @brief the simple default constructor
     */
    nauVector2() = default;

    /**
     * @brief Constructor 0.0f
     */
    nauVector2(float nx, float ny);
    /**
     * @brief Constructor based on a Vector3
     */
    explicit inline nauVector2(const nauVector3& v);


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

    FORCEINLINE nauVector2
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

}
