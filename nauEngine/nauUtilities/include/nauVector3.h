/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Vector3.h
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

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"

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
  class NAU_UTILITY_EXPORT Vector3 
  {
   public:
    /**
     * Constructors
     */

    /**
     * @brief the simple default constructor
     */
    Vector3() = default;

    /**
     * @brief Constructor 0.0f
     */
    Vector3(float nx, float ny, float nz);

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
    Vector3
    operator+(const Vector3& v) const;

    /**
     * @brief - operator overload
     * @param b the other matrix to substract
     * @return a vector difference of *this and v
     *
     */
    Vector3
    operator-(const Vector3& v) const;

    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return a vector multiplication of *this times v
     *
     */
    Vector3
    operator*(const Vector3& v) const;

    /**
     * @brief / operator overload
     * @param b the other matrix to divide
     * @return a vector division of *this divided by v
     *
     */
    Vector3
    operator/(const Vector3& v) const;

    /**
     * @brief + operator overload
     * @param plus the float to add to all vector
     * @return a vector sum of *this + plus
     *
     */
    Vector3
    operator+(float plus) const;

    /**
     * @brief - operator overload
     * @param minus the float to subtract to all vector
     * @return a vector difference of *this - minus
     *
     */
    Vector3
    operator-(float minus) const;

    /**
     * @brief * operator overload
     * @param times the float to multiply all vector
     * @return a vector multiplication of *this times times
     *
     */
    Vector3
    operator*(float times) const;

    /**
     * @brief / operator overload
     * @param under the float to divide all vector
     * @return a vector divided of *this divided by times
     *
     */
    Vector3
    operator/(float under) const;

    /**
     * @brief | operator overload for dot product
     * @param the other vector
     * @return dot product
     *
     */
    float
    operator|(const Vector3 v) const;

    /**
     * @brief ^ operator overload for cross product
     * @param the other vector
     * @return cross product
     *
     */
    Vector3
    operator^(const Vector3 v) const;

    /**
     * @brief == operator overload
     * @param the other vector to compare
     * @return true if this components are == to v components
     *
     */
    bool
    operator==(const Vector3& v) const;

    /**
     * @brief != operator overload
     * @param the other vector to compare
     * @return true if this components are != to v components
     *
     */
    bool
    operator!=(const Vector3& v) const;

    /**
     * @brief < operator overload
     * @param the other vector to compare
     * @return true if this components are < to v components
     *
     */
    bool
    operator<(const Vector3& v) const;

    /**
     * @brief > operator overload
     * @param the other vector to compare
     * @return true if this components are > to v components
     *
     */
    bool
    operator>(const Vector3& v) const;

    /**
     * @brief <= operator overload
     * @param the other vector to compare
     * @return true if this components are <= to v components
     *
     */
    bool
    operator<=(const Vector3& v) const;

    /**
     * @brief >= operator overload
     * @param the other vector to compare
     * @return true if this components are >= to v components
     *
     */
    bool
    operator>=(const Vector3& v) const;

    /**
     * @brief - operator overload
     * @param
     * @return the negative of the vector
     *
     */
    Vector3
    operator-() const;

    /**
     * @brief += operator overload
     * @param the other vector to add
     * @return *this + v components
     *
     */
    Vector3&
    operator+=(const Vector3& v);

    /**
     * @brief -= operator overload
     * @param the other vector to subtract
     * @return *this - v components
     *
     */
    Vector3&
    operator-=(const Vector3& v);

    /**
     * @brief *= operator overload
     * @param the other vector to multiply
     * @return *this * v components
     *
     */
    Vector3&
    operator*=(const Vector3& v);

    /**
     * @brief /= operator overload
     * @param the other vector to divide
     * @return *this / v components
     *
     */
    Vector3&
    operator/=(const Vector3& v);

    /**
     * @brief *= operator overload
     * @param the float to multiply with
     * @return *this * float
     *
     */
    Vector3&
    operator*=(float scale);

    /**
     * @brief /= operator overload
     * @param the float to divide the vector
     * @return *this / float
     *
     */
    Vector3&
    operator/=(float scale);

    /**
     * @brief the dot product
     * @param a Vector3 and b Vector3
     * @return the dot product between a and b
     *
     */
    static float
    dot(const Vector3& a, const Vector3& b);

    /**
     * @brief the cross product
     * @param a Vector3 and b Vector3
     * @return the cross product between a and b
     *
     */
    static Vector3
    cross(const Vector3& a, const Vector3& b);

    /**
     * @brief the scale of b over a
     * @param a Vector3 that is the reflection and b Vector3 that reflects over
     * @return scale of b in a
     *
     */
    static float
    dotScale(const Vector3& a, const Vector3& b);

    /**
     * @brief the square distance
     * @param a Vector3 and b Vector3
     * @return the square distance between the two points
     *
     */
    static float
    sqrDistance(const Vector3& a, const Vector3& b);

    /**
     * @brief the distance between two points in 2d space
     * @param a Vector3 and b Vector3
     * @return the distance between the two points
     *
     */
    static float
    distance(const Vector3& a, const Vector3& b);

    /**
     * @brief sets the value of a Vector3
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
    min(const Vector3& v);

    /**
     * @brief gets the max between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    max(const Vector3& v);

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
    Vector3
    normalized() const;

    /**
     * @brief normalizes the vector
     * @param
     * @return
     *
     */
    void
    normalize();

    /**
     * @brief Checks if the vector is empty (0s)
     * @param
     * @return true if it is empty
     *
     */
    bool
    isZero() const;

    /**
     * @brief Checks if one vector is near the same as another vector based in an error
     * @param Vector other, error (default is LITTLENUMBER)
     * @return true if based on the error is the same
     *
     */
    static bool
    isSame(const Vector3& a, const Vector3& b, float error = Math::SMALLNUMBER);

    /**
     * static const
     */
    
   public:

    /**
     * Vector3 that has all values 0
     */
    static const Vector3 ZERO;

    /**
     * Vector3 that has all values 1
     */
    static const Vector3 ONES;

    /**
     * Vector3 that has x value 1
     */
    static const Vector3 ONEX;

    /**
     * Vector3 that has y value 1
     */
    static const Vector3 ONEY;

    /**
     * Vector3 that has x value 1
     */
    static const Vector3 ONEZ;

    /**
     * Vector3 that has x value 1
     */
    static const Vector3 RIGHT;

    /**
     * Vector3 with y value 1
     */
    static const Vector3 UP;

    /**
     * Vector3 with z value 1
     */
    static const Vector3 FRONT;

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
