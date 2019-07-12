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
  Clock::init() {
    m_time = high_resolution_clock::now();
  }


  float
  Clock::deltaTime() {
    auto now = high_resolution_clock::now();
    milliseconds ms = duration_cast<milliseconds>(now - m_time);
    m_time = now;
    return static_cast<float>(ms.count());
  }

  float
  Clock::deltaTime(DELTA::E as) {
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

  String
  Clock::hour() {
    String hour = "";
    std::time_t timeStamp;

    system_clock::time_point today = system_clock::now();

    timeStamp = system_clock::to_time_t(today);
    std::tm localTime = *localtime(&timeStamp);

    hour += std::to_string(localTime.tm_hour);
    hour += ": ";
    hour += std::to_string(localTime.tm_min);
    hour += ": ";
    hour += std::to_string(localTime.tm_sec);
    hour += "\n";

    return hour;
  }

}