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

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"

namespace nauEngineSDK {
  //forward declaration?
  class nauVector3;

  /**
  * Description:
  *   This is our simple vector2f, nothing to special about it. Its a nice point
  * Sample usage:
  * 	Vector2 foo (2.0f, 3.0f);
  */
  class NAU_UTILITY_EXPORT nauVector2 
  {
   public:
    /**
     * Constructors
     */

     /**
      * Default constructor
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
     * @brief [] operator overload
     * @param index of the object we wanna get
     * @return value at index
     *
     */
    float& 
    operator[](uint32 index);

    /**
     * @brief [] operator overload
     * @param index of the object we wanna get
     * @return value at index
     *
     */
    float 
    operator[](uint32 index) const;

    /**
     * @brief + operator overload
     * @param b the other matrix to add
     * @return a vector sum of *this and v
     *
     */
    FORCEINLINE nauVector2
    operator+(const nauVector2& v) const;

    /**
     * @brief - operator overload
     * @param b the other matrix to substract
     * @return a vector difference of *this and v
     *
     */
    FORCEINLINE nauVector2
    operator-(const nauVector2& v) const;

    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return a vector multiplication of *this times v
     *
     */
    FORCEINLINE nauVector2
    operator*(const nauVector2& v) const;


    /**
     * @brief / operator overload
     * @param b the other matrix to divide
     * @return a vector division of *this divided by v
     *
     */
    FORCEINLINE nauVector2
    operator/(const nauVector2& v) const;

    /**
     * @brief + operator overload
     * @param plus the float to add to all vector
     * @return a vector sum of *this + plus
     *
     */
    FORCEINLINE nauVector2
    operator+(float plus) const;

    /**
     * @brief - operator overload
     * @param minus the float to subtract to all vector
     * @return a vector difference of *this - minus
     *
     */
    FORCEINLINE nauVector2
    operator-(float minus) const;

    /**
     * @brief * operator overload
     * @param times the float to multiply all vector
     * @return a vector multiplication of *this times times
     *
     */
    FORCEINLINE nauVector2
    operator*(float times) const;

    /**
     * @brief / operator overload
     * @param under the float to divide all vector
     * @return a vector divided of *this divided by times
     *
     */
    FORCEINLINE nauVector2
    operator/(float under) const;


    /**
     * @brief | operator overload for dot product
     * @param the other vector
     * @return dot product
     *
     */
    FORCEINLINE float
    operator|(const nauVector2 v) const;

    /**
     * @brief ^ operator overload for cross product
     * @param the other vector
     * @return cross product
     *
     */
    FORCEINLINE float
    operator^(const nauVector2 v) const;


    /**
     * @brief == operator overload
     * @param the other vector to compare
     * @return true if this components are == to v components
     *
     */
    bool
    operator==(const nauVector2& v) const;

    /**
     * @brief != operator overload
     * @param the other vector to compare
     * @return true if this components are != to v components
     *
     */
    bool
    operator!=(const nauVector2& v) const;

    /**
     * @brief < operator overload
     * @param the other vector to compare
     * @return true if this components are < to v components
     *
     */
    bool
    operator<(const nauVector2& v) const;

    /**
     * @brief > operator overload
     * @param the other vector to compare
     * @return true if this components are > to v components
     *
     */
    bool
    operator>(const nauVector2& v) const;

    /**
     * @brief <= operator overload
     * @param the other vector to compare
     * @return true if this components are <= to v components
     *
     */
    bool
    operator<=(const nauVector2& v) const;

    /**
     * @brief >= operator overload
     * @param the other vector to compare
     * @return true if this components are >= to v components
     *
     */
    bool
    operator>=(const nauVector2& v) const;

    /**
     * @brief - operator overload
     * @param
     * @return the negative of the vector
     *
     */
    FORCEINLINE nauVector2
    operator-() const;

    /**
     * @brief += operator overload
     * @param the other vector to add
     * @return *this + v components
     *
     */
    nauVector2&
    operator+=(const nauVector2& v);

    /**
     * @brief -= operator overload
     * @param the other vector to subtract
     * @return *this - v components
     *
     */
    nauVector2&
    operator-=(const nauVector2& v);

    /**
     * @brief *= operator overload
     * @param the other vector to multiply
     * @return *this * v components
     *
     */
    nauVector2&
    operator*=(const nauVector2& v);

    /**
     * @brief /= operator overload
     * @param the other vector to divide
     * @return *this / v components
     *
     */
    nauVector2&
    operator/=(const nauVector2& v);

    /**
     * @brief *= operator overload
     * @param the float to multiply with
     * @return *this * float
     *
     */
    nauVector2&
    operator*=(float scale);

    /**
     * @brief /= operator overload
     * @param the float to divide the vector
     * @return *this / float
     *
     */
    nauVector2&
    operator/=(float scale);

    /**
     * @brief the dot product
     * @param a nauVector2 and b nauVector2
     * @return the dot product between a and b
     *
     */
    static FORCEINLINE float
    dot(const nauVector2& a, const nauVector2& b);

    /**
     * @brief the cross product
     * @param a nauVector2 and b nauVector2
     * @return the cross product between a and b
     *
     */
    static FORCEINLINE float
    cross(const nauVector2& a, const nauVector2& b);

    /**
     * @brief the scale of b over a
     * @param a nauVector2 that is the reflection and b nauVector2 that reflects over
     * @return scale of b in a
     *
     */
    static FORCEINLINE float
    dotScale(const nauVector2& a, const nauVector2& b);

    /**
     * @brief the square distance
     * @param a nauVector2 and b nauVector2
     * @return the square distance bewteen the two points
     *
     */
    static FORCEINLINE float
    sqrDistance(const nauVector2& a, const nauVector2& b);


    /**
     * @brief the distance between two points in 2d space
     * @param a nauVector2 and b nauVector2
     * @return the distance bewteen the two points
     *
     */
    static FORCEINLINE float
    distance(const nauVector2& a, const nauVector2& b);

    /**
     * @brief sets the value of a nauVector2
     * @param float x and y
     * @return
     *
     */
    void
    setValues(float newX, float newY);

    /**
     * @brief gets the min between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    min(const nauVector2& v);

    /**
     * @brief gets the max between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    max(const nauVector2& v);

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
     * @brief gets the magnitude value of the vector
     * @param
     * @return
     *
     */
    float
    magnitude() const;

    /**
     * @brief gets the squared magnitude value of the vector
     * @param
     * @return
     *
     */
    float
    sqrMagnitude() const;

    /**
     * @brief gets the normalized version of the vector
     * @param
     * @return the normalized vector
     *
     */
    FORCEINLINE nauVector2
    normalized();

    /**
     * @brief normalizes the vector
     * @param
     * @return
     *
     */
    void
    normalize() const;

    /**
     * @brief Checks if the vector is empty (0s)
     * @param 
     * @return true if it is empty
     *
     */
    bool
    isZero() const;

    /**
     * static const
     */

   public:
    
    /**
     * vauVector2 with all values 0
     */
    static const nauVector2 ZERO;

    /**
     * vauVector2 with all values 1
     */
    static const nauVector2 ONES;

    /**
     * vauVector2 with x value 1
     */
    static const nauVector2 ONEX;

    /**
     * vauVector2 with y value 1
     */
    static const nauVector2 ONEY;

    /**
     * Member declaration
     */

   public:

    /**
     * x component of the vector
     */
    float x;

    /**
     * y component of the vector
     */
    float y;

  };
}
