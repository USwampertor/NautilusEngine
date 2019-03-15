/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauTime.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/08 2019
 * @brief Time class for time registered by users, its like a clock but its personal
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauClock.h"

namespace nauEngineSDK {
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
     * @brief Starts the timer 
     * @param 
     * @return 
     *
     */
    void
    start();


    /**
     * @brief Restarts the elapsed time in the elapsed time member
     * @param 
     * @return 
     *
     */
    void
    restart();

    /**
     * @brief Returns the elapsed time between a frame and another
     * @param 
     * @return the time between frames
     *
     */
    float
    deltaTime();

  };
  
}

