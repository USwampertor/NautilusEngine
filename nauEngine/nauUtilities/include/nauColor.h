/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauColor.h
 * @author Marco "Swampy" Mill嫕
 * @date 10/23/2019
 * @brief Color struct in RGBA to have predefined colors for rendering purposes
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesUtil.h"

#include "nauVector4.h"

#define MAX_COLOR_VALUE 255

namespace nauEngineSDK {
  /**
   * Color
   * Description:
   * 	Class that holds 4 uint32 numbers that range from 0 to 255
   * Sample usage:
   * 	Color.blend() blends two colors
   */
class NAU_UTILITY_EXPORT Color
{
public:

  /**
   * Default constructor
   */
  Color() = default;

  /**
   * Default constructor
   */
  ~Color() = default;

  /**
   * Constructor with a copy of a color
   */
  Color(const Color& copy)
    : m_r(copy.m_r),
      m_g(copy.m_g),
      m_b(copy.m_b),
      m_a(copy.m_a) {}

  /**
   * Constructor with a Vector 4
   */
  Color(Vector4 vector)
    : m_r(static_cast<uint32>(vector.x)),
      m_g(static_cast<uint32>(vector.y)),
      m_b(static_cast<uint32>(vector.z)),
      m_a(static_cast<uint32>(vector.w)) {}

  /**
   * Constructor with a Vector 3
   */
  Color(Vector3 vector)
    : m_r(static_cast<uint32>(vector.x)),
      m_g(static_cast<uint32>(vector.y)),
      m_b(static_cast<uint32>(vector.z)) {}

  /**
   * @brief Constructor with a RGBA color based on uint32 from 0 to 255
   * @param uint32 R red color from 0 to 255
   * @param uint32 G green color from 0 to 255
   * @param uint32 B blue color from 0 to 255
   * @param uint32 A alpha channel from 0 to 255
   */
  Color(uint32 R, uint32 G = 0, uint32 B = 0, uint32 A = 1)
    : m_r(R),
      m_g(G),
      m_b(B),
      m_a(A) {}

  /**
   * @brief Returns a string with the information of the color
   * @param 
   * @return a String with (R: XXX, G: XXX, B: XXX, A: XXX)
   *
   */
  String
  toString();

  /**
   * @brief 
   * @param Vector3 HSV value
   * @return 
   *
   */
  void
  HSVToRGB(Vector3 hsv);

  /**
   * @brief Blends two colors
   * @param Color& A
   * @param Color& B
   * @return the blending of the two colors
   *
   */
  static Color
  blend(Color& A, Color& B);

  /**
   * @brief Operator * overload to multiply two colors
   * @param Color& other color to combine
   * @return the combination of the two colors
   *
   */
  Color
  operator*(Color& other);

  /**
   * @brief Operator + overload to sum two colors
   * @param Color& other color to sum
   * @return the combination of the two colors
   *
   */
  Color
  operator+(Color& other);

  /**
   * @brief Operator - overload to get the difference of two colors
   * @param Color& other color to get the difference
   * @return the difference between two colors
   *
   */
  Color
  operator-(Color& other);

  /**
   * @brief Operator / overload to get the division between two colors
   * @param Color& other color to get the division
   * @return the division between two colors
   *
   */
  Color
  operator/(uint32& other);

  /**
   * @brief Sets a color based in (R, G, B, A)
   * @param float R
   * @param float G
   * @param float B
   * @param float A
   * @return 
   *
   */
  void
  setColor(float r, float g, float b, float a = 1.0f);

  /**
   * @brief Sets a color based in (R, G, B, A)
   * @param uint32 R
   * @param uint32 G
   * @param uint32 B
   * @param uint32 A
   * @return 
   *
   */
  void
  setColor(uint32 r, uint32 g, uint32 b, uint32 a);

  /**
   * @brief Returns the color as a vector3 in RGB format
   * @param 
   * @return a Vector3(R, G, B) in uint32
   *
   */
  Vector3
  toVector3();

  /**
   * @brief Returns the color as a Vector4 in RGBA format
   * @param 
   * @return a Vector4(R, G, B, A) in uint32 (0-255)
   *
   */
  Vector4
  toVector4();

  /**
   * @brief Returns the color as a Vector in RGBA format 
   * @param 
   * @return a Vector(R, G, B, A) in float (0.0f - 1.0f)
   *
   */
  Vector4
  toVector4F();

  static const Color Azure;
  static const Color Black;
  static const Color Blue;
  static const Color Clear;
  static const Color Cyan;
  static const Color Gray;
  static const Color Green;
  static const Color Grey;
  static const Color Magenta;
  static const Color Red;
  static const Color Orange;
  static const Color Violet;
  static const Color White;
  static const Color Yellow;

public:

  /**
   * Red channel of the color
   */
  uint32 m_r;

  /**
   * Green channel of the color
   */
  uint32 m_g;

  /**
   * Blue channel of the color
   */
  uint32 m_b;
  
  /**
   * Alpha channel of the color
   */
  uint32 m_a;

};
}
