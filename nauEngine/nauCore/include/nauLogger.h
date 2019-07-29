/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauLogger.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/12 2019
 * @brief Logger object for console output debugging and A
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauModule.h"

#define LGRWARNINGSIGN " !WARNING! "
#define LGRERROREDSIGN " !!ERROR!! "
#define LGRSUCCESSSIGN " -SUCCESS- "
#define LGRDEBUGGRSIGN " --DEBUG-- "

namespace nauEngineSDK {

namespace LOGGER_LEVEL {
  enum E
  {
    DEBUG = 0,
    WARNING,
    ERRORED,
    SUCCESS
  };
}

class NAU_CORE_EXPORT Logger : public Module<Logger>
{
public:
  /**
   * Default constructor
   */
  Logger() = default;

  /**
   * Default destructor
   */
  ~Logger() = default;

  /**
   * @brief Initializes the logger
   * @param 
   * @return 
   *
   */
  void
  init();

  /**
   * @brief Clears the logger
   * @param 
   * @return 
   *
   */
  void
  clear();

  /**
   * @brief adds a new string to the logger
   * @param 
   * @return 
   *
   */
  void
  add(String newEntry);

  /**
   * @brief Prints a string to the IDE being used
   * @param String new Entry
   * @return 
   *
   */
  void
  toIDE(String newEntry, LOGGER_LEVEL::E level = LOGGER_LEVEL::DEBUG);

  /**
   * @brief Prints a string on the screen
   * @param String new Entry
   * @return 
   *
   */
  void
  toScreen(String newEntry, LOGGER_LEVEL::E level = LOGGER_LEVEL::DEBUG);

  /**
   * @brief Prints a string to the Console Object
   * @param String new Entry
   * @return 
   *
   */
  void
  toConsole(String newEntry, LOGGER_LEVEL::E level = LOGGER_LEVEL::DEBUG);

private:

  /**
   * The object that will hold all entries
   */
  Vector<String> _m;

};
}

