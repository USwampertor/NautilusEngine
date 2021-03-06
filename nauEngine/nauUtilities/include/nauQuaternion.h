/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauQuaternion.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauMatrix4.h"

namespace nauEngineSDK {
  class NAU_UTILITY_EXPORT nauQuaternion {

   public:
    
    /**
     * Default constructor
     */
    nauQuaternion() = default;

    /**
     * @brief Constructor setting values x y z w
     * @param x y z w components for the quaternion
     * @return 
     * 
     */
    nauQuaternion(const float nx, const float ny, const float nz, const float nw);
    
    /**
     * @brief + operator overload
     * @param b the other matrix to add
     * @return a vector sum of *this and v
     *
     */
    FORCEINLINE nauQuaternion
    operator+(const nauQuaternion& other) const;
    
    /**
     * @brief - operator overload
     * @param b the other matrix to substract
     * @return a vector difference of *this and v
     *
     */
    FORCEINLINE nauQuaternion
    operator-(const nauQuaternion& other) const;
    
    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return a vector multiplication of *this times v
     *
     */
    FORCEINLINE nauQuaternion
    operator*(const nauQuaternion& other) const;
    
    /**
     * @brief / operator overload
     * @param b the other matrix to divide
     * @return a vector division of *this divided by v
     *
     */
    FORCEINLINE nauQuaternion
    operator/(const nauQuaternion& other) const;
    
    /**
     * @brief == operator overload
     * @param the other vector to compare
     * @return true if this components are == to v components
     *
     */
    FORCEINLINE bool
    operator==(const nauQuaternion& other);

    /**
     * @brief < operator overload
     * @param the other vector to compare
     * @return true if this components are < to v components
     *
     */
    FORCEINLINE bool
    operator<(const nauQuaternion& other);

    /**
     * @brief > operator overload
     * @param the other vector to compare
     * @return true if this components are > to v components
     *
     */
    FORCEINLINE bool
    operator>(const nauQuaternion& other);

    /**
     * @brief <= operator overload
     * @param the other vector to compare
     * @return true if this components are <= to v components
     *
     */
    FORCEINLINE bool
    operator<=(const nauQuaternion& other);

    /**
     * @brief >= operator overload
     * @param the other vector to compare
     * @return true if this components are >= to v components
     *
     */
    FORCEINLINE bool
    operator>=(const nauQuaternion& other);
    
    /**
     * @brief += operator overload
     * @param the other vector to add
     * @return *this + v components
     *
     */
    nauQuaternion&
    operator+=(const nauQuaternion& other);
    
    /**
     * @brief -= operator overload
     * @param the other vector to subtract
     * @return *this - v components
     *
     */
    nauQuaternion&
    operator-=(const nauQuaternion& other);
    
    /**
     * @brief *= operator overload
     * @param the other vector to multiply
     * @return *this * v components
     *
     */
    nauQuaternion&
    operator*=(const nauQuaternion& other);
    
    /**
     * @brief /= operator overload
     * @param the other vector to divide
     * @return *this / v components
     *
     */
    nauQuaternion&
    operator/=(const nauQuaternion& other);
    
    /**
    * @brief ^ operator overload for cross product
    * @param the other vector
    * @return cross product
    *
    */
    FORCEINLINE float
    operator^(const nauQuaternion& v) const;
    
    /**
     * @brief | operator overload for dot product
     * @param the other vector
     * @return dot product
     *
     */
    FORCEINLINE float
    operator|(const nauQuaternion& v) const;
    
    /**
     * @brief Rotation in X axis
     * @param theta angle to rotate
     * @return
     *
     */
    void
    RotateX(const float& theta);
    
    /**
     * @brief Rotation in Y axis
     * @param theta angle to rotate
     * @return
     *
     */
    void
    RotateY(const float& theta);
    
    /**
     * @brief Rotation in Z axis
     * @param theta angle to rotate
     * @return 
     * 
     */
    void
    RotateZ(const float& theta);
   
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

    /**
     * z component of the vector
     */
    float z;

    /**
     * w component of the vector
     */
    float w;
  };

}