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


namespace nauEngineSDK {
  struct NAU_UTILITY_EXPORT nauPlatformMath {

    static const float  PI;
    static const float EULER;
    static const float DEGREE;
    static const float RADIAN;
    /**
     * @brief Changes from degrees to rads
     * @param T the degree to translate
     * @return the degree in rads
     * 
     */

    /**
     * Transformation functions
     */
    template<typename T>
    static T degToRad(T degree) {
      return (degree * 0.017453292519f);
    }


    template<typename T>
    static T radToDeg(T rad) {
      return (rad * 57.29577951f);
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
        return std::sin(rad);
    }

    template<typename T>
    static T cos(T rad) {
        return std::cos(rad);
    }

    template<typename T>
    static T tan(T rad) {
        return std::tan(rad);
    }

    template<typename T>
    static T asin(T rad) {
        return std::asin(rad);
    }

    template<typename T>
    static T acos(T rad) {
        return std::acos(rad);
    }

    template<typename T>
    static T atan(T rad) {
        return std::atan(rad);
    }

    template<typename T>
    static T atan2(T t1, T t2) {
        return std::atan2(t1, t2);
    }

    template<typename T>
    static T sinh(T rad) {
        return std::sinh(rad);
    }

    template<typename T>
    static T cosh(T rad) {
        return std::cosh(rad);
    }

    template<typename T>
    static T tanh(T rad) {
        return std::tanh(rad);
    }

    template<typename T>
    static T asinh(T rad) {
        return std::asinh(rad);
    }

    template<typename T>
    static T acosh(T rad) {
        return std::acosh(rad);
    }

    template<typename T>
    static T atanh(T rad) {
        return std::atanh(rad);
    }


    /**
     * Basic math library
     */
    template<typename T>
    static T exp(T power) {
        return std::exp(power)
    }
    
    template<typename T>
    static T pow(T value, T power) {
      return static_cast<T>(std::pow(value, power));
    }

    template<typename T>
    static T abs(T value) {
      return std::abs(value);
    }

    template<typename T>
    static T sqr(T value) {
      return value*value;
    }
    
    template<typename T>
    static T cbc(T value) {
      return value*value*value;
    }

    template <typename T>
    static T sqrt(T value) {
      return static_cast<T>(std::sqrt(value));
    }

    template<typename T>
    static T invSqrt(T value) {
      return 1.0f/std::sqrt(value);
    }

    template <typename T>
    static T cbrt(T value) {
      return std::cbrt(value);
    }

    template <typename T>
    static T hypot(T co, T ca) {
      return std::hypot(co, ca);
    }


   
    template<typename T>
    static T floor(T a) {
      return std::floor(a);
    }

    template<typename T>
    static T ceil(T a) {
      return std::ceil(a);
    }

    template<typename T>
    static T roundHalf(T a) {
      return std::round(a*2.0f) / 2.0f;
    }

    template<typename T>
    static T round(T a) {
      return std::round(a);
    }

    template<typename T>
    static T max(T a, T b) {
      return std::max(a, b);
    }

    template<typename T>
    static T min(T a, T b) {
      return std::min(a, b);
    }

    template<typename T>
    static T max3(T a, T b, T c) {
      return max(max(a, b), c);
    }
    
    template<typename T>
    static T min3(T a, T b, T c) {
      return min(min(a, b), c);
    }

    template<typename T>
    static T frac(T fracpart, T* intpart) {
      return std::modf(fracpart, intpart);
    }

    template<typename T>
    static T clamp(T number, T bot, T top) {
      return std::clamp(number, bot, top);
    }

    
    /**
    * Log functions
    */
    template <typename T>
    static T log10(T value) {
      return std::log10(value);
    }

    template <typename T>
    static T log2(T value) {
      return std::log2(value);
    }

    template <typename T>
    static T logn(T value) {
      return std::log(value);
    }

    template <typename T>
    static T logx(T base, T value) {
      return log(value) / log(base);
    }


    /**
     * @brief Get the cosine of an angle with Taylor
     *
     * @param T value to obtain the angle of
     *
     * @return the cosine
     */
    template<typename T>
    static T lerp(T a, T b, float scale) {
        return (a + (b - a)* t);
    }

    template<typename T>
    static T factorial(T top) {
        return top == 0 ? 1 : (top * factorial(top - 1));
    }

    template<typename T>
    static T fastcos(T rad) {
      return (
        1 -
        (pow(rad, 2) / 2) +
        (pow(rad, 4) / 24) -
        (pow(rad, 6) / 720) +
        (pow(rad, 8) / 40320));
    }
    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    static T fastsin(T rad) {
      return (
        rad -
        (pow(rad, 3) / 6) +
        (pow(rad, 5) / 120) -
        (pow(rad, 7) / 5040) +
        (pow(rad, 9) / 362880));
    }
    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    static T fasttan(T rad) {
      return (
        rad -
        (pow(rad, 3) * 2 / 6) +
        (pow(rad, 5) * 16 / 120) -
        (pow(rad, 7) * 272 / 5040) +
        (pow(rad, 9) * 7936 / 362880));
    }
    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    static T fastacos(T rad) {
      return static_cast<T>(0);
    }

    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    static T fastasin(T rad) {
    
    }

    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
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


    template<typename T>
    static T fastcosh(T rad) {
      return (
        1 +
        (pow(rad, 2) / 2) +
        (pow(rad, 4) / 24) +
        (pow(rad, 6) / 720) +
        (pow(rad, 8) / 40320));
    }

    template<typename T>
    static T fastsinh(T rad) {
      return (
        rad +
        ((rad*rad*rad) / 6) +
        ((rad*rad*rad*rad*rad) / 120) +
        ((rad*rad*rad*rad*rad*rad*rad) / 5040) +
        ((rad*rad*rad*rad*rad*rad*rad*rad*rad) / 362880));
    }

    template<typename T>
    static T fasttanh(T rad) {
      return ();
    }

    /**
     * Collisions
     */

  };
}
