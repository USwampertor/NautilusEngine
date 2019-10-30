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

    m_file = new FileStream();
    m_file->m_file.open(path.c_str(), fstream::binary);

    if (!m_file->m_file.is_open()) {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Failed to load Neural Training information", 
                               LOGGER_LEVEL::ERRORED);
#endif
      Logger::instance().toConsole("Failed to load Neural Training information",
                                   LOGGER_LEVEL::ERRORED);
      return false;
    }

    uint32 layers = 0;
    m_file->m_file >> layers;

    for (uint32 i = 0; i < layers;  ++i) {
      NeuralLayer layer;
      layer.read(m_file->m_file);
      m_layers.push_back(layer);
    }

    m_file->m_file.close();
    return true;
  }

  bool
  NeuralNetwork::load(Path path) {

    m_file = new FileStream();
    m_file->m_file.open(path.getFullPath(), fstream::binary);

    if (!m_file->m_file.is_open()) {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Failed to load Neural Training information",
                               LOGGER_LEVEL::ERRORED);
#endif
      Logger::instance().toConsole("Failed to load Neural Training information",
                                   LOGGER_LEVEL::ERRORED);
      return false;
    }


    uint32 layers = 0;
    m_file->m_file >> layers;

    for (uint32 i = 0; i < layers; ++i) {
      NeuralLayer layer;
      layer.read(m_file->m_file);
      m_layers.push_back(layer);
    }
    m_file->m_file.close();

    return true;
  }

  bool
  NeuralNetwork::save() {
    if (m_file == nullptr) {
      String newName = "";
      newName.append(IRINA_FILE_EXTENSION);
      return saveAs(newName);
    }
    return saveAs(m_file->m_path);
  }

  bool
  NeuralNetwork::saveAs(String fileName) {

    m_file->m_file.open(fileName.c_str(), fstream::binary);

    if (!m_file->m_file.is_open()) {
#if NAU_DEBUG_MODE
      Logger::instance().toIDE("Failed to load Neural Training information",
        LOGGER_LEVEL::ERRORED);
#endif
      Logger::instance().toConsole("Failed to load Neural Training information",
        LOGGER_LEVEL::ERRORED);
      return false;
    }
    //Write the amount of layers it has
    m_file->m_file << m_layers.size();
    for (auto layer : m_layers) {
      layer.write(*m_file);
    }
    m_file->m_file.close();
    return true;
  }

  void
  NeuralNetwork::init() {

  }

  void
  NeuralNetwork::clean() {
    for (auto layer :  m_layers) {
      for (auto neuron : layer.m_data) {
        neuron.reset();
      }
    }
  }

  void
  NeuralNetwork::adjust() {
    for (auto layer : m_layers) {
      for (auto neuron : layer.m_data) {
      }
    }
  }

  String
  NeuralNetwork::toString() {
    String toReturn;
    toReturn += "Neural Network IrinaIK \n";
    toReturn += "Controlling model with ID: ";
    return toReturn;
  }


  Vector<Vector<Color>>
  NeuralNetwork::toColor() {
    Vector<Vector<Color>> matrix;
    for (auto layer : m_layers) {
      matrix.push_back(layer.toColor());
    }
    return matrix;
  }

  void
  NeuralNetwork::operator<<(FileStream& stream) {

  }

  void
  NeuralNetwork::operator<<(fstream& stream) {

  }

  void
  NeuralNetwork::write(FileStream& stream) {

  }

  void
  NeuralNetwork::write(fstream& stream) {

  }

  void
  NeuralNetwork::operator>>(FileStream& stream) {

  }

  void
  NeuralNetwork::operator>>(fstream& stream) {

  }

  void
  NeuralNetwork::read(FileStream& stream) {

  }
  void
  NeuralNetwork::read(fstream& stream) {

  }

}