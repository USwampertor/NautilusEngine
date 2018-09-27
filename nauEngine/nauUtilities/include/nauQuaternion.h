/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauQuaternion.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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
   
    
    FORCEINLINE nauQuaternion
    operator+(const nauQuaternion& other) const;
    
    FORCEINLINE nauQuaternion
    operator-(const nauQuaternion& other) const;
    
    FORCEINLINE nauQuaternion
    operator*(const nauQuaternion& other) const;
    
    FORCEINLINE nauQuaternion
    operator/(const nauQuaternion& other) const;
    
    FORCEINLINE bool
    operator==(const nauQuaternion& other);

    FORCEINLINE bool
    operator<(const nauQuaternion& other);

    FORCEINLINE bool
    operator>(const nauQuaternion& other);

    FORCEINLINE bool
    operator<=(const nauQuaternion& other);

    FORCEINLINE bool
    operator>=(const nauQuaternion& other);
    
    FORCEINLINE nauQuaternion
    operator+=(const nauQuaternion& other);
    
    FORCEINLINE nauQuaternion
    operator-=(const nauQuaternion& other);
    
    FORCEINLINE nauQuaternion
    operator*=(const nauQuaternion& other);
    
    FORCEINLINE nauQuaternion
    operator/=(const nauQuaternion& other);
    
    FORCEINLINE float
    operator^(const nauQuaternion& v) const;
    
    FORCEINLINE float
    operator|(const nauQuaternion& v) const;
    
    void
    RotateX(const float& theta);
    
    void
    RotateY(const float& theta);
    
    void
    RotateZ(const float& theta);
   
   public:

    float x;

    float y;

    float z;

    float w;
  };

}