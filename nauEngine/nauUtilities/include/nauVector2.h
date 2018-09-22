/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief Vector2 object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauMath.h"


namespace nauEngineSDK {

  class Vector2 {
   public:
    Vector2() = default;
    Vector2 () : x(0), y(0) {}
    
    /**
     * Method declaration
     */
    
    Vector2 operator+(const Vector2& v) const;

    Vector2 operator-(const Vector2& v) const;

    Vector2 operator*(const Vector2& v) const;

    Vector2 operator/(const Vector2& v) const;

    Vector2 operator+(const Vector2& v) const;

    Vector2 operator+(float plus) const;

    Vector2 operator-(float minus) const;

    Vector2 operator*(float times) const;

    Vector2 operator/(float under) const;

    float operator|(const Vector2 v) const;

    Vector2 operator^(const Vector2 v) const;

    bool operator==(const Vector2& v) const;

    bool operator!=(const Vector2& v) const;

    bool operator<(const Vector2& v) const;

    bool operator>(const Vector2& v) const;

    bool operator<=(const Vector2& v) const;

    bool operator>=(const Vector2& v) const;

    Vector2 operator-() const;

    Vector2 operator+=(const Vector2& v);

    Vector2 operator-=(const Vector2& v);

    Vector2 operator*=(const Vector2& v);

    Vector2 operator/=(const Vector2& v);
    
    Vector2 operator*=(float scale);

    Vector2 operator/=(float scale);

    static float dot(const Vector2& a, const Vector2& b);

    float magnitude() const;

    /**
     * Method Implementation
     */




    /**
     * Member declaration
     */

    float x;
    float y;

  };
}