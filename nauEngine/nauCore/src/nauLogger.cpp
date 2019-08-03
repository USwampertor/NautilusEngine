/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauLogger.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/06/25 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauLogger.h"

namespace nauEngineSDK {

  void
  Logger::init() {
    _m.clear();
  }

  void
  Logger::clear() {
    _m.clear();
  }

  void
  Logger::add(String newEntry) {
    _m.push_back(newEntry);
  }

  void
  Logger::toIDE(String newEntry, LOGGER_LEVEL::E level) {

    String outputString;

    if      (LOGGER_LEVEL::DEBUG   == level) { outputString = LGRDEBUGGRSIGN; }
    else if (LOGGER_LEVEL::ERRORED == level) { outputString = LGRERROREDSIGN; }
    else if (LOGGER_LEVEL::WARNING == level) { outputString = LGRWARNINGSIGN; }
    else if (LOGGER_LEVEL::SUCCESS == level) { outputString = LGRSUCCESSSIGN; }

    outputString += newEntry; 

#if NAU_COMPILER == NAU_COMPILER_MSVC
    OutputDebugString(newEntry.c_str());
    OutputDebugString("\n");
# elif NAU_COMPILER == NAU_COMPILER_GNUC
#endif
  }

  void
  Logger::toScreen(String newEntry, LOGGER_LEVEL::E level) {

  }

  void
  Logger::toConsole(String newEntry, LOGGER_LEVEL::E level) {

  }


}