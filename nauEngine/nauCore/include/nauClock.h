/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauClock.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/08 2019
 * @brief Clock Module member declaration, its for taking deltas and controls the time in the app
 *
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "nauPrerequisitesCore.h"
#include "nauModule.h"

#include <chrono>
#include <ctime>

namespace nauEngineSDK {
  using namespace std::chrono;

  namespace DELTA
  {
  enum E
  {
    MICROSECOND         = 0,    //Returns the value in microseconds 
    MILLISECOND         = 1,    //Returns the value in milliseconds
    DELTASECOND         = 2     //Returns the value in seconds

  };

  }


   /**
    * Clock
    * Description:
    * 	Used for checking time and getting deltas
    * Sample usage:
    *   Clock.deltaTime gives the difference between this frame and the last frame in seconds	
    */
  class NAU_CORE_EXPORT Clock : public Module<Clock>
  {
  public:
    /**
     * Default constructor
     */
    Clock() = default;
  
    /**
     * Default destructor
     */
    ~Clock() = default;
    
    /**
     * @brief initializes the clock and gets the current time
     * @param 
     * @return 
     *
     */
    void
    init();


    /**
     * @brief returns the delta time between the last time it was called
     * @param 
     * @return the time in milliseconds
     *
     */
    float
    deltaTime();

    /**
     * @brief returns the delta time between the last time it was called
     * @param how you want to take the time (MICROSECONDS MILISECONDS OR SECONDS)
     * @return the time in the given DELTA parameter
     *
     */
    float
    deltaTime(DELTA::E as);

    /**
     * @brief Returns a string with the exact hour in the computer
     * @param 
     * @return the string at x hour, minute, second and millisecond
     *
     */
    String
    hour();

    /**
     * @brief Returns a string with the year, month, day and hour f the computer
     * @param 
     * @return YYYY-MM-DD-HH-MM-SS
     *
     */
    String 
    toString();

    /**
     * @brief updates the delta value
     * @param 
     * @return 
     *
     */
    void
    update();

  private:

    /**
     * Clock for getting time
     */
    high_resolution_clock::time_point m_time;
  
    /**
     * the delta time value between the last frame and this one
     */
    float m_delta;
  };
  
}


