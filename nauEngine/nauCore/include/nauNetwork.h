/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNetwork.h
 * @author Marco "Swampy" Millan
 * @date 10/17/2019
 * @brief NeuralNetwork is the main file of the IrinaIK Neural Network System for
 *        3d animation correction in video games. This project is intended to 
 *        generate a neural network that can handle animations and muscles that
 *        correct the animation to handle terrain and stimulus from the level.
 *        Files with the training of the neural network have the extension ".irn"
 *        The project creates a neural network based on the amount of bones the
 *        model 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauLogger.h"

#include "nauNeuralLayer.h"
#include "nauNeuron.h"

#include "nauPath.h"

#include <nauModule.h>
#include <nauVector4.h>

#define IRINA_FILE_EXTENSION ".irn"

#define IRINA_MAX_BONES 64

namespace nauEngineSDK {

  //Forward declaration
  class Skeleton;

  using std::fstream;

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
  init(Skeleton skeleton);

  /**
   * @brief Processes the skeleton 
   * @param Bone* actual bone 
   * @return 
   *
   */
  void
  processSkeleton(NeuralLayer layer, Bone* actualBone);

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
   * @brief returns the information of the neurons as an arrangement of color matrix
   * @param 
   * @return Vector<Vector<Color>> matrix of colors by layer and amount of neurons
   *
   */
  Vector<Vector<Color>>
  toColor();

  /**
   * @brief Operator << for serialization
   * @param FileStream stream
   * @return 
   *
   */
  void
  operator<<(FileStream& stream);

  /**
   * @brief Operator << for serialization
   * @param fstream stream
   * @return
   *
   */
  void
  operator<<(fstream& stream);

  /**
   * @brief Writing function for the Neural network to stream information to a file
   * @param FileStream stream
   * @return 
   *
   */
  void
  write(FileStream& stream);

  /**
   * @brief Writing function for the Neural Network to stream information to a file
   * @param fstream stream
   * @return 
   *
   */
  void
  write(fstream& stream);

  /**
   * @brief Operator >> for serialization
   * @param FileStream stream
   * @return
   *
   */
  void
  operator>>(FileStream& stream);

  /**
   * @brief Operator >> for serialization
   * @param fstream stream 
   * @return
   *
   */
  void
  operator>>(fstream& stream);

  /**
   * @brief Reading function for the Neural Network to stream information to a network
   * @param FileStream stream
   * @return 
   *
   */
  void
  read(FileStream& stream);

  /**
   * @brief Reading function for the Neural Network to stream information to a network
   * @param fstream stream
   * @return 
   *
   */
  void
  read(fstream& stream);

 public:

  /**
   * The layers in this neural network
   */
  Vector<NeuralLayer> m_layers;

  /**
   * A reference to a file if it has been loaded with
   */
  FileStream* m_file = nullptr;
};
}
