/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/17 2018
 * @brief Random member implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauRandom.h"

namespace nauEngineSDK {

float 
nauRandomZ::next() {
  float res =
    (1.0f / nauMath::sqrt(2.0f*nauMath::PI*m_deviation)) *
    nauMath::exp(-((m_seed - nauMath::sqr(m_mean)) / 2.0f*m_deviation));
  m_seed = res;
  return res;

}

}

