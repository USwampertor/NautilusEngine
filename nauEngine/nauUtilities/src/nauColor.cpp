/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauColor.cpp
 * @author Marco "Swampy" Millan
 * @date 10/23/2019
 * @brief Color member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauColor.h"

namespace nauEngineSDK {
  String
  Color::toString() {
    String toReturn;
    toReturn += "(R: ";
    toReturn += std::to_string(m_r);
    toReturn += ", G: ";
    toReturn += std::to_string(m_g);
    toReturn += ", B: ";
    toReturn += std::to_string(m_b);
    toReturn += ", A: ";
    toReturn += std::to_string(m_a);
    toReturn += ")";

    return toReturn;
  }

  void
  Color::HSVToRGB(Vector3 hsv) {

  }

  Color
  Color::blend(Color& A, Color& B) {
    return Color(Math::lerp(A.m_r, B.m_r, 0.5),
                 Math::lerp(A.m_g, B.m_g, 0.5),
                 Math::lerp(A.m_b, B.m_b, 0.5),
                 Math::lerp(A.m_a, B.m_a, 0.5));
  }

  Color
  Color::operator*(Color& other) {

    return Color((m_r * other.m_r) / 255, 
                 (m_g * other.m_g) / 255, 
                 (m_b * other.m_b) / 255, 
                 (m_a * other.m_a) / 255);
  }

  Color
  Color::operator+(Color& other) {
    return Color((m_r + other.m_r) / 255, 
                 (m_g + other.m_g) / 255, 
                 (m_b + other.m_b) / 255, 
                 (m_a + other.m_a) / 255);

  }

  Color
  Color::operator-(Color& other) {
    return Color((m_r - other.m_r) / 255, 
                 (m_g - other.m_g) / 255, 
                 (m_b - other.m_b) / 255, 
                 (m_a - other.m_a) / 255);
  }

  Color
  Color::operator/(uint32& other) {
    return Color((m_r / other), 
                 (m_g / other), 
                 (m_b / other), 
                 (m_a / other));
  }

  void
  Color::setColor(float r, float g, float b, float a) {
    m_r = r * 255;
    m_g = g * 255;
    m_b = b * 255;
    m_a = a * 255;
  }

  void
  Color::setColor(uint32 r, uint32 g, uint32 b, uint32 a) {
    m_r = r;
    m_g = g;
    m_b = b;
    m_a = a;
  }

  Vector3
  Color::toVector3() {
    return Vector3(m_r, m_g, m_b);
  }

  Vector4
  Color::toVector4() {
    return Vector4(m_r, m_g, m_b, m_a);
  }

  Vector4
  Color::toVector4F() {
    return Vector4(m_r / 255.0f, m_g / 255.0f, m_b / 255.0f, m_a / 255.0f);
  }

  const Color Color::Azure    = Color(240,255,255);
  const Color Color::Black    = Color(0);
  const Color Color::Blue     = Color(0,0,255);
  const Color Color::Clear    = Color(0,0,0,127);
  const Color Color::Cyan     = Color(0,255,255);
  const Color Color::Gray     = Color(128,128,128);
  const Color Color::Green    = Color(0,255,0);
  const Color Color::Grey     = Color(100,100,100);
  const Color Color::Magenta  = Color(255,0,255);
  const Color Color::Red      = Color(255,0,0);
  const Color Color::Orange   = Color(255,100,0);
  const Color Color::Violet   = Color(140,0,210);
  const Color Color::White    = Color(255,255,255);
  const Color Color::Yellow   = Color(255,255,0);

}