/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauPlatformMath.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief General math library
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPlatformTypes.h"
#include <cmath>
#include <algorithm>
//#include "nauSphere.h"
//#include "nauBox2d.h"

namespace nauEngineSDK {
  
  class nauBox2d;
  class nauSphere;

  struct NAU_UTILITY_EXPORT nauPlatformMath {
    /**
     * Transformation functions
     */
    
    /**
     * @brief Changes from degrees to rads
     * @param T the degree to translate
     * @return the degree in rads
     * 
     */
    template<typename T>
    static T degToRad(T degree) {
      return (degree * RADIAN);
    }

    /**
     * @brief Changes from rads to degrees
     * @param T the rad to translate
     * @return the rads in degrees
     *
     */
    template<typename T>
    static T radToDeg(T rad) {
      return (rad * DEGREE);
    }

    /**
     * Trigonometric functions
     */

    /**
     * @brief sin function
     * @param radian to get sin
     * @return the sin of the radian
     * 
     */
    template<typename T>
    static T sin(T rad) {
        return static_cast<T>(std::sin(rad));
    }

    /**
     * @brief cos function
     * @param radian to get cos
     * @return the cos of the radian
     *
     */
    template<typename T>
    static T cos(T rad) {
        return static_cast<T>(std::cos(rad));
    }

    /**
     * @brief tan function
     * @param radian to get tan
     * @return the tan of the radian
     *
     */
    template<typename T>
    static T tan(T rad) {
        return std::tan(rad);
    }

    /**
     * @brief asin function
     * @param radian to get asin
     * @return the asin of the radian
     *
     */
    template<typename T>
    static T asin(T rad) {
        return std::asin(rad);
    }

    /**
     * @brief acos function
     * @param radian to get acos
     * @return the acos of the radian
     *
     */
    template<typename T>
    static T acos(T rad) {
        return std::acos(rad);
    }

    /**
     * @brief atan function
     * @param radian to get atan
     * @return the atan of the radian
     *
     */
    template<typename T>
    static T atan(T rad) {
        return std::atan(rad);
    }

    /**
     * @brief atan function
     * @param radian to get atan
     * @return the atan of the radian
     *
     */
    template<typename T>
    static T atan2(T t1, T t2) {
        return std::atan2(t1, t2);
    }

    /**
     * @brief sinh function
     * @param radian to get sinh
     * @return the sinh of the radian
     *
     */
    template<typename T>
    static T sinh(T rad) {
        return std::sinh(rad);
    }

    /**
     * @brief cosh function
     * @param radian to get cosh
     * @return the cosh of the radian
     *
     */
    template<typename T>
    static T cosh(T rad) {
        return std::cosh(rad);
    }

    /**
     * @brief tanh function
     * @param radian to get tanh
     * @return the tanh of the radian
     *
     */
    template<typename T>
    static T tanh(T rad) {
        return std::tanh(rad);
    }

    /**
     * @brief asin function
     * @param radian to get asin
     * @return the asin of the radian
     *
     */
    template<typename T>
    static T asinh(T rad) {
        return std::asinh(rad);
    }

    /**
     * @brief acosh function
     * @param radian to get acosh
     * @return the acosh of the radian
     *
     */
    template<typename T>
    static T acosh(T rad) {
        return std::acosh(rad);
    }

    /**
     * @brief atanh function
     * @param radian to get atanh
     * @return the atanh of the radian
     *
     */
    template<typename T>
    static T atanh(T rad) {
        return std::atanh(rad);
    }


    /**
     * Basic math library
     */

    /**
     * @brief computes e to the value given
     * @param power of e
     * @return e^power
     *
     */
    template<typename T>
    static T exp(T power) {
        return std::exp(power)
    }
    
    /**
     * @brief computes value to the power given
     * @param value and power of the evaluation
     * @return value^power
     *
     */
    template<typename T>
    static T pow(T value, T power) {
      return static_cast<T>(std::pow(value, power));
    }

    /**
     * @brief computes T value to the power given
     * @param T value and float power of the evaluation
     * @return value^power
     *
     */
    template<typename T>
    static T powf(T value, float power) {
      return static_cast<float>(std::pow(value, power));
    }

    /**
     * @brief computes absolute of value
     * @param value to get absolute
     * @return value with no signs
     *
     */
    template<typename T>
    static T abs(T value) {
      return std::abs(value);
    }

    /**
     * @brief computes square of given value
     * @param value to get square of
     * @return value^2
     *
     */
    template<typename T>
    static T sqr(T value) {
      return value*value;
    }
    
    /**
     * @brief computes cubic of given value
     * @param value to get cubic of
     * @return value^3
     *
     */
    template<typename T>
    static T cbc(T value) {
      return value*value*value;
    }

    /**
     * @brief computes square root of given value
     * @param value to get square root of
     * @return value^(1/2)
     *
     */
    template <typename T>
    static T sqrt(T value) {
      return static_cast<T>(std::sqrt(value));
    }

    /**
     * @brief computes inverse square root of given value
     * @param value to get inverse square root of
     * @return 1/(value^(1/2))
     *
     */
    template<typename T>
    static T invSqrt(T value) {
      return 1.0f/std::sqrt(value);
    }

    /**
     * @brief computes cubic root of given value
     * @param value to get cubic root of
     * @return value^(1/3)
     *
     */
    template <typename T>
    static T cbrt(T value) {
      return std::cbrt(value);
    }

    /**
     * @brief computes hypotenuse of given CA and CO
     * @param Opposite leg and adjacent leg
     * @return value^2
     *
     */
    template <typename T>
    static T hypot(T co, T ca) {
      return std::hypot(co, ca);
    }


    /**
     * @brief floors the given value to the nearest integer
     * @param value to floor
     * @return floored value
     *
     */
    template<typename T>
    static T floor(T a) {
      return std::floor(a);
    }

    /**
     * @brief ceiling given value to the nearest integer
     * @param value to ceiling
     * @return ceiling value
     *
     */
    template<typename T>
    static T ceil(T a) {
      return std::ceil(a);
    }

    /**
     * @brief rounds values to the nearest integer or half number x.0 <- -> x.5 <- -> y.0
     * @param value to round half
     * @return rounded value
     *
     */
    template<typename T>
    static T roundHalf(T a) {
      return std::round(a*2.0f) / 2.0f;
    }

    /**
     * @brief rounds values to the nearest integer x.0 <- -> y.0
     * @param value to round
     * @return rounded value
     *
     */
    template<typename T>
    static T round(T a) {
      return std::round(a);
    }

    /**
     * @brief returns the max value between two numbers
     * @param A value, B value
     * @return highest value
     *
     */
    template<typename T>
    static T max(T a, T b) {
      return std::max(a, b);
    }

    /**
     * @brief returns the min value between two numbers
     * @param A value, B value
     * @return lowest value
     *
     */
    template<typename T>
    static T min(T a, T b) {
      return std::min(a, b);
    }

    /**
     * @brief returns the max value between 3 numbers
     * @param A value, B value, C value
     * @return highest value
     *
     */
    template<typename T>
    static T max3(T a, T b, T c) {
      return max(max(a, b), c);
    }
    
    /**
     * @brief returns the min value between 3 numbers
     * @param A value, B value, C value
     * @return lowest value
     *
     */
    template<typename T>
    static T min3(T a, T b, T c) {
      return min(min(a, b), c);
    }

    /**
     * @brief returns the max value between two numbers
     * @param A value, B value
     * @return highest value
     *
     */
    template<typename T>
    static T frac(T fracpart, T* intpart) {
      return std::modf(fracpart, intpart);
    }

    /**
     * @brief clamps the value between two given values
     * @param value to clamp, top value, bottom value
     * @return highest value
     *
     */
    template<typename T>
    static T clamp(T number, T bot, T top) {
      return std::clamp(number, bot, top);
    }

    
    /**
    * Log functions
    */

    /**
     * @brief returns the power of given number ( base 10)
     * @param value to get exponent
     * @return exponent of log(10) value
     *
     */
    template <typename T>
    static T log10(T value) {
      return std::log10(value);
    }

    /**
     * @brief returns the power of given number ( base 2)
     * @param value to get exponent
     * @return exponent of log(2) value
     *
     */
    template <typename T>
    static T log2(T value) {
      return std::log2(value);
    }

    /**
     * @brief returns the power of given number ( base e)
     * @param value to get exponent
     * @return exponent of ln value
     *
     */
    template <typename T>
    static T logN(T value) {
      return std::log(value);
    }

    /**
     * @brief returns the power of given number by given base
     * @param value to get exponent, base of logarithm
     * @return exponent of log(base) value 
     *
     */
    template <typename T>
    static T logX(T base, T value) {
      return std::log(value) / std::log(base);
    }


    /**
     * @brief creates a lerp between to given values and a scale
     * @param first point a, second point b, scale of lerp
     * @return lerp value
     *
     */
    template<typename T>
    static T lerp(T a, T b, float scale) {
        return (a + (b - a)* scale);
    }

    /**
     * @brief returns the factorial of given number
     * @param top of the factorial list
     * @return the factorial of top
     *
     */
    template<typename T>
    static T factorial(T top) {
        return top == 0 ? 1 : (top * factorial(top - 1));
    }

    /**
     * @brief fast cosine of given radian
     * @param radian to get cos
     * @return cosine(rad) with Taylor
     *
     */
    template<typename T>
    static T fastcos(T rad) {
      return (1 -
              (pow(rad, 2) / 2) +
              (pow(rad, 4) / 24) -
              (pow(rad, 6) / 720) +
              (pow(rad, 8) / 40320));
    }
    
    /**
     * @brief fast sin of given radian
     * @param radian to get sin
     * @return sin(rad) with Taylor
     *
     */
    template<typename T>
    static T fastsin(T rad) {
      return (rad -
              (pow(rad, 3) / 6) +
              (pow(rad, 5) / 120) -
              (pow(rad, 7) / 5040) +
              (pow(rad, 9) / 362880));
    }
    
    /**
     * @brief fast tangent of given radian
     * @param radian to get tan
     * @return tan(rad) with Taylor
     *
     */
    template<typename T>
    static T fasttan(T rad) {
      return (rad -
              (pow(rad, 3) * 2 / 6) +
              (pow(rad, 5) * 16 / 120) -
              (pow(rad, 7) * 272 / 5040) +
              (pow(rad, 9) * 7936 / 362880));
    }
    
    /**
     * @brief fast arcocosine of given radian
     * @param radian to get acos
     * @return arcocosine(rad) with Taylor
     *
     */
    template<typename T>
    static T fastacos(T rad) {
      return static_cast<T>(0);
    }

    /**
     * @brief fast arcsine of given radian
     * @param radian to get asin
     * @return arcsine(rad) with Taylor
     *
     */
    template<typename T>
    static T fastasin(T rad) {
    
    }

    /**
     * @brief fast arctan of given radian
     * @param radian to get atan
     * @return arctan(rad) with Taylor
     *
     */
    template<typename T>
    static T fastatan(T rad) {
      return (
        rad -
        (pow(rad, 3) / 3) +
        (pow(rad, 3) / 5) -
        (pow(rad, 3) / 7) +
        (pow(rad, 3) / 9));
    }

    /**
     * @brief fast hyperbolic cosine of given radian
     * @param radian to get cosh
     * @return hyperbolic cosine(rad) with Taylor
     *
     */
    template<typename T>
    static T fastcosh(T rad) {
      return (1 +
              (pow(rad, 2) / 2) +
              (pow(rad, 4) / 24) +
              (pow(rad, 6) / 720) +
              (pow(rad, 8) / 40320));
    }

    /**
     * @brief fast hyperbolic cosine of given radian
     * @param radian to get cosh
     * @return hyperbolic cosine(rad) with Taylor
     *
     */
    template<typename T>
    static T fastsinh(T rad) {
      return (rad +
              ((rad*rad*rad) / 6) +
              ((rad*rad*rad*rad*rad) / 120) +
              ((rad*rad*rad*rad*rad*rad*rad) / 5040) +
              ((rad*rad*rad*rad*rad*rad*rad*rad*rad) / 362880));
    }

    /**
     * @brief fast hyperbolic tangent of given radian
     * @param radian to get tanh
     * @return hyperbolic tangent(rad) with Taylor
     *
     */
    template<typename T>
    static T fasttanh(T rad) {
      return rad;
    }

    /**
     * Collisions
     */

    /**
     * @brief Collision between Sphere and Box2D objects
     * @param nauSphere sphere, nauBox2D box
     * @return true if colliding
     * 
     */
    //bool
    //collisionBoxSphere(const nauSphere& sphere, const nauBox2d& box) {
    //  
    //  nauVector2 sphereD;
    //  sphereD.x = abs(sphere.m_center.x - (box.m_max.x / 2));
    //  sphereD.y = abs(sphere.m_center.y - (box.m_max.y / 2));
    //
    //  if (sphereD.x > ((box.m_max - box.m_min).x / 2 + sphere.m_radius)) { return false; }
    //  if (sphereD.y > ((box.m_max - box.m_min).y / 2 + sphere.m_radius)) { return false; }
    //
    //  if (sphereD.x <= ((box.m_max - box.m_min).x / 2)) { return true; }
    //  if (sphereD.y <= ((box.m_max - box.m_min).y / 2)) { return true; }
    //
    //  float cornerDistance = sqr(sphereD.x - (box.m_max - box.m_min).x / 2) +
    //    sqr(sphereD.y - (box.m_max - box.m_min).y / 2);
    //
    //  return cornerDistance <= sqr(sphere.m_radius);
    //}

    /**
     * Constants
     */

    /**
     * Constant PI 3.141592~
     */
    static const float PI;


    /**
     * Constant EULER 2.71828182
     */
    static const float EULER;

    /**
     * Equivalent degrees of 1 rad
     */
    static const float DEGREE;

    /**
     * Equivalent radians of 1 Degree
     */
    static const float RADIAN;
  };
}
