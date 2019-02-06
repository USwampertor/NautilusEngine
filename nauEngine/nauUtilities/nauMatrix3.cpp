/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMatrix3.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/02/06 2019
 * @brief Matrix3 implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauMatrix3.h"

namespace nauEngineSDK {

  const Matrix3 Matrix3::ZERO = Matrix3(FORCE_INIT::ZERO);

  const Matrix3 Matrix3::IDENTITY = Matrix3(FORCE_INIT::ONE);

  Matrix3::Matrix3(const Matrix3& other) {
    _m = other._m;
  }

  Matrix3::Matrix3(int32 value) {
    memset(this, 0, sizeof(Matrix3));

    if (FORCE_INIT::ZERO != value) {
      _m.m00 = _m.m11 = _m.m22 = 1.0f;
    }
  }

  void
  Matrix3::identity() {
    *this = IDENTITY;
  }

  void
  Matrix3::zero() {
    *this = ZERO;
  }

  void
  Matrix3::transposed() {
    Matrix3 temp = *this;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        m[i][j] = temp.m[j][i];
      }
    }
  }

  void
  Matrix3::setValues(float value) {
    memset(&_m, static_cast<int>(value), sizeof(_m));
  }

  void
  Matrix3::inverse() {
    float det = determinant();
    if (det == 0.0f) {
      std::cout << "This matrix can't have an inverse \n";
      return;
    }
    Matrix3 temp = *this;
    m[0][0] =  ((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[1][0] = -((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[2][0] =  ((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[0][1] = -((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[1][1] =  ((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[2][1] = -((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[0][2] =  ((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[1][2] = -((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));
    m[2][2] =  ((temp.m[1][1] * temp.m[2][2]) - (temp.m[1][2] * temp.m[2][1]));

    *this /= det;
  }

  float
  Matrix3::determinant() {

  }

  FORCEINLINE Matrix3
  Matrix3::operator+(const Matrix3& b){
  }

  FORCEINLINE Matrix3
  Matrix3::operator-(const Matrix3& b){
  }

  FORCEINLINE Matrix3
  Matrix3::operator*(const Matrix3& b){
  }

  Matrix3&
  Matrix3::operator+=(const Matrix3& b){
  }

  Matrix3&
  Matrix3::operator-=(const Matrix3& b){
  }

  Matrix3&
  Matrix3::operator*=(const Matrix3& b){
  }

  Matrix3&
  Matrix3::operator+=(const float& value){
  }

  Matrix3&
  Matrix3::operator-=(const float& value){
  }

  Matrix3&
  Matrix3::operator*=(const float& value){
  }

  Matrix3&
  Matrix3::operator/=(const float& value){
  }

  Matrix3
  Matrix3::operator==(const Matrix3& b){
  }

}