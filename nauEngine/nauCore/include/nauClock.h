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

namespace nauEngineSDK {
  using namespace std::chrono;

  enum DELTA
  {
    MICROSECOND         = 0,    //Returns the value in microseconds 
    MILLISECOND         = 1,    //Returns the value in milliseconds
    DELTASECOND         = 2     //Returns the value in seconds

  };


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
    initialize();


    /**
     * @brief returns the delta time between the last time it was called
     * @param 
     * @return the time in milliseconds
     *
     */
    float
    DeltaTime();

    /**
     * @brief returns the delta time between the last time it was called
     * @param
     * @return the time in the given DELTA parameter
     *
     */
    float
    DeltaTime(DELTA as);

  private:

    high_resolution_clock::time_point m_time;
  
  };
  
}


