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
    m[3][0] += x;
    m[3][1] += y;
    m[3][2] += z;
  }

  void
  Matrix4::translate(const Vector3& position) {
    m[3][0] += position.x;
    m[3][1] += position.y;
    m[3][2] += position.z;
  }

  void
  Matrix4::scale(const float& x, const float &y, const float &z) {
    m[0][0] = x;
    m[1][1] = y;
    m[2][2] = z;
  }

  void
  Matrix4::rotateX(const float& rads) {
    float cos = nauMath::cos(rads);
    float sin = nauMath::sin(rads);
    Matrix4 tmp = *this;

    m[0][1] = (cos * m[0][1]) - (sin * m[0][2]);
    m[1][1] = (cos * m[1][1]) - (sin * m[1][2]);
    m[2][1] = (cos * m[2][1]) - (sin * m[2][2]);
    m[0][2] = (cos * m[0][2]) + (sin * m[0][1]);
    m[1][2] = (cos * m[1][2]) + (sin * m[1][1]);
    m[2][2] = (cos * m[2][2]) + (sin * m[2][1]);
  }

  void
  Matrix4::rotateY(const float& rads) {
    float cos = nauMath::cos(rads);
    float sin = nauMath::sin(rads);
    Matrix4 tmp = *this;

    m[0][0] = (cos * m[0][0]) + (sin * m[0][2]);
    m[1][0] = (cos * m[1][0]) + (sin * m[1][2]);
    m[2][0] = (cos * m[2][0]) + (sin * m[2][2]);
    m[0][2] = (cos * m[0][2]) - (sin * m[0][0]);
    m[1][2] = (cos * m[1][2]) - (sin * m[1][0]);
    m[2][2] = (cos * m[2][2]) - (sin * m[2][0]);
  }

  void
  Matrix4::rotateZ(const float& rads) {
    float cos = nauMath::cos(rads);
    float sin = nauMath::sin(rads);
    Matrix4 tmp = *this;

    m[0][0] = (cos * m[0][0]) - (sin * m[0][1]);
    m[1][0] = (cos * m[1][0]) - (sin * m[1][1]);
    m[2][0] = (cos * m[2][0]) - (sin * m[2][1]);
    m[0][1] = (cos * m[0][1]) + (sin * m[0][0]);
    m[1][1] = (cos * m[1][1]) + (sin * m[1][0]);
    m[2][1] = (cos * m[2][1]) + (sin * m[2][0]);
  }

  void
  Matrix4::rotateAxis(const Vector3& axis, const float& rads) {
    float cos = nauMath::cos(rads);
    float sin = nauMath::sin(rads);
    float min = (1 - nauMath::cos(rads));
    Matrix4 tmp = *this;
    axis.normalize();

    m[0][0] = cos + axis.x*axis.x*min;
    m[1][0] = axis.x*axis.y*min - axis.z;
    m[2][0] = axis.x*axis.z*min + axis.y*sin;
    m[0][1] = axis.y*axis.x * min + axis.z * sin;
    m[1][1] = cos + axis.y*axis.y;
    m[2][1] = axis.y*axis.z*min - axis.x*sin;
    m[0][2] = axis.z*axis.x*min - axis.y*sin;
    m[1][2] = axis.z*axis.y*min + axis.x*sin;
    m[2][2] = cos + axis.z*axis.z*min;

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
    float det = determinant();
    if (det == 0.0f) {
      std::cout << "This matrix can't have an inverse \n";
      return;
    }
    Matrix4 temp;

    temp.m[0][0] = m[1][1]; temp.m[1][0] = m[2][1]; temp.m[2][0] = m[3][1];
    temp.m[0][1] = m[1][2]; temp.m[1][1] = m[2][2]; temp.m[2][1] = m[3][2];
    temp.m[0][2] = m[1][3]; temp.m[1][2] = m[2][3]; temp.m[2][2] = m[3][3];
    m[0][0] = temp.determinant();

    temp.m[0][0] = m[1][0]; temp.m[1][0] = m[2][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[1][2]; temp.m[1][1] = m[2][2]; temp.m[2][1] = m[3][2];
    temp.m[0][2] = m[1][3]; temp.m[1][2] = m[2][3]; temp.m[2][2] = m[3][3];
    m[1][0] = - temp.determinant();

    temp.m[0][0] = m[1][0]; temp.m[1][0] = m[2][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[1][1]; temp.m[1][1] = m[2][1]; temp.m[2][1] = m[3][1];
    temp.m[0][2] = m[1][3]; temp.m[1][2] = m[2][3]; temp.m[2][2] = m[3][3];
    m[2][0] = temp.determinant();

    temp.m[0][0] = m[1][0]; temp.m[1][0] = m[2][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[1][1]; temp.m[1][1] = m[2][1]; temp.m[2][1] = m[3][1];
    temp.m[0][2] = m[1][2]; temp.m[1][2] = m[2][2]; temp.m[2][2] = m[3][2];
    m[3][0] = - temp.determinant();

    temp.m[0][0] = m[0][1]; temp.m[1][0] = m[2][1]; temp.m[2][0] = m[3][1];
    temp.m[0][1] = m[0][2]; temp.m[1][1] = m[2][2]; temp.m[2][1] = m[3][2];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[2][3]; temp.m[2][2] = m[3][3];
    m[0][1] = temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[2][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[0][2]; temp.m[1][1] = m[2][2]; temp.m[2][1] = m[3][2];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[2][3]; temp.m[2][2] = m[3][3];
    m[1][1] = - temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[2][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[0][1]; temp.m[1][1] = m[2][1]; temp.m[2][1] = m[3][1];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[2][3]; temp.m[2][2] = m[3][3];
    m[2][1] = temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[2][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[0][1]; temp.m[1][1] = m[2][1]; temp.m[2][1] = m[3][1];
    temp.m[0][2] = m[0][2]; temp.m[1][2] = m[2][2]; temp.m[2][2] = m[3][2];
    m[3][1] = - temp.determinant();

    temp.m[0][0] = m[0][1]; temp.m[1][0] = m[1][1]; temp.m[2][0] = m[3][1];
    temp.m[0][1] = m[0][2]; temp.m[1][1] = m[1][2]; temp.m[2][1] = m[3][2];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[1][3]; temp.m[2][2] = m[3][3];
    m[0][2] = temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[1][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[0][2]; temp.m[1][1] = m[1][2]; temp.m[2][1] = m[3][2];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[1][3]; temp.m[2][2] = m[3][3];
    m[1][2] = - temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[1][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[0][1]; temp.m[1][1] = m[1][1]; temp.m[2][1] = m[3][1];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[1][3]; temp.m[2][2] = m[3][3];
    m[2][2] = temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[1][0]; temp.m[2][0] = m[3][0];
    temp.m[0][1] = m[0][1]; temp.m[1][1] = m[1][1]; temp.m[2][1] = m[3][1];
    temp.m[0][2] = m[0][2]; temp.m[1][2] = m[1][2]; temp.m[2][2] = m[3][2];
    m[3][2] = - temp.determinant();

    temp.m[0][0] = m[0][1]; temp.m[1][0] = m[1][1]; temp.m[2][0] = m[2][1];
    temp.m[0][1] = m[0][2]; temp.m[1][1] = m[1][2]; temp.m[2][1] = m[2][2];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[1][3]; temp.m[2][2] = m[2][3];
    m[0][3] = temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[1][0]; temp.m[2][0] = m[2][0];
    temp.m[0][1] = m[0][2]; temp.m[1][1] = m[1][2]; temp.m[2][1] = m[2][2];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[1][3]; temp.m[2][2] = m[2][3];
    m[1][3] = - temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[1][0]; temp.m[2][0] = m[2][0];
    temp.m[0][1] = m[0][1]; temp.m[1][1] = m[1][1]; temp.m[2][1] = m[2][1];
    temp.m[0][2] = m[0][3]; temp.m[1][2] = m[1][3]; temp.m[2][2] = m[2][3];
    m[2][3] = temp.determinant();

    temp.m[0][0] = m[0][0]; temp.m[1][0] = m[1][0]; temp.m[2][0] = m[2][0];
    temp.m[0][1] = m[0][1]; temp.m[1][1] = m[1][1]; temp.m[2][1] = m[2][1];
    temp.m[0][2] = m[0][2]; temp.m[1][2] = m[1][2]; temp.m[2][2] = m[2][2];
    m[3][3] = - temp.determinant();

    *this /= det;
  }

  float
  Matrix4::determinant() {
    return (((m[0][0] * m[1][1] * m[2][2] * m[3][3]) +
             (m[1][0] * m[2][1] * m[3][2] * m[0][3]) +
             (m[2][0] * m[3][1] * m[0][2] * m[1][3])) -
             (m[3][0] * m[0][1] * m[1][2] * m[2][3]) +

            ((m[0][3] * m[1][2] * m[2][1] * m[3][0]) +
             (m[1][3] * m[2][2] * m[3][1] * m[0][0]) +
             (m[2][3] * m[3][2] * m[0][1] * m[1][0]) +
             (m[3][3] * m[0][2] * m[1][1] * m[2][0])));
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
