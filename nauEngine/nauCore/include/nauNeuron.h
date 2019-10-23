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

namespace nauEngineSDK {
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
  init();

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
   * @brief operator << overloading to be used for serialization
   * @param 
   * @return 
   *
   */
  void 
  operator<<(FileStream stream);

  /**
   * @brief operator >> overloading to be used for serialization
   * @param 
   * @return 
   *
   */
  void 
  operator>>(FileStream stream);

  /**
   * Vertex used to store the info of the bones
   */
  Bone m_data;

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