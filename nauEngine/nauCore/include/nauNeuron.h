/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauNeuron.h
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief Neuron Simplest structure for IrinaIK
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauBone.h"


namespace nauEngineSDK {
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * nauNeuron.h Forward declaration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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