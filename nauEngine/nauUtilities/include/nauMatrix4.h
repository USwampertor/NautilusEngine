/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauMatrix4.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/26 2018
 * @brief a 4x4 Matrix for transformations and other stuff
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector2.h"
#include "nauVector3.h"
#include "nauVector4.h"

namespace nauEngineSDK{
  /**
   * Enum for static specific matrices
   */
  namespace FORCE_INIT {
    enum E {
      ZERO,
      ONE
    };
  }
  /**
  * Description:
  *   A 4x4 Matrix Object
  * Sample usage:
  * 	Transformation Matrices can be used with this
  */
  class nauMatrix4
  {
   public:

    /**
     * Default constructor
     */
    nauMatrix4() {}

    /**
     * @brief Constructor with value parameter
     * @param value will be copied into all the matrix
     * @return 
     * 
     */
    nauMatrix4(int32 value);

    /**
     * @brief Constructor that copies the info of another matrix
     * @param the other matrix to copy info from
     * @return 
     * 
     */
    nauMatrix4(const nauMatrix4& other);

    /**
     * @brief transforms the matrix into the IDENTITY matrix
     * @param 
     * @return 
     * 
     */
    void
    identity();

    /**
     * @brief transforms the matrix into the ZERO matrix
     * @param 
     * @return 
     * 
     */
    void
    zero();
    
    /**
     * @brief transposes the matrix
     * @param 
     * @return 
     * 
     */
    void
    transposed();

    /**
     * @brief Sets the value of all the matrix to the parameter 
     * @param the value which will be copied to all the matrix
     * @return 
     * 
     */
    void
    setValues(float value);

    /**
     * @brief + operator overload
     * @param b the other matrix to add
     * @return the sum of *this and b
     * 
     */
    FORCEINLINE nauMatrix4
    operator+(const nauMatrix4& b);
    
    /**
     * @brief - operator overload
     * @param b the other matrix to substract
     * @return the difference of *this and b
     *
     */
    FORCEINLINE nauMatrix4
    operator-(const nauMatrix4& b);
    
    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return the multiplication of *this and b
     *
     */
    FORCEINLINE nauMatrix4
    operator*(const nauMatrix4& b);
    
    /**
     * @brief += operator overload
     * @param b the other matrix to add
     * @return *this summed b
     *
     */
    nauMatrix4&
    operator+=(const nauMatrix4& b);
    
    /**
     * @brief -= operator overload
     * @param b the other matrix to substract
     * @return *this minus b
     *
     */
    nauMatrix4&
    operator-=(const nauMatrix4& b);
    
    /**
     * @brief *= operator overload
     * @param b the other matrix to multiply
     * @return *this summed b
     *
     */
    nauMatrix4&
    operator*=(const nauMatrix4& b);

    /**
     * @brief += operator overload
     * @param value to add to the matrix
     * @return naumatrix equal to *this summed value
     *
     */
    nauMatrix4&
    operator+=(const float& value);

    /**
     * @brief -= operator overload
     * @param value to substract to the matrix
     * @return naumatrix equal to *this minus value
     *
     */
    nauMatrix4&
    operator-=(const float& value);

    /**
     * @brief *= operator overload
     * @param value to multiply the matrix
     * @return naumatrix equal to *this times value
     *
     */
    nauMatrix4&
    operator*=(const float& value);

    /**
     * @brief /= operator overload
     * @param value to divide to the matrix
     * @return naumatrix equal to *this folded value
     *
     */
    nauMatrix4&
    operator/=(const float& value);
    
    /**
     * @brief == operator overload
     * @param nauMatrix to compare
     * @return true if *this is equal to b
     *
     */
    nauMatrix4
    operator==(const nauMatrix4& b);
   

    /**
     * Member declaration
     */
   public:

    /**
     * Matrix component
     */
    union {
       /**
        * Matrix struct made by 4x4 array row major
        */
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

    /**
     * ZERO filled Matrix
     */
    static const nauMatrix4 ZERO;

    /**
     * IDENTITY matrix
     */
    static const nauMatrix4 IDENTITY;

  };
}


