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
  Clock::initialize() {
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
  Clock::deltaTime(DELTA as) {
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
    String time;




    return time;
  }

}