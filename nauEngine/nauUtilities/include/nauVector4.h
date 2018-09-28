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
  *   Vector with 4 components x y z w
  * Sample usage:
  *   Orientation vector
  */
  class NAU_UTILITY_EXPORT nauVector4 
  {
   public:
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
    float& 
    operator[](uint32 index);

    /**
     * @brief access the number at index position
     * @param the index where you wanna get the number
     * @return the object reference at index
     *
     */
    float 
    operator[](uint32 index) const;

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

    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return a vector multiplication of *this times v
     *
     */
    FORCEINLINE nauVector4
    operator*(const nauVector4& v) const;

    /**
     * @brief / operator overload
     * @param b the other matrix to divide
     * @return a vector division of *this divided by v
     *
     */
    FORCEINLINE nauVector4
    operator/(const nauVector4& v) const;

    /**
     * @brief + operator overload
     * @param plus the float to add to all vector
     * @return a vector sum of *this + plus
     *
     */
    FORCEINLINE nauVector4
    operator+(float plus) const;

    /**
     * @brief - operator overload
     * @param minus the float to subtract to all vector
     * @return a vector difference of *this - minus
     *
     */
    FORCEINLINE nauVector4
    operator-(float minus) const;

    /**
     * @brief * operator overload
     * @param times the float to multiply all vector
     * @return a vector multiplication of *this times times
     *
     */
    FORCEINLINE nauVector4
    operator*(float times) const;

    /**
     * @brief / operator overload
     * @param under the float to divide all vector
     * @return a vector divided of *this divided by times
     *
     */
    FORCEINLINE nauVector4
    operator/(float under) const;

    /**
     * @brief | operator overload for dot product
     * @param the other vector
     * @return dot product
     *
     */
    FORCEINLINE float
    operator|(const nauVector4 v) const;

    /**
     * @brief ^ operator overload for cross product
     * @param the other vector
     * @return cross product
     *
     */
    FORCEINLINE float
    operator^(const nauVector4 v) const;

    /**
     * @brief == operator overload
     * @param the other vector to compare
     * @return true if this components are == to v components
     *
     */
    bool
    operator==(const nauVector4& v) const;

    /**
     * @brief != operator overload
     * @param the other vector to compare
     * @return true if this components are != to v components
     *
     */
    bool
    operator!=(const nauVector4& v) const;

    /**
     * @brief < operator overload
     * @param the other vector to compare
     * @return true if this components are < to v components
     *
     */
    bool
    operator<(const nauVector4& v) const;

    /**
     * @brief > operator overload
     * @param the other vector to compare
     * @return true if this components are > to v components
     *
     */
    bool
    operator>(const nauVector4& v) const;

    /**
     * @brief <= operator overload
     * @param the other vector to compare
     * @return true if this components are <= to v components
     *
     */
    bool
    operator<=(const nauVector4& v) const;

    /**
     * @brief >= operator overload
     * @param the other vector to compare
     * @return true if this components are >= to v components
     *
     */
    bool
    operator>=(const nauVector4& v) const;

    /**
     * @brief - operator overload
     * @param
     * @return the negative of the vector
     *
     */
    FORCEINLINE nauVector4
    operator-() const;

    /**
     * @brief += operator overload
     * @param the other vector to add
     * @return *this + v components
     *
     */
    nauVector4&
    operator+=(const nauVector4& v);

    /**
     * @brief -= operator overload
     * @param the other vector to subtract
     * @return *this - v components
     *
     */
    nauVector4&
    operator-=(const nauVector4& v);

    /**
     * @brief *= operator overload
     * @param the other vector to multiply
     * @return *this * v components
     *
     */
    nauVector4&
    operator*=(const nauVector4& v);

    /**
     * @brief /= operator overload
     * @param the other vector to divide
     * @return *this / v components
     *
     */
    nauVector4&
    operator/=(const nauVector4& v);

    /**
     * @brief *= operator overload
     * @param the float to multiply with
     * @return *this * float
     *
     */
    nauVector4&
    operator*=(float scale);

    /**
     * @brief /= operator overload
     * @param the float to divide the vector
     * @return *this / float
     *
     */
    nauVector4&
    operator/=(float scale);

    /**
     * @brief the dot product from x y z
     * @param a nauVector2 and b nauVector2
     * @return the dot product between a and b
     *
     */
    static FORCEINLINE float
    dot3(const nauVector4& a, const nauVector4& b);

    /**
     * @brief the dot product from x y z w
     * @param a nauVector4 and b nauVector4
     * @return the dot product between a and b
     *
     */
    static FORCEINLINE float
    dot4(const nauVector4& a, const nauVector4& b);

    /**
     * @brief the cross product
     * @param a nauVector4 and b nauVector4
     * @return the cross product between a and b
     *
     */
    static FORCEINLINE float
    cross(const nauVector4& a, const nauVector4& b);

    /**
     * @brief the scale of b over a
     * @param a nauVector4 that is the reflection and b nauVector4 that reflects over
     * @return scale of b in a
     *
     */
    static FORCEINLINE float
    dotScale(const nauVector4& a, const nauVector4& b);

    /**
     * @brief the square distance
     * @param a nauVector4 and b nauVector4
     * @return the square distance bewteen the two points
     *
     */
    static FORCEINLINE float
    sqrDistance(const nauVector4& a, const nauVector4& b);

    /**
     * @brief the distance between two points in 2d space
     * @param a nauVector4 and b nauVector4
     * @return the distance bewteen the two points
     *
     */
    static FORCEINLINE float
    distance(const nauVector4& a, const nauVector4& b);

    /**
     * @brief sets the value of a nauVector4
     * @param float x and y
     * @return
     *
     */
    void
    setValues(float newX, float newY, float newZ, float newW);

    /**
     * @brief gets the min between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    min(const nauVector4& v);

    /**
     * @brief gets the max between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    max(const nauVector4& v);

    /**
     * @brief floors the components
     * @param
     * @return
     *
     */
    void
    floor();

    /**
     * @brief ceils the components
     * @param
     * @return
     *
     */
    void
    ceiling();

    /**
     * @brief rounds the components x.0 <- -> y.0
     * @param
     * @return
     *
     */
    void
    round();

    /**
     * @brief rounds components taking in account also x.0 - x.5 - y.0
     * @param
     * @return
     *
     */
    void
    roundHalf();

    /**
     * @brief gets the highest value of the vector
     * @param
     * @return
     *
     */
    float
    getHighest() const;

    /**
     * @brief gets the least value of the vector
     * @param
     * @return
     *
     */
    float
    getLowest() const;

    /**
     * @brief gets the magnitude of x y z w from vector4
     * @param
     * @return the sqrMagnitude of the vector
     *
     */
    float
    magnitude() const;

    /**
     * @brief gets the sqrd magnitude of x y z w from vector4
     * @param
     * @return the sqrMagnitude of the vector
     *
     */
    float
    sqrMagnitude() const;

    /**
     * @brief gets the magnitude of x y z from vector4
     * @param
     * @return the sqrMagnitude of the vector
     *
     */
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
     * static const declaration
     */

   public:
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

  };
  
}
