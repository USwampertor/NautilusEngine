/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauMatrix4.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the nauMatrix4 member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "nauMatrix4.h"

namespace nauEngineSDK {
  const nauMatrix4 nauMatrix4::ZERO = nauMatrix4(FORCE_INIT::ZERO);
  const nauMatrix4 nauMatrix4::IDENTITY = nauMatrix4(FORCE_INIT::ONE);

  nauMatrix4::nauMatrix4(const nauMatrix4& other) {
    _m = other._m;
  }
  
  nauMatrix4::nauMatrix4(int32 value) {
    memset(this, 0, sizeof(nauMatrix4));

    if (FORCE_INIT::ZERO != value) {
      _m.m00 = _m.m11 = _m.m22 = _m.m33 = 1.0f;
    }
  }

  void
  nauMatrix4::identity() {
    *this = IDENTITY;
  }

  void
  nauMatrix4::zero() {
    *this = ZERO;
  }

  void
  nauMatrix4::transposed() {
    nauMatrix4 temp = *this;
    for (int i = 0; i< 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        m[i][j] = temp.m[j][i];
      }
    }
  }

  void
  nauMatrix4::setValues(float value) {
    memset(&_m,static_cast<int>(value),sizeof(_m));
  }

  nauMatrix4
  nauMatrix4::operator+(const nauMatrix4& b){
    nauMatrix4 temp;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        temp.m[i][j] = m[i][j] + b.m[i][j];
      }
    }
    return temp;
  }

  nauMatrix4
  nauMatrix4::operator-(const nauMatrix4& b) {
    nauMatrix4 temp;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        temp.m[i][j] = m[i][j] - b.m[i][j];
      }
    }
    return temp;
  }

  nauMatrix4
  nauMatrix4::operator*(const nauMatrix4& b) {
    nauMatrix4 temp = ZERO;
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        for (uint32 k = 0; k < 4; ++k) {
          temp.m[i][j] += m[i][k] * b.m[k][j];
        }
      }
    }
    return temp;
  }

  nauMatrix4&
  nauMatrix4::operator+=(const nauMatrix4& b) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] += b.m[i][j];
      }
    }
    return *this;
  }

  nauMatrix4&
  nauMatrix4::operator-=(const nauMatrix4& b) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] -= b.m[i][j];
      }
    }
    return *this;
  }

  nauMatrix4&
  nauMatrix4::operator+=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] += value;
      }
    }
    return *this;
  }

  nauMatrix4&
  nauMatrix4::operator-=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] -= value;
      }
    }
    return *this;
  }

  nauMatrix4&
  nauMatrix4::operator*=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] *= value;
      }
    }
    return *this;
  }

  nauMatrix4&
  nauMatrix4::operator/=(const float& value) {
    for (uint32 i = 0; i < 4; ++i) {
      for (uint32 j = 0; j < 4; ++j) {
        m[i][j] /= value;
      }
    }
    return *this;
  }

  nauMatrix4&
  nauMatrix4::operator*=(const nauMatrix4& b) {
    nauMatrix4 temp = ZERO;
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

  nauMatrix4
  nauMatrix4::operator==(const nauMatrix4& b) {
   for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      if (m[i][j] != b.m[i][j]) {return false; }
    }
   }
   return true;
  }

}
