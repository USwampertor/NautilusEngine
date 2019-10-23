/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNeuron.h
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief Neuron Simplest structure for IrinaIK
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauBone.h"

#include <nauDataStream.h>
#include <nauVector4.h>

namespace nauEngineSDK {
  using std::fstream;


/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauNeuron.h Forward declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

class NeuralLayer;

/**
 * Neuron
 * Description:
 * 	
 * Sample usage:
 * 	
 */
class Neuron
{
 public:
  /**
   * Default constructor
   */
  Neuron() = default;

  /**
   * Virtual default destructor
   */
  ~Neuron() = default;

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  init(uint32 newID);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  reset();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  Bone*
  get();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  String
  toString();

  /**
   * @brief Returns the weight of the neuron as a color, for display purposes
   * @param 
   * @return Vector4 a RGBA color
   *
   */
  Vector4
  toColor();

  /**
   * @brief operator << overloading to be used for serialization
   * @param 
   * @return 
   *
   */
  void 
  operator<<(FileStream stream);

  void
  operator<<(fstream stream);


  /**
   * @brief operator >> overloading to be used for serialization
   * @param 
   * @return 
   *
   */
  void 
  operator>>(FileStream stream);

  void
  operator>>(fstream stream);

  /**
   * Vertex used to store the info of the bones
   */
  Bone* m_data;

  /**
   * Id of the Neuron
   */
  uint32 m_ID;

  /**
   * Weight of the Neuron
   */
  float m_weight;

};

}