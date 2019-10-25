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
#include "nauPath.h"
#include "nauLogger.h"

#include <nauModule.h>
#include <nauVector4.h>

namespace nauEngineSDK {
  using std::fstream;

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
   * @param String the path to find the object
   * @return 
   *
   */
  bool
  load(String path);

  /**
   * @brief Loads the information stores previously in a database
   * @param 
   * @return 
   *
   */
  bool
  load(Path path);

  /**
   * @brief Saves the information of the neural network in the file 
   *        it was loaded from. If it is a new object, it will call save as
   * @param 
   * @return true if able to save
   *
   */
  bool
  save();

  /**
   * @brief Saves the object in a new file
   * @param String fileName the file to save
   * @return 
   *
   */
  bool
  saveAs(String fileName);

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

  /**
   * @brief returns the information of the network as a string
   * @param 
   * @return 
   *
   */
  String
  toString();

  /**
   * @brief returns the information of the neurons as an arrangement of colors
   * @param 
   * @return 
   *
   */
  Vector4
  toColor();

  /**
   * @brief Operator << for serialization
   * @param 
   * @return 
   *
   */
  void
  operator<<(FileStream stream);

  void
  operator<<(fstream stream);

  /**
   * @brief Operator >> for serialization
   * @param
   * @return
   *
   */
  void
  operator>>(FileStream stream);

  void
  operator>>(fstream stream);

 public:

  /**
   * The layers in this neural network
   */
  Vector<NeuralLayer*> m_layer;

  /**
   * A reference to a file if it has been loaded with
   */
  FileStream* m_file = nullptr;
};
}
