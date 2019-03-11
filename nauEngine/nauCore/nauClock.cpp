/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauClock.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/03/08 2019
 * @brief Clock member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauClock.h"

namespace nauEngineSDK {

  void
  Clock::initialize() {
    m_time = high_resolution_clock::now();
  }


  float
  Clock::DeltaTime() {
    auto now = high_resolution_clock::now();
    milliseconds ms = duration_cast<milliseconds>(now - m_time);
    m_time = now;
    return static_cast<float>(ms.count());
  }

  float
  Clock::DeltaTime(DELTA as) {
    auto now = high_resolution_clock::now();
    milliseconds ms = duration_cast<milliseconds>(now - m_time);
    m_time = now;

    if      (DELTA::DELTASECOND == as) {
      return static_cast<float>(ms.count() * 0.001f);
    }
    else if (DELTA::MICROSECOND == as) {
      return static_cast<float>(ms.count() * 1000.0f);
    }
    return static_cast<float>(ms.count());
  }
}