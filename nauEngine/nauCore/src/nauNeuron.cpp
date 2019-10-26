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
    stream.m_file << m_ID << m_weight << m_data->m_ID;
    stream.m_file.write(reinterpret_cast<char*>(&m_data->m_offset), 
                        sizeof(Matrix4));

  }

  void
  Neuron::operator<<(fstream stream) {
    stream << m_ID << m_weight << m_data->m_ID;
    stream.write(reinterpret_cast<char*>(&m_data->m_offset),
                 sizeof(Matrix4));
  }

  void
  Neuron::write(FileStream stream) {
    stream.m_file << m_ID << m_weight << m_data->m_ID;
    stream.m_file.write(reinterpret_cast<char*>(&m_data->m_offset), 
                        sizeof(Matrix4));
  }

  void
  Neuron::write(fstream stream) {
    stream << m_ID << m_weight << m_data->m_ID;
    stream.write(reinterpret_cast<char*>(&m_data->m_offset),
                 sizeof(Matrix4));
  }

  void
  Neuron::operator>>(FileStream stream) {
    uint32 boneID = 0;
    Matrix4 boneOffset;
    stream.m_file >> m_ID >> m_weight >> boneID;
    stream.m_file.read(reinterpret_cast<char*>(&boneOffset), sizeof(Matrix4));
  }

  void
  Neuron::operator>>(fstream stream) {
    uint32 boneID = 0;
    Matrix4 boneOffset;
    stream >> m_ID >> m_weight >> boneID;
    stream.read(reinterpret_cast<char*>(&boneOffset), sizeof(Matrix4));
  }

  void
  Neuron::read(FileStream stream) {
    uint32 boneID = 0;
    Matrix4 boneOffset;

    stream.m_file >> m_ID >> m_weight >> boneID;
    stream.read(reinterpret_cast<char*>(&boneOffset), sizeof(Matrix4));

  }

  void
  Neuron::read(fstream stream) {
    uint32 boneID = 0;
    Matrix4 boneOffset;
    stream >> m_ID >> m_weight >> boneID;
    stream.read(reinterpret_cast<char*>(&boneOffset), sizeof(Matrix4));
  }
  
}