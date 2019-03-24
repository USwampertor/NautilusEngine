/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTime.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/03/08 2019
 * @brief Time member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauTimer.h"

namespace nauEngineSDK {

  void
  Timer::restart() {
    m_time = high_resolution_clock::now();
    m_totalTime = 0.0f;
  }

  float
  Timer::asSeconds() {
    auto now = high_resolution_clock::now();

    seconds s = duration_cast<seconds>(now - m_time);
    m_totalTime = static_cast<float>(s.count());
    return m_totalTime;
  }

  float
  Timer::asMilliseconds() {
    auto now = high_resolution_clock::now();

    milliseconds s = duration_cast<milliseconds>(now - m_time);
    m_totalTime = static_cast<float>(s.count());
    return m_totalTime;
  }

  float
  Timer::asMicroseconds() {
    auto now = high_resolution_clock::now();

    microseconds s = duration_cast<microseconds>(now - m_time);
    m_totalTime = static_cast<float>(s.count());
    return m_totalTime;
  }

}
