/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBoneNeuron.cpp
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief IrinaIK Neuron Implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauNeuron.h"

namespace nauEngineSDK {

  void
  Neuron::init(uint32 newID) {
    m_ID = newID;
    m_weight = 0.0f;
  }

  void
  Neuron::reset() {
    m_weight = 0;
  }

  Bone*
  Neuron::get() {
    return m_data;
  }

  String
  Neuron::toString() {
    String toReturn;
    toReturn += "Neuron ID: ";
    toReturn += std::to_string(m_ID);
    toReturn += "\nWeight: ";
    toReturn += std::to_string(m_weight);

    return toReturn;
  }

  void
  Neuron::operator<<(FileStream stream) {
    stream.m_file << m_ID << m_weight;
  }

  void
  Neuron::operator<<(fstream stream) {
    stream << m_ID << m_weight;
  }


  void
  Neuron::operator>>(FileStream stream) {
    stream.m_file >> m_ID >> m_weight;
  }

  void
  Neuron::operator>>(fstream stream) {
    stream >> m_ID >> m_weight;
  }
  
}