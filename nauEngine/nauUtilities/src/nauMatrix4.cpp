/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMatrix4.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauMatrix4 member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauMatrix4.h"

namespace nauEngineSDK {

  const Matrix4 Matrix4::ZERO = Matrix4(FORCE_INIT::ZERO);
  
  const Matrix4 Matrix4::IDENTITY = Matrix4(FORCE_INIT::ONE);

  Matrix4::Matrix4(const Matrix4& other) {
    _m = other._m;
  }
  
  Matrix4::Matrix4(int32 value) {
    memset(this, 0, sizeof(Matrix4));

    if (FORCE_INIT::ZERO != value) {
      _m.m00 = _m.m11 = _m.m22 = _m.m33 = 1.0f;
    }
  }

  void
  Matrix4::identity() {
    *this = IDENTITY;
  }

  void
  Matrix4::zero() {
    *this = ZERO;
  }

  void
  Matrix4::transposed() {
    Matrix4 temp = *this;
    for (int i = 0; i< 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        m[i][j] = temp.m[j][i];
      }
    }
  }

  void
  Matrix4::setValues(float value) {
    memset(&_m,static_cast<int>(value),sizeof(_m));
  }

  void
  Matrix4::translate(const float& x, const float& y, const float& z) {

  }

  void
  Matrix4::translate(const Vector3& other) {

  }

  void
  Matrix4::scale(const float& x, const float &y, const float &z) {

  }

  void
  Matrix4::rotateX(const float& rads) {

  }

  void
  Matrix4::rotateY(const float& rads) {

  }

  void
  Matrix4::rotateZ(const float& rads) {

  }

  void
  Matrix4::rotateAxis(const Vector3& axis, const float& rads) {

  }

  void
  Matrix4::viewLookAt(const Vector3& camPos, 
                      const Vector3& lookAt, 
                      const Vector3& upAxis) {

  }

  void
  Matrix4::ortographic(const float& width, 
                       const float& height, 
                       const float& depth) {
    m[0][0] = 2 / width;
    m[1][1] = 2 / height;
    m[2][2] = depth / -2;

  }

  void
  Matrix4::inverse() {

  }

  float
  Matrix4::determinant() {

  }

  Matrix4
  Matrix4::operator+(const Matrix4& b){
    Matrix4 temp;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        temp.m[i][j] = m[i][j] + b.m[i][j];
      }
    }
    return temp;
  }

  Matrix4
  Matrix4::operator-(const Matrix4& b) {
    Matrix4 temp;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        temp.m[i][j] = m[i][j] - b.m[i][j];
      }
    }
    return temp;
  }

  Matrix4
  Matrix4::operator*(const Matrix4& b) {
    Matrix4 temp = ZERO;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        for (uint32 k = 0; k < 4; ++k) {
          temp.m[i][j] += m[i][k] * b.m[k][j];
        }
      }
    }
    return temp;
  }

  Matrix4&
  Matrix4::operator+=(const Matrix4& b) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] += b.m[i][j];
      }
    }
    return *this;
  }

  Matrix4&
  Matrix4::operator-=(const Matrix4& b) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] -= b.m[i][j];
      }
    }
    return *this;
  }

  Matrix4&
  Matrix4::operator+=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] += value;
      }
    }
    return *this;
  }

  Matrix4&
  Matrix4::operator-=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] -= value;
      }
    }
    return *this;
  }

  Matrix4&
  Matrix4::operator*=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] *= value;
      }
    }
    return *this;
  }

  Matrix4&
  Matrix4::operator/=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] /= value;
      }
    }
    return *this;
  }

  Matrix4&
  Matrix4::operator*=(const Matrix4& b) {
    Matrix4 temp = ZERO;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        for (uint32 k = 0; k < 4; ++k) {
          temp.m[i][j] += m[i][k] * b.m[k][j];
        }
      }
    }
    *this = temp; 
    return *this;
  }

  Matrix4
  Matrix4::operator==(const Matrix4& b) {
   for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      if (m[i][j] != b.m[i][j]) {return false; }
    }
   }
   return true;
  }

}
