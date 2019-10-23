/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauColor.h
 * @author Marco "Swampy" Millan
 * @date 10/23/2019
 * @brief Color struct in RGBA to have predefined colors for rendering purposes
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesUtil.h"

#include "nauVector4.h"

namespace nauEngineSDK {
class Color
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
  Color(const Color& copy);

  /**
   * Constructor with a Vector 4
   */
  Color(Vector4 vector);

  /**
   * Constructor with a Vector 3
   */
  Color(Vector3 vector);

  /**
   * Constructor with a RGBA color based on uint32 from 0 to 255
   */
  Color(uint32 R, uint32 G = 0, uint32 B = 0, uint32 A = 1);

  /**
   * Constructor with a RGBA color based on float from 0 to 1
   */
  Color(float R, float G = 0.0f, float B = 0.0f, float A = 1.0f);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  String
  toString();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  HSVToRGB(Vector3 hsv);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  Vector3
  toVector3();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  Vector4
  toVector4();

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
