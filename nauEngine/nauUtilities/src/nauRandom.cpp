/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/17 2018
 * @brief Random member implementation
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/

#include "nauRandom.h"

namespace nauEngineSDK {

float 
RandomZ::next() {
  float res =
    (1.0f / Math::sqrt(2.0f*Math::PI*m_deviation)) *
    Math::exp(-((m_seed - Math::sqr(m_mean)) / 2.0f*m_deviation));
  m_seed = res;
  return res;

}

float
RandomMC::next() {
  
  float res = 0;
  
  return res;
}

void
RandomBM::initialize() {
  m_seed = static_cast<float>(time(0));

  m_z1 = static_cast<float>(time(0));
  m_z2 = static_cast<float>(time(0));
}

float
RandomBM::next() {

  if (m_inquery) {
    m_inquery = false;
    return m_z1;
  }

  float z1 = Math::sqrt(-2.0f*Math::logN(m_z2))*Math::cos(2.0f*Math::PI*m_z2);
  float z2 = Math::sqrt(-2.0f*Math::logN(m_z1))*Math::cos(2.0f*Math::PI*m_z1);

  m_z1 = z2;
  m_z2 = z1;

  m_inquery = true;
  return m_z2;
}

}

