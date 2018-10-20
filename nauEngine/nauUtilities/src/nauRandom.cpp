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

float
nauRandomMC::next() {
  
  float res = 0;
  
  return res;
}

void
nauRandomBM::initialize() {
  m_seed = static_cast<float>(time(0));

  m_z1 = static_cast<float>(time(0));
  m_z2 = static_cast<float>(time(0));
}

float
nauRandomBM::next() {

  if (m_inquery) {
    m_inquery = false;
    return m_z1;
  }

  float z1 = nauMath::sqrt(-2.0f*nauMath::logN(m_z2))*nauMath::cos(2.0f*nauMath::PI*m_z2);
  float z2 = nauMath::sqrt(-2.0f*nauMath::logN(m_z1))*nauMath::cos(2.0f*nauMath::PI*m_z1);

  m_z1 = z2;
  m_z2 = z1;

  m_inquery = true;
  return m_z2;
}

}

