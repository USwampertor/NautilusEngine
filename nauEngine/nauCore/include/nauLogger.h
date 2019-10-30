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

#include "nauClock.h"
#include "nauModule.h"
#include "nauColor.h"

#include <iostream>



#define LGRWARNINGSIGN " !WARNING! "
#define LGRERROREDSIGN " !!ERROR!! "
#define LGRSUCCESSSIGN " -SUCCESS- "
#define LGRDEBUGGRSIGN " --DEBUG-- "

namespace nauEngineSDK {

/**
 * Forward declaration
 */
  class FileStream;

namespace LOGGER_LEVEL {
  enum E
  {
    DEFAULT = 0,
    DEBUG,
    WARNING,
    ERRORED,
    SUCCESS
  };
}

/**
 *  LoggerString 
 * Description:
 * 	String for exclusive use in the logger
 * Sample usage:
 * 	
 */
class NAU_CORE_EXPORT LoggerString 
{
 public:
  /**
   * Default constructor
   */
  LoggerString() = default;

  /**
   * Default destructor
   */
  ~LoggerString() = default;

  /**
   * @brief Copy constructor
   * @param LoggerString& other the other string to copy
   *
   */
  LoggerString(LoggerString& other) 
    : m_type(other.m_type),
      m_data(other.m_data) {}

  /**
   * @brief Constructor with a defined string and level of the log
   * @param String the data
   * @param LOGGER_LEVEL::E the level of the log
   *
   */
  LoggerString(String data, LOGGER_LEVEL::E type = LOGGER_LEVEL::DEFAULT)
    : m_data(data),
      m_type(type) {}

 public:

  /**
   * Type of the logged string
   */
  LOGGER_LEVEL::E m_type;

  /**
   * The string with the information of the log
   */
  String m_data;

};


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
  add(String newEntry, LOGGER_LEVEL::E level = LOGGER_LEVEL::DEFAULT);

  /**
   * @brief Prints a string to the IDE being used
   * @param String new Entry
   * @return 
   *
   */
  void
  toIDE(String newEntry, LOGGER_LEVEL::E level = LOGGER_LEVEL::DEFAULT);

  /**
   * @brief Prints a string on the screen
   * @param String new Entry
   * @return 
   *
   */
  void
  toScreen(String newEntry, 
           LOGGER_LEVEL::E level = LOGGER_LEVEL::DEFAULT, 
           Color color = Color::White, 
           float duration = 1.0f);

  /**
   * @brief Prints a string to the Console Object
   * @param String new Entry
   * @return 
   *
   */
  void
  toConsole(String newEntry, LOGGER_LEVEL::E level = LOGGER_LEVEL::DEFAULT);

  /**
   * @brief Dumps all the errors found in a file named as the hour it found a crash
   * @param 
   * @return void. It creates a file in the root directory tho
   *
   */
  void
  dump();

private:

  /**
   * The object that will hold all entries
   */
  Vector<LoggerString> m_data;

};


}

