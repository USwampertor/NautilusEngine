/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNeuralLayer.h
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief Neural Layer Object for 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include <nauDataStream.h>


namespace nauEngineSDK {
class Neuron;

/**
 * NeuralLayer
 * Description:
 *  Neural Layer in charge to hold a specific amount of neurons,
 *  connect to other neurons and generate a final value for the network
 * Sample usage:
 * 	
 */
class NeuralLayer
{
public:
  /**
   * Default constructor
   */
  NeuralLayer() = default;

  /**
   * Default destructor
   */
  ~NeuralLayer() = default;

  /**
   * @brief Returns the layer to string
   * @param 
   * @return 
   *
   */
  String
  toString();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void 
  operator<<(FileStream stream);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void 
  operator>>(FileStream stream);

public:

  /**
   * List of neurons in the layer
   */
  Vector<Neuron*> m;

  /**
   * Pointer to the next layer
   */
  NeuralLayer* m_next;

};

}

