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

#include "nauColor.h"

#include <nauDataStream.h>


namespace nauEngineSDK {
  using std::fstream;

namespace NeuralLayerType
{
  enum E
  {
    NONE      = 0,
    HIDDEN    = 1,
    EXPOSED   = 2,
    INPUT     = 3,
    OUTPUT    = 4
  };
}

  
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
   * @brief Returns the layer as a vector of Color struct
   * @param 
   * @return Vector<Color>
   *
   */
  Vector<Color>
  toColor();

  /**
   * @brief Writing operator for the neural layer
   * @param FileStream stream
   * @return 
   *
   */
  void 
  operator<<(FileStream& stream);

  /**
   * @brief Writing operator for the neural layer
   * @param fstream stream
   * @return 
   *
   */
  void 
  operator<<(fstream& stream);

  /**
   * @brief Write function to get information from the layer to the stream
   * @param FileStream stream
   * @return 
   *
   */
  void
  write(FileStream& stream);

  /**
   * @brief Write function to get information from the layer to the stream
   * @param fstream stream
   * @return 
   *
   */
  void
  write(fstream& stream);

  /**
   * @brief Reading operator >> for neural layer stream
   * @param FileStream stream
   * @return 
   *
   */
  void 
  operator>>(FileStream& stream);

  /**
   * @brief Reading operator >> for neural layer stream
   * @param fstream stream
   * @return 
   *
   */
  void 
  operator>>(fstream& stream);

  /**
   * @brief Reading function to insert information in the neural layer 
   * @param FileStream stream
   * @return 
   *
   */
  void
  read(FileStream& stream);

  /**
   * @brief Reading function to insert information in the neural layer
   * @param fstream stream
   * @return 
   *
   */
  void
  read(fstream& stream);

public:

  /**
   * List of neurons in the layer
   */
  Vector<Neuron> m_data;

  /**
   * Pointer to the next layer
   */
  NeuralLayer* m_next;

  /**
   * ID of the layer
   */
  uint32 m_ID;

  /**
   * type of the layer
   */
  NeuralLayerType::E m_type;

};

}

