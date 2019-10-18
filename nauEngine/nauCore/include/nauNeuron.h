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
   * Virtual Neuron Initialization
   */
  void
  init();

  /**
   * Neuron Reset
   */
  void
  reset();

  /**
   * 
   */
  Bone*
  get();

  /**
   * Pointer to another 
   */
  Vector<NeuralLayer*> m_nextLayer;

  /**
   * Vertex used to store the info of the bones
   */
  Bone m;
};

}