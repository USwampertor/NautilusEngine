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

  Vector<NeuralLayer*> m_layers;
};

