/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief the cpp from the vector object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

/**
 * #include
 */

#include "nauVector2.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
  const Vector2 Vector2::ONES = Vector2(1.0f, 1.0f);
  const Vector2 Vector2::ONEX = Vector2(1.0f, 0.0f);
  const Vector2 Vector2::ONEY = Vector2(0.0f, 1.0f);
  
  inline Vector2::Vector2(const Vector3& v): x(v.x),y(v.y) {}


}
