/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauTime.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/08 2019
 * @brief Time class for time registered by users, its like a clock but its personal
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauClock.h"

namespace nauEngineSDK {
  using namespace std::chrono;

   /**
    * Time
    * Description:
    * 	to control time in the app
    * Sample usage:
    *   time seconds
    */
  class NAU_CORE_EXPORT Timer
  {
  public:
    /**
     * Default constructor
     */
    Timer() = default;
  
    /**
     * Default destructor
     */
    ~Timer() = default;

    /**
     * @brief Restarts the timer and the elapsed time
     * @param 
     * @return 
     *
     */
    void
    restart();

    /**
     * @brief Shows the accumulated time in seconds
     * @param 
     * @return seconds passed since last restart
     *
     */
    float
    asSeconds();

    /**
     * @brief Shows the accumulated time in milliseconds
     * @param
     * @return milliseconds passed since last restart
     *
     */
    float
    asMilliseconds();

    /**
     * @brief Shows the accumulated time in microseconds
     * @param
     * @return microseconds passed since last restart
     *
     */
    float
    asMicroseconds();

  private:

    /**
     * Accumulated time
     */
    float m_totalTime;

    /**
     * Clock for getting Time
     */
    high_resolution_clock::time_point m_time;
  };
  
}

