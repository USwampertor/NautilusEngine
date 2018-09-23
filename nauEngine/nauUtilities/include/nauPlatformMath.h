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

/**
 * TODO:
 * cos
 * sin
 * tan
 * acos
 * asin
 * atan
 * atan2
 * cosh
 * sinh
 * tanh
 * acosh
 * asinh
 * atanh
 * LERP = a + (b-a)*t; t es hasta donde lo quiero t de 0 a 1
 * Extrapolar es mas de 1
 */
namespace nauEngineSDK {
  struct nauPlatformMath {

    static const float  PI;
    static const double euler;
    /**
     * @brief Changes from degrees to rads
     * @param T the degree to translate
     * @return the degree in rads
     * 
     */
    template<typename T>
    T degToRad(T degree) {
      return (degree * 0.017453292519f);
    }


    template<typename T>
    T radToDeg(T rad) {
      return (rad * 57.29577951f);
    }

    template<typename T>
    T sin(T rad) {
        return std::sin(rad);
    }

    template<typename T>
    T cos(T rad) {
        return std::cos(rad);
    }

    template<typename T>
    T tan(T rad) {
        return std::tan(rad);
    }

    template<typename T>
    T asin(T rad) {
        return std::asin(rad);
    }

    template<typename T>
    T acos(T rad) {
        return std::acos(rad);
    }

    template<typename T>
    T atan(T rad) {
        return std::atan(rad);
    }

    template<typename T>
    T atan2(T t1, T t2) {
        return std::atan2(t1, t2);
    }

    template<typename T>
    T sinh(T rad) {
        return std::sinh(rad);
    }

    template<typename T>
    T cosh(T rad) {
        return std::cosh(rad);
    }

    template<typename T>
    T tanh(T rad) {
        return std::tanh(rad);
    }

    template<typename T>
    T asinh(T rad) {
        return std::asinh(rad);
    }

    template<typename T>
    T acosh(T rad) {
        return std::acosh(rad);
    }

    template<typename T>
    T atanh(T rad) {
        return std::atanh(rad);
    }

    template<typename T>
    T exp(T power) {
        return std::exp(power)
    }
    
    template<typename T>
    T pow(T value, T power) {
        return std::pow(value, power);
    }

    template <typename T>
    T sqrt(T value) {
        return std::sqrt(value);
    }

    template <typename T>
    T cbrt(T value) {
        return std::cbrt(value);
    }

    template <typename T>
    T hypot(T co, T ca) {
        return std::hypot(co, ca);
    }
    /**
     * @brief Get the cosine of an angle with Taylor
     *
     * @param T value to obtain the angle of
     *
     * @return the cosine
     */
    template<typename T>
    T lerp(T a, T b, float scale) {
        return (a + (b - a)* t);
    }

    template<typename T>
    T factorial(T top) {
        return top == 0 ? 1 : (top * factorial(top - 1));
    }

    template<typename T>
    T fastcos(T rad) {
      return (
        1 -
        (pow(rad, 2) / 2) +
        (pow(rad, 4) / 24) -
        (pow(rad, 6) / 720) +
        (pow(rad, 8) / 40320);
    }
    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    T fastsin(T rad) {
      return (
        rad -
        (pow(rad, 3) / 6) +
        (pow(rad, 5) / 120) -
        (pow(rad, 7) / 5040) +
        (pow(rad, 9) / 362880);
    }
    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    T fasttan(T rad) {
      return (
        rad -
        (pow(rad, 3) * 2 / 6) +
        (pow(rad, 5) * 16 / 120) -
        (pow(rad, 7) * 272 / 5040) +
        (pow(rad, 9) * 7936 / 362880);
    }
    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    T acos(T) {}

    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    T asin(T) {}

    /**
    * @brief Get the cosine of an angle with Taylor
    *
    * @param T value to obtain the angle of
    *
    * @return the cosine
    */
    template<typename T>
    T atan(T rad) {
      return (
        rad -
        (pow(rad, 3) / 3) +
        (pow(rad, 3) / 5) -
        (pow(rad, 3) / 7) +
        (pow(rad, 3) / 9);
    }


    template<typename T>
    T cosh(T) {
      return (
        1 +
        (pow(rad, 2) / 2) +
        (pow(rad, 4) / 24) +
        (pow(rad, 6) / 720) +
        (pow(rad, 8) / 40320);
    }

    template<typename T>
    T sinh(T) {
      return (
        T +
        ((T*T*T) / 6) +
        ((T*T*T*T*T) / 120) +
        ((T*T*T*T*T*T*T) / 5040) +
        ((T*T*T*T*T*T*T*T*T) / 362880);
    }

    template<typename T>
    T tanh(T) {
      return (

        )
    }

    template<typename T>
    T floor(T a) {
      return std::floor(a);
    }

    template<typename T>
    T ceil(T a) {
      return std::ceil(a);
    }

    template<typename T>
    T roundHalf(T a) {
      return std::round(a*2.0f)/2.0f;
    }

    template<typename T>
    T round(T a) {
      return std::round(a);
    }

    template<typename T>
    T max(T a, T b) {
      return std::max(a, b);
    }

    template<typename T>
    T min(T a, T b) {
      return std::min(a, b);
    }

  };
}
