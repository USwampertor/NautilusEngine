/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNetwork.h
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief Neural Network System for IrinaIK project
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauNeuralLayer.h"
#include <nauModule.h>

namespace nauEngineSDK {


class NeuralNetwork : public Module<NeuralNetwork>
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
   * @brief Loads the information stored previously in a database
   * @param 
   * @return 
   *
   */
  void
  load(String path);

  /**
   * @brief Initializes the neural network. Should be used only once tho
   * @param 
   * @return 
   *
   */
  void
  init();

  /**
   * @brief Cleans and resets the information from the neural network. Should NOT
   *        be used unless its super necessary.
   * @param
   * @return
   *
   */
  void
  clean();

  /**
   * @brief Adjusts the network given a series of values inside the system.
   * @param
   * @return
   *
   */
  void
  adjust();

 public:
  Vector<NeuralLayer*> m_layer;
};
}
