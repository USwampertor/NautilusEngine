/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauVector3.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/24 2018
 * @brief 3D point
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
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
  /**
  * Description:
  *   A vector3 object for position and rotation in 3d
  * Sample usage:
  * 	Vetor3 position = 0,0,0;
  */
  class NAU_UTILITY_EXPORT nauVector3 
  {
   public:
    /**
     * Constructors
     */

    /**
     * @brief the simple default constructor
     */
    nauVector3() = default;

    /**
     * @brief Constructor 0.0f
     */
    nauVector3(float nx, float ny, float nz);

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
    FORCEINLINE nauVector3
    operator+(const nauVector3& v) const;

    /**
     * @brief - operator overload
     * @param b the other matrix to substract
     * @return a vector difference of *this and v
     *
     */
    FORCEINLINE nauVector3
    operator-(const nauVector3& v) const;

    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return a vector multiplication of *this times v
     *
     */
    FORCEINLINE nauVector3
    operator*(const nauVector3& v) const;

    /**
     * @brief / operator overload
     * @param b the other matrix to divide
     * @return a vector division of *this divided by v
     *
     */
    FORCEINLINE nauVector3
    operator/(const nauVector3& v) const;

    /**
     * @brief + operator overload
     * @param plus the float to add to all vector
     * @return a vector sum of *this + plus
     *
     */
    FORCEINLINE nauVector3
    operator+(float plus) const;

    /**
     * @brief - operator overload
     * @param minus the float to subtract to all vector
     * @return a vector difference of *this - minus
     *
     */
    FORCEINLINE nauVector3
    operator-(float minus) const;

    /**
     * @brief * operator overload
     * @param times the float to multiply all vector
     * @return a vector multiplication of *this times times
     *
     */
    FORCEINLINE nauVector3
    operator*(float times) const;

    /**
     * @brief / operator overload
     * @param under the float to divide all vector
     * @return a vector divided of *this divided by times
     *
     */
    FORCEINLINE nauVector3
    operator/(float under) const;

    /**
     * @brief | operator overload for dot product
     * @param the other vector
     * @return dot product
     *
     */
    FORCEINLINE float
    operator|(const nauVector3 v) const;

    /**
     * @brief ^ operator overload for cross product
     * @param the other vector
     * @return cross product
     *
     */
    FORCEINLINE float
    operator^(const nauVector3 v) const;

    /**
     * @brief == operator overload
     * @param the other vector to compare
     * @return true if this components are == to v components
     *
     */
    bool
    operator==(const nauVector3& v) const;

    /**
     * @brief != operator overload
     * @param the other vector to compare
     * @return true if this components are != to v components
     *
     */
    bool
    operator!=(const nauVector3& v) const;

    /**
     * @brief < operator overload
     * @param the other vector to compare
     * @return true if this components are < to v components
     *
     */
    bool
    operator<(const nauVector3& v) const;

    /**
     * @brief > operator overload
     * @param the other vector to compare
     * @return true if this components are > to v components
     *
     */
    bool
    operator>(const nauVector3& v) const;

    /**
     * @brief <= operator overload
     * @param the other vector to compare
     * @return true if this components are <= to v components
     *
     */
    bool
    operator<=(const nauVector3& v) const;

    /**
     * @brief >= operator overload
     * @param the other vector to compare
     * @return true if this components are >= to v components
     *
     */
    bool
    operator>=(const nauVector3& v) const;

    /**
     * @brief - operator overload
     * @param
     * @return the negative of the vector
     *
     */
    nauVector3
    operator-() const;

    /**
     * @brief += operator overload
     * @param the other vector to add
     * @return *this + v components
     *
     */
    nauVector3&
    operator+=(const nauVector3& v);

    /**
     * @brief -= operator overload
     * @param the other vector to subtract
     * @return *this - v components
     *
     */
    nauVector3&
    operator-=(const nauVector3& v);

    /**
     * @brief *= operator overload
     * @param the other vector to multiply
     * @return *this * v components
     *
     */
    nauVector3&
    operator*=(const nauVector3& v);

    /**
     * @brief /= operator overload
     * @param the other vector to divide
     * @return *this / v components
     *
     */
    nauVector3&
    operator/=(const nauVector3& v);

    /**
     * @brief *= operator overload
     * @param the float to multiply with
     * @return *this * float
     *
     */
    nauVector3&
    operator*=(float scale);

    /**
     * @brief /= operator overload
     * @param the float to divide the vector
     * @return *this / float
     *
     */
    nauVector3&
    operator/=(float scale);

    /**
     * @brief the dot product
     * @param a nauVector3 and b nauVector3
     * @return the dot product between a and b
     *
     */
    static FORCEINLINE float
    dot(const nauVector3& a, const nauVector3& b);

    /**
     * @brief the cross product
     * @param a nauVector3 and b nauVector3
     * @return the cross product between a and b
     *
     */
    static FORCEINLINE float
    cross(const nauVector3& a, const nauVector3& b);

    /**
     * @brief the scale of b over a
     * @param a nauVector3 that is the reflection and b nauVector3 that reflects over
     * @return scale of b in a
     *
     */
    static FORCEINLINE float
    dotScale(const nauVector3& a, const nauVector3& b);

    /**
     * @brief the square distance
     * @param a nauVector3 and b nauVector3
     * @return the square distance between the two points
     *
     */
    static float
    sqrDistance(const nauVector3& a, const nauVector3& b);

    /**
     * @brief the distance between two points in 2d space
     * @param a nauVector3 and b nauVector3
     * @return the distance between the two points
     *
     */
    static FORCEINLINE float
    distance(const nauVector3& a, const nauVector3& b);

    /**
     * @brief sets the value of a nauVector3
     * @param float x and y
     * @return
     *
     */
    void
    setValues(float newX, float newY, float newZ);

    /**
     * @brief gets the min between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    min(const nauVector3& v);

    /**
     * @brief gets the max between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    max(const nauVector3& v);

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
    FORCEINLINE nauVector3
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
     * nauVector3 that has all values 0
     */
    static const nauVector3 ZERO;

    /**
     * nauVector3 that has all values 1
     */
    static const nauVector3 ONES;

    /**
     * nauVector3 that has x value 1
     */
    static const nauVector3 ONEX;

    /**
     * nauVector3 that has y value 1
     */
    static const nauVector3 ONEY;

    /**
     * nauVector3 that has x value 1
     */
    static const nauVector3 ONEZ;

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

    
  };
  
}
