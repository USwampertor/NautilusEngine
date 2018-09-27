/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector4.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"

namespace nauEngineSDK {
  /**
  * Description:
  * Vector with 4 components x y z w
  * Sample usage:
  * Orientation vector
  */
  class NAU_UTILITY_EXPORT nauVector4
  {
    /**
    * Constructors
    */
    
    /**
     * @brief the simple default constructor
     */
    nauVector4() = default;

    /**
     * @brief Constructor 0.0f
     */
    nauVector4(float nx, float ny, float nz, float nw);

    /**
     * Overloaded operator declarations
     */

    /**
     * @brief returns the number at index position
     * @param the index where you wanna get the number
     * @return the object at index
     * 
     */
    float& operator[](uint32 index);

    /**
     * @brief access the number at index position
     * @param the index where you wanna get the number
     * @return the object reference at index
     *
     */
    float operator[](uint32 index) const;

    /**
     * @brief Sum of vectors
     * @param the other vector to add
     * @return a vector with added objects
     *
     */
    FORCEINLINE nauVector4
    operator+(const nauVector4& v) const;

    /**
     * @brief returns the number at index position
     * @param the index where you wanna get the number
     * @return the object at index
     *
     */
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

    nauVector4&
    operator+=(const nauVector4& v);

    nauVector4&
    operator-=(const nauVector4& v);

    nauVector4&
    operator*=(const nauVector4& v);

    nauVector4&
    operator/=(const nauVector4& v);

    nauVector4&
    operator*=(float scale);

    nauVector4&
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

    /**
     * @brief gets the sqrd magnitude of x y z from vector4
     * @param
     * @return the sqrMagnitude of the vector
     *
     */
    float
    sqrMagnitude3() const;

    /**
     * @brief returns a normalized vector of same
     * @param
     * @return a normalized version of same vector
     *
     */
    FORCEINLINE nauVector4
    normalized3();

    /**
     * @brief normalizes the vector
     * @param 
     * @return 
     * 
     */
    void
    normalize3() const;

    /**
     * @brief returns true if all components are 0
     * @param 
     * @return true if all components are 0
     * 
     */
    bool
    isZero() const;


    /**
     * Member declaration
     */
   public:
    
    /**
     * x component
     */
    float x;
    
    /**
     * y component
     */
    float y;
    
    /**
     * z component
     */
    float z;
    
    /**
     * w component
     */
    float w;

    /**
     * nauVector4 that has all values at 0
     */
    static const nauVector4 ZERO;

    /**
     * nauVector4 that has all values at 1
     */
    static const nauVector4 ONES;

    /**
     * nauVector4 that has x value at 1
     */
    static const nauVector4 ONEX;
    
    /**
     * nauVector4 that has y value at 1
     */
    static const nauVector4 ONEY;

    /**
     * nauVector4 that has z value at 1
     */
    static const nauVector4 ONEZ;

    /**
     * nauVector4 that has w value at 1
     */
    static const nauVector4 ONEW;

  };
  

}