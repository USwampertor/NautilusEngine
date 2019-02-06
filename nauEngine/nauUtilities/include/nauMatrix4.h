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
#include "nauMatrix3.h"

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
  class Matrix4
  {
   public:

    /**
     * Default constructor
     */
    Matrix4() {}

    /**
     * @brief Constructor with value parameter
     * @param value will be copied into all the matrix
     * @return 
     * 
     */
    Matrix4(int32 value);

    /**
     * @brief Constructor that copies the info of another matrix
     * @param the other matrix to copy info from
     * @return 
     * 
     */
    Matrix4(const Matrix4& other);

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
     * @brief Translates matrix with floats
     * @param x offset, y offset, z offset
     * @return 
     *
     */
    void
    translate(const float& x, const float& y, const float& z);

    /**
     * @brief Translates matrix with floats
     * @param x offset, y offset, z offset
     * @return
     *
     */
    void
    translate(const Vector3& other);


    /**
     * @brief Scales the object
     * @param x scale y scale z scale
     * @return 
     *
     */
    void
    scale(const float& x, const float &y, const float &z);

    /**
     * @brief rotates the object over X by rads
     * @param rads to rotate
     * @return 
     *
     */
    void
    rotateX(const float& rads);

    /**
     * @brief rotates the object over Y by rads
     * @param rads to rotate
     * @return 
     *
     */
    void
    rotateY(const float& rads);

    /**
     * @brief rotates the object over z by rads
     * @param rads to rotate
     * @return 
     *
     */
    void
    rotateZ(const float& rads);

    /**
     * @brief rotates over an axis over rads
     * @param 
     * @return 
     *
     */
    void
    rotateAxis(const Vector3& axis, const float& rads);

    /**
     * @brief for view matrix 
     * @param position of camera, objective to look, up axis
     * @return 
     *
     */
    void
    viewLookAt(const Vector3& camPos, const Vector3& lookAt, const Vector3& upAxis);

    /**
     * @brief creates an ortographic view
     * @param width of camera, height of camera, distance between near and far
     * @return 
     *
     */
    void
    ortographic(const float& width, const float& height, const float& depth);

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
    FORCEINLINE Matrix4
    operator+(const Matrix4& b);
    
    /**
     * @brief - operator overload
     * @param b the other matrix to subtract
     * @return the difference of *this and b
     *
     */
    FORCEINLINE Matrix4
    operator-(const Matrix4& b);
    
    /**
     * @brief * operator overload
     * @param b the other matrix to multiply
     * @return the multiplication of *this and b
     *
     */
    FORCEINLINE Matrix4
    operator*(const Matrix4& b);
    
    /**
     * @brief += operator overload
     * @param b the other matrix to add
     * @return *this summed b
     *
     */
    Matrix4&
    operator+=(const Matrix4& b);
    
    /**
     * @brief -= operator overload
     * @param b the other matrix to subtract
     * @return *this minus b
     *
     */
    Matrix4&
    operator-=(const Matrix4& b);
    
    /**
     * @brief *= operator overload
     * @param b the other matrix to multiply
     * @return *this summed b
     *
     */
    Matrix4&
    operator*=(const Matrix4& b);

    /**
     * @brief += operator overload
     * @param value to add to the matrix
     * @return naumatrix equal to *this summed value
     *
     */
    Matrix4&
    operator+=(const float& value);

    /**
     * @brief -= operator overload
     * @param value to substract to the matrix
     * @return naumatrix equal to *this minus value
     *
     */
    Matrix4&
    operator-=(const float& value);

    /**
     * @brief *= operator overload
     * @param value to multiply the matrix
     * @return naumatrix equal to *this times value
     *
     */
    Matrix4&
    operator*=(const float& value);

    /**
     * @brief /= operator overload
     * @param value to divide to the matrix
     * @return naumatrix equal to *this folded value
     *
     */
    Matrix4&
    operator/=(const float& value);
    
    /**
     * @brief == operator overload
     * @param nauMatrix to compare
     * @return true if *this is equal to b
     *
     */
    Matrix4
    operator==(const Matrix4& b);
   

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
         float m00, m10, m20, m30;
         float m01, m11, m21, m31;
         float m02, m12, m22, m32;
         float m03, m13, m23, m33;
       }_m;
       float m[4][4];
       Vector4 vec[4];
       float fVec[16];
    };

    /**
     * ZERO filled Matrix
     */
    static const Matrix4 ZERO;

    /**
     * IDENTITY matrix
     */
    static const Matrix4 IDENTITY;

  };
}


