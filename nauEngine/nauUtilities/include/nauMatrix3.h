/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMatrix3.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/06 2019
 * @brief Matrix3 object class
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector2.h"
#include "nauVector3.h"

namespace nauEngineSDK {

  /**
   * Enum for static specific matrices
   */
  
    enum MAT3 {
      ZERO,
      ONE
    };
  
   /**
    * Matrix3
    * Description:
    * 	A matrix 3by 3 for easier operations
    * Sample usage:
    * 	
    */
  class NAU_UTILITY_EXPORT Matrix3
  {
  public:

    /**
     * Default Constructor
     */
    Matrix3() = default;

    /**
     * Default Destructor
     */
    ~Matrix3() {}

    /**
     * @brief Constructor with value parameter
     * @param value will be copied into all the matrix
     * @return
     *
     */
    Matrix3(int32 value);

    /**
     * @brief Constructor that copies the info of another matrix
     * @param the other matrix to copy info from
     * @return
     *
     */
    Matrix3(const Matrix3& other);

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
     * @brief Sets the values inside the matrix
     * @param This goes column mayor like this:
     *        | v00 | v10 | v20 |
     *        | v01 | v11 | v21 |
     *        | v02 | v12 | v22 |
     * @return 
     *
     */
    void
    setValues(float v00, float v10, float v20, 
              float v01, float v11, float v21, 
              float v02, float v12, float v22);

    /**
     * @brief gets the inverse of the matrix (if possible)
     * @param
     * @return
     *
     */
    void
    inverse();

    /**
     * @brief gets the determinant of the matrix
     * @param
     * @return the determinant
     *
     */
    float
    determinant();

    /**
     * @brief + operator overload
     * @param b the other matrix to add
     * @return the sum of *this and b
     *
     */
    FORCEINLINE Matrix3
    operator+(const Matrix3& b);

    /**
     * @brief - operator overload
     * @param b the other matrix to subtract
     * @return the difference of *this and b
     *
     */
    FORCEINLINE Matrix3
    operator-(const Matrix3& b);

    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return the multiplication of *this and b
     *
     */
    FORCEINLINE Matrix3
    operator*(const Matrix3& b);

    /**
     * @brief += operator overload
     * @param b the other matrix to add
     * @return *this summed b
     *
     */
    Matrix3&
    operator+=(const Matrix3& b);

    /**
     * @brief -= operator overload
     * @param b the other matrix to subtract
     * @return *this minus b
     *
     */
    Matrix3&
    operator-=(const Matrix3& b);

    /**
     * @brief *= operator overload
     * @param b the other matrix to multiply
     * @return *this summed b
     *
     */
    Matrix3&
    operator*=(const Matrix3& b);

    /**
     * @brief += operator overload
     * @param value to add to the matrix
     * @return naumatrix equal to *this summed value
     *
     */
    Matrix3&
    operator+=(const float& value);

    /**
     * @brief -= operator overload
     * @param value to substract to the matrix
     * @return naumatrix equal to *this minus value
     *
     */
    Matrix3&
    operator-=(const float& value);

    /**
     * @brief *= operator overload
     * @param value to multiply the matrix
     * @return naumatrix equal to *this times value
     *
     */
    Matrix3&
    operator*=(const float& value);

    /**
     * @brief /= operator overload
     * @param value to divide to the matrix
     * @return naumatrix equal to *this folded value
     *
     */
    Matrix3&
    operator/=(const float& value);

    /**
     * @brief == operator overload
     * @param nauMatrix to compare
     * @return true if *this is equal to b
     *
     */
    Matrix3
    operator==(const Matrix3& b);

    String
    toString();

    /**
     * Member declaration
     */
  public:

    /**
     * Matrix component
     */
    union {
      /**
       * Matrix struct made by 4x4 array column major
       */
      struct {
        float m00, m10, m20;
        float m01, m11, m21;
        float m02, m12, m22;
      }_m;
      float m[3][3];
      Vector3 vec[3];
      float fVec[9];
    };

    /**
     * ZERO filled Matrix
     */
    static const Matrix3 ZERO;

    /**
     * IDENTITY matrix
     */
    static const Matrix3 IDENTITY;

  };

}

