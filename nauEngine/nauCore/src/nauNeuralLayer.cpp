/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauNeuralLayer.cpp
 * @author Marco "Swampy" Millan
 * @date 10/22/2019
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauNeuralLayer.h"

#include "nauNeuron.h"

namespace nauEngineSDK {


void
NeuralLayer::operator<<(FileStream stream) {
  stream.m_file << m_ID << static_cast<int>(m_type) << m_data.size();
}

void
NeuralLayer::operator>>(FileStream stream) {
  SIZE_T layerSize = 0;
  uint32 layerType = 0;
  stream.m_file >> m_ID >> layerType >> layerSize;

  m_type = static_cast<NeuralLayerType::E>(layerType);
  for (uint32 i = 0; i < layerSize; ++i) {
    Neuron* tmp = new Neuron();
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

}