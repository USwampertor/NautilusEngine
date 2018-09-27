/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMatrix4.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/26 2018
 * @brief a 4x4 Matrix for transformations and other stuff
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector2.h"
#include "nauVector3.h"
#include "nauVector4.h"

namespace nauEngineSDK{
  namespace FORCE_INIT {
    enum E {
      ZERO,
      ONE
    };
  }

  class nauMatrix4
  {
   public:
    static const nauMatrix4 ZERO;
    static const nauMatrix4 IDENTITY;

    nauMatrix4() {}
    nauMatrix4(int32 value);
    nauMatrix4(const nauMatrix4& other);

    void
    identity();

    void
    zero();
    
    void
    inverse();

    void
    setValues(int32 value);


    FORCEINLINE nauMatrix4
    operator+(const nauMatrix4& b);
    
    FORCEINLINE nauMatrix4
    operator-(const nauMatrix4& b);
    
    FORCEINLINE nauMatrix4
    operator*(const nauMatrix4& b);
    
    nauMatrix4&
    operator+=(const nauMatrix4& b);
    
    nauMatrix4&
    operator-=(const nauMatrix4& b);
    
    nauMatrix4&
    operator*=(const nauMatrix4& b);

    nauMatrix4&
    operator+=(const float& value);

    nauMatrix4&
    operator-=(const float& value);

    nauMatrix4&
    operator*=(const float& value);

    nauMatrix4&
    operator/=(const float& value);
    
    nauMatrix4
    operator==(const nauMatrix4& b);
   
   public:
    union {
       struct {
         float m00, m01, m02, m03;
         float m10, m11, m12, m13;
         float m20, m21, m22, m23;
         float m30, m31, m32, m33;
       }_m;
       float m[4][4];
       nauVector4 vec[4];
       float fVec[16];
    };
  };
}


