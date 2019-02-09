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

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   Vector2 with integers instead of floats
  * Sample usage:
  * 	Vector2i(3,4) can be used for coordinates in a chess like game
  */
  class NAU_UTILITY_EXPORT Vector2i 
  {
   public:
    
    /**
     * Default Constructor
     */
    Vector2i() = default;

    /**
     * @brief Constructor with x y int arguments
     * @param x int value y int value
     * @return 
     * 
     */
    Vector2i(int32 nx, int32 ny);
    explicit FORCEINLINE Vector2i(int32 val) : x(val), y(val) {}

    /**
     * @brief () operator overload
     * @param index of the object we wanna get
     * @return value at index
     *
     */
    const int32&
    operator()(uint32& index) const;
    
    /**
     * @brief () operator overload
     * @param index of the object we wanna get
     * @return value at index
     *
     */
    int32&
    operator()(uint32& index);
    
    /**
     * @brief [] operator overload
     * @param index of the object we wanna get
     * @return value at index
     *
     */
    const int32
    operator[](uint32 index) const;

    /**
     * @brief [] operator overload
     * @param index of the object we wanna get
     * @return value at index
     *
     */
    int32&
    operator[](uint32 index);

    /**
     * @brief + operator overload
     * @param b the other matrix to add
     * @return a vector sum of *this and v
     *
     */
    FORCEINLINE Vector2i
    operator+(const Vector2i& v) const;

    /**
     * @brief - operator overload
     * @param b the other matrix to substract
     * @return a vector difference of *this and v
     *
     */
    FORCEINLINE Vector2i
    operator-(const Vector2i& v) const;

    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return a vector multiplication of *this times v
     *
     */
    FORCEINLINE Vector2i
    operator*(const Vector2i& v) const;

    /**
     * @brief / operator overload
     * @param b the other matrix to divide
     * @return a vector division of *this divided by v
     *
     */
    FORCEINLINE Vector2i
    operator/(const Vector2i& v) const;

    /**
     * @brief + operator overload
     * @param plus the float to add to all vector
     * @return a vector sum of *this + plus
     *
     */
    FORCEINLINE Vector2i
    operator+(int32 plus) const;

    /**
     * @brief - operator overload
     * @param minus the float to subtract to all vector
     * @return a vector difference of *this - minus
     *
     */
    FORCEINLINE Vector2i
    operator-(int32 minus) const;

    /**
     * @brief * operator overload
     * @param times the float to multiply all vector
     * @return a vector multiplication of *this times times
     *
     */
    FORCEINLINE Vector2i
    operator*(int32 times) const;

    /**
     * @brief / operator overload
     * @param under the float to divide all vector
     * @return a vector divided of *this divided by times
     *
     */
    FORCEINLINE Vector2i
    operator/(int32 under) const;

    /**
     * @brief | operator overload for dot product
     * @param the other vector
     * @return dot product
     *
     */
    FORCEINLINE int32
    operator|(const Vector2i v) const;

    /**
     * @brief ^ operator overload for cross product
     * @param the other vector
     * @return cross product
     *
     */
    FORCEINLINE int32
    operator^(const Vector2i v) const;

    /**
     * @brief == operator overload
     * @param the other vector to compare
     * @return true if this components are == to v components
     *
     */
    bool
    operator==(const Vector2i& v) const;

    /**
     * @brief != operator overload
     * @param the other vector to compare
     * @return true if this components are != to v components
     *
     */
    bool
    operator!=(const Vector2i& v) const;

    /**
     * @brief < operator overload
     * @param the other vector to compare
     * @return true if this components are < to v components
     *
     */
    bool
    operator<(const Vector2i& v) const;

    /**
     * @brief > operator overload
     * @param the other vector to compare
     * @return true if this components are > to v components
     *
     */
    bool
    operator>(const Vector2i& v) const;

    /**
     * @brief <= operator overload
     * @param the other vector to compare
     * @return true if this components are <= to v components
     *
     */
    bool
    operator<=(const Vector2i& v) const;

    /**
     * @brief >= operator overload
     * @param the other vector to compare
     * @return true if this components are >= to v components
     *
     */
    bool
    operator>=(const Vector2i& v) const;

    /**
     * @brief - operator overload
     * @param
     * @return the negative of the vector
     *
     */
    Vector2i
    operator-() const;

    /**
     * @brief += operator overload
     * @param the other vector to add
     * @return *this + v components
     *
     */
    Vector2i&
    operator+=(const Vector2i& v);

    /**
     * @brief -= operator overload
     * @param the other vector to subtract
     * @return *this - v components
     *
     */
    Vector2i&
    operator-=(const Vector2i& v);

    /**
     * @brief *= operator overload
     * @param the other vector to multiply
     * @return *this * v components
     *
     */
    Vector2i&
    operator*=(const Vector2i& v);

    /**
     * @brief /= operator overload
     * @param the other vector to divide
     * @return *this / v components
     *
     */
    Vector2i&
    operator/=(const Vector2i& v);

    /**
     * @brief *= operator overload
     * @param the float to multiply with
     * @return *this * float
     *
     */
    Vector2i&
    operator*=(int32 scale);

    /**
     * @brief /= operator overload
     * @param the float to divide the vector
     * @return *this / float
     *
     */
    Vector2i&
    operator/=(int32 scale);

    /**
     * @brief the dot product
     * @param a nauVector2 and b nauVector2
     * @return the dot product between a and b
     *
     */
    static FORCEINLINE int32
    dot(const Vector2i& a, const Vector2i& b);

    /**
     * @brief the cross product
     * @param a nauVector2 and b nauVector2
     * @return the cross product between a and b
     *
     */
    static FORCEINLINE int32
    cross(const Vector2i& a, const Vector2i& b);

    /**
     * @brief the scale of b over a
     * @param a nauVector2 that is the reflection and b nauVector2 that reflects over
     * @return scale of b in a
     *
     */
    static FORCEINLINE int32
    dotScale(const Vector2i& a, const Vector2i& b);

    /**
     * @brief the square distance
     * @param a nauVector2 and b nauVector2
     * @return the square distance bewteen the two points
     *
     */
    static FORCEINLINE int32
    sqrDistance(const Vector2i& a, const Vector2i& b);

    /**
     * @brief the distance between two points in 2d space
     * @param a nauVector2 and b nauVector2
     * @return the distance bewteen the two points
     *
     */
    static FORCEINLINE int32
    distance(const Vector2i& a, const Vector2i& b);

    /**
     * @brief sets the value of a nauVector2
     * @param float x and y
     * @return
     *
     */
    void
    setValues(int32 newX, int32 newY);

    /**
     * @brief gets the min between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    min(const Vector2i& v);

    /**
     * @brief gets the max between two vectors
     * @param the other vector to compare
     * @return
     *
     */
    void
    max(const Vector2i& v);
    
    /**
     * @brief gets the highest value of the vector
     * @param
     * @return
     *
     */
    int32
    getHighest() const;

    /**
     * @brief gets the least value of the vector
     * @param
     * @return
     *
     */
    int32
    getLowest() const;

    /**
     * @brief gets the magnitude value of the vector
     * @param
     * @return
     *
     */
    int32
    magnitude() const;

    /**
     * @brief gets the squared magnitude value of the vector
     * @param
     * @return
     *
     */
    int32
    sqrMagnitude() const;

    /**
     * @brief gets the normalized version of the vector
     * @param
     * @return the normalized vector
     *
     */
    Vector2i 
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
     * static const
     */

   public:

    /**
     * vauVector2 with all values 0
     */
    static const Vector2i ZERO;

    /**
     * vauVector2 with all values 1
     */
    static const Vector2i ONES;

    /**
     * vauVector2 with x value 1
     */
    static const Vector2i ONEX;

    /**
     * vauVector2 with y value 1
     */
    static const Vector2i ONEY;

    /**
     * vauVector2 with y value 1. This is our right in our world
     */
    static const Vector2i UP;

    /**
     * vauVector2 with x value 1. This is our up in our world
     */
    static const Vector2i RIGHT;

    /**
     * Member declaration
     */

   public:

    /**
     * x component
     */
    int32 x;

    /**
     * y component
     */
    int32 y;

  };

}
