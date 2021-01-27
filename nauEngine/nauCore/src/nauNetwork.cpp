/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauNetwork.cpp
 * @author Marco "Swampy" Millan
 * @date 10/22/2019
 * @brief Neural Network
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauNetwork.h"

#include "nauSkeleton.h"

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
  NeuralNetwork::init(Sptr<Skeleton> skeleton) {

    NeuralLayer base;
    NeuralLayer firstHidden;
    NeuralLayer secondHidden;
    NeuralLayer output;

   for (auto bone : skeleton->getRoot()->m_children ) {
     Neuron neuron;
     neuron.m_data = bone;
     base.m_data.push_back(neuron);
     processSkeleton(base, bone);
   }

   firstHidden = secondHidden = output = base;

   m_layers.push_back(base);
   m_layers.push_back(firstHidden);
   m_layers.push_back(secondHidden);
   m_layers.push_back(output);

   for (uint32 i = 0; i < m_layers.size() - 1; ++i) {
     m_layers[i].m_next = &m_layers[i + 1];
   }

   for (auto layer : m_layers) {
     for (auto neuron : layer.m_data) {
       neuron.m_weight;
     }
   }

  }

  void
  NeuralNetwork::processSkeleton(NeuralLayer layer, Bone* actualBone) {
    for (auto child : actualBone->m_children) {
      Neuron neuron;
      neuron.m_data = child;
      layer.m_data.push_back(neuron);
      if (child->m_children.size() > 0) { processSkeleton(layer, child); }
    }
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
    UNREFERENCED_PARAMETER(stream);
  }

  void
  NeuralNetwork::operator<<(fstream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }

  void
  NeuralNetwork::write(FileStream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }

  void
  NeuralNetwork::write(fstream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }

  void
  NeuralNetwork::operator>>(FileStream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }

  void
  NeuralNetwork::operator>>(fstream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }

  void
  NeuralNetwork::read(FileStream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }
  void
  NeuralNetwork::read(fstream& stream) {
    UNREFERENCED_PARAMETER(stream);
  }

}