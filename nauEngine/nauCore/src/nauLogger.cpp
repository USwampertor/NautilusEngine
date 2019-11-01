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
#include <nauDataStream.h>


namespace nauEngineSDK {

  void
  Logger::init() {
    m_data.clear();
  }

  void
  Logger::clear() {
    m_data.clear();
  }

  void
  Logger::add(String newEntry, LOGGER_LEVEL::E level) {
    m_data.push_back(LoggerString(newEntry, level));
  }

  void
  Logger::toIDE(String newEntry, LOGGER_LEVEL::E level) {

    String outputString = "(";
    outputString.append(Clock::instance().hour());
    outputString.append("): ");

    if      (LOGGER_LEVEL::DEBUG   == level) { outputString += LGRDEBUGGRSIGN; }
    else if (LOGGER_LEVEL::ERRORED == level) { outputString += LGRERROREDSIGN; }
    else if (LOGGER_LEVEL::WARNING == level) { outputString += LGRWARNINGSIGN; }
    else if (LOGGER_LEVEL::SUCCESS == level) { outputString += LGRSUCCESSSIGN; }

    outputString += newEntry; 

#if NAU_COMPILER == NAU_COMPILER_MSVC
    OutputDebugString(newEntry.c_str());
    OutputDebugString("\n");
# elif NAU_COMPILER == NAU_COMPILER_GNUC
#endif

    add(outputString, level);
  }

  void
  Logger::toScreen(String newEntry, 
                   LOGGER_LEVEL::E level,
                   Color color,
                   float duration) {
    String outputString = "(";
    outputString.append(Clock::instance().hour());
    outputString.append("): ");
    outputString.append(newEntry);

    add(outputString, level);
  }

  void
  Logger::toConsole(String newEntry, LOGGER_LEVEL::E level) {

    String outputString = "(";
    outputString.append(Clock::instance().hour());
    outputString.append("): ");
    outputString.append(newEntry);

    add(outputString, level);
  }

  Vector<String>
  Logger::get() {
    Vector<String> output;
    for (auto logString : m_data) {
      if (logString.m_type == LOGGER_LEVEL::ERRORED) {
        output.push_back(logString.m_data);
      }
    }
  }

  void
  Logger::dump() {

    String fileName = "ERRORLOG";
    fileName.append(Clock::instance().toString());
    fileName.append(".txt");

    FileStream dumpFile;

    dumpFile.m_file.open(fileName, fstream::out);

    if (!dumpFile.m_file.is_open()) {
      toIDE("Couldn't create dump file", LOGGER_LEVEL::ERRORED);
    }

    for (auto errorString : m_data) {
      dumpFile.m_file << errorString.m_data << '\n';
    }
    dumpFile.m_file.close();
  }

}