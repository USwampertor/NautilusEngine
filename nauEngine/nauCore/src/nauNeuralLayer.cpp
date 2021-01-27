/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauNeuralLayer.cpp
 * @author Marco "Swampy" Millan
 * @date 10/22/2019
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauNeuralLayer.h"

#include "nauNeuron.h"

namespace nauEngineSDK {


void
NeuralLayer::operator<<(FileStream& stream) {
  stream.m_file << m_ID << static_cast<int32>(m_type) << m_data.size();
  for (uint32 i = 0; i < m_data.size(); ++i) {
    m_data[i].write(stream);
  }
}

void
NeuralLayer::operator<<(fstream& stream) {
  stream << m_ID << static_cast<int32>(m_type) << m_data.size();
  for (uint32 i = 0; i < m_data.size(); ++i) {
    m_data[i].write(stream);
  }
}

void
NeuralLayer::write(FileStream& stream) {
  stream.m_file << m_ID << static_cast<int32>(m_type) << m_data.size();
  for (uint32 i = 0; i < m_data.size(); ++i) {
    m_data[i].write(stream);
  }
}

void
NeuralLayer::write(fstream& stream) {
  stream << m_ID << static_cast<int32>(m_type) << m_data.size();
  for (uint32 i = 0; i < m_data.size(); ++i) {
    m_data[i].write(stream);
  }
}

void
NeuralLayer::operator>>(FileStream& stream) {
  SIZE_T layerSize = 0;
  uint32 layerType = 0;
  stream.m_file >> m_ID >> layerType >> layerSize;

  m_type = static_cast<NeuralLayerType::E>(layerType);
  for (uint32 i = 0; i < layerSize; ++i) {
    Neuron tmp;
    tmp.read(stream);
    m_data.push_back(tmp);
  }
}

void
NeuralLayer::operator>>(fstream& stream) {
  SIZE_T layerSize = 0;
  uint32 layerType = 0;
  stream >> m_ID >> layerType >> layerSize;
  m_type = static_cast<NeuralLayerType::E>(layerType);

  for (uint32 i = 0; i < layerSize; ++i) {
    Neuron tmp;
    tmp.read(stream);
    m_data.push_back(tmp);
  }
}

void
NeuralLayer::read(FileStream& stream) {
  SIZE_T layerSize = 0;
  uint32 layerType = 0;
  stream.m_file >> m_ID >> layerType >> layerSize;
  m_type = static_cast<NeuralLayerType::E>(layerType);

  for (uint32 i = 0; i < layerSize; ++i) {
    Neuron tmp;
    tmp.read(stream);
    m_data.push_back(tmp);
  }
}

void
NeuralLayer::read(fstream& stream) {
  SIZE_T layerSize = 0;
  uint32 layerType = 0;
  stream >> m_ID >> layerType >> layerSize;
  m_type = static_cast<NeuralLayerType::E>(layerType);

  for (uint32 i = 0; i < layerSize; ++i) {
    Neuron tmp;
    tmp.read(stream);
    m_data.push_back(tmp);
  }
}

String
NeuralLayer::toString() {
  String toReturn;
  
  toReturn += "Neuron Layer ID: ";
  toReturn += std::to_string(m_ID);
  toReturn += "Layer Type: ";
  toReturn += std::to_string(static_cast<uint32>(m_type));
  toReturn += "\nNumber of neurons: ";
  toReturn += std::to_string(m_data.size());

  return toReturn;
}

Vector<Color>
NeuralLayer::toColor() {
  Vector<Color> layer;
  for (auto neuron : m_data) {
    layer.push_back(neuron.toColor());
  }
  return layer;
}

}