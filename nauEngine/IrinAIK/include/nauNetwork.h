/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNetwork.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/19 2019
 * @brief The network that generates procedural animation adaption
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauNeuralLayer.h"
#include <vector>

namespace nauEngineSDK {
class NeuralNetwork
{
public:
  /**
   * Default Constructor
   */
  NeuralNetwork() = default;

  /**
   * Default destructor
   */
  ~NeuralNetwork() = default;

  /**
   * Initializes the neural network
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
  clean();

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void
  adjust();

  std::vector<NeuralLayer*> m_layers;


};
}

