/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauBoneNeuron.cpp
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief IrinaIK Neuron Implementation
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauNeuron.h"

namespace nauEngineSDK {

  void
  Neuron::init() {

  }

  void
  Neuron::reset() {

  }

  Bone*
  Neuron::get() {

  }

  String
  Neuron::toString() {
    String toReturn;
    toReturn += "Neuron: ID: ";
    toReturn += std::to_string(m_ID);
    toReturn += " Weight: ";
    toReturn += std::to_string(m_weight);
  }

  void
  Neuron::operator<<(FileStream stream) {
    stream.m_file << m_ID << m_weight;
  }

  void
  Neuron::operator>>(FileStream stream) {
    
  }

  
}