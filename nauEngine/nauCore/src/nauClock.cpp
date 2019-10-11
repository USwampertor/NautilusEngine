/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauClock.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/03/08 2019
 * @brief Clock member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauClock.h"

namespace nauEngineSDK {

  void
  Clock::init() {
    m_time = high_resolution_clock::now();
  }

  void
  Clock::update() {
    auto now = high_resolution_clock::now();
    milliseconds ms = duration_cast<milliseconds>(now - m_time);
    m_time = now;
    m_delta = static_cast<float>(ms.count());
  }

  float
  Clock::deltaTime() {
    return m_delta;
  }

  float
  Clock::deltaTime(DELTA::E as) {
    if      (DELTA::DELTASECOND == as) {
      m_delta *= 0.001f;
    }
    else if (DELTA::MICROSECOND == as) {
      m_delta *= 1000.0f;
    }
    return m_delta;
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