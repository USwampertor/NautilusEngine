/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNetwork.cpp
 * @author Marco "Swampy" Millan
 * @date 10/22/2019
 * @brief Neural Network
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauNetwork.h"

namespace nauEngineSDK {


  bool
  NeuralNetwork::load(String path) {

    FileStream file;
    file.m_file.open(path.c_str(), fstream::binary);

    if (!file.m_file.is_open()) {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Failed to load Neural Training information", 
                               LOGGER_LEVEL::ERRORED);
#endif
      Logger::instance().toConsole("Failed to load Neural Training information",
                                   LOGGER_LEVEL::ERRORED);
      return false;
    }

    uint32 layers = 0;
    file.m_file >> layers;

    return true;
  }

  bool
  NeuralNetwork::load(Path path) {

    FileStream* file = new FileStream();
    file->m_file.open(path.get().c_str(), fstream::binary);

    if (!file->m_file.is_open()) {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Failed to load Neural Training information",
                               LOGGER_LEVEL::ERRORED);
#endif
      Logger::instance().toConsole("Failed to load Neural Training information",
                                   LOGGER_LEVEL::ERRORED);
      return false;
    }


    return true;
  }

  bool
  NeuralNetwork::save() {
    
  }

  bool
  NeuralNetwork::saveAs(String fileName) {

  }

  void
  NeuralNetwork::init() {

  }

  void
  NeuralNetwork::clean() {

  }

  void
  NeuralNetwork::adjust() {

  }

  String
  NeuralNetwork::toString() {

  }

  void
  NeuralNetwork::operator<<(FileStream stream) {

  }

  void
  NeuralNetwork::operator<<(fstream stream) {

  }

  void
  NeuralNetwork::operator>>(FileStream stream) {

  }

  void
  NeuralNetwork::operator>>(fstream stream) {

  }
}