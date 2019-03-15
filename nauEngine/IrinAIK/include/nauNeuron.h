/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauNeuron.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/14 2019
 * @brief Neuron for the neural Network for the Kinematics Project
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


namespace nauEngineSDK {

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
     * Default Constructor
     */
    Neuron() = default;
    
    /**
     * Default destructor
     */
    ~Neuron() = default;

    /**
     * @brief Get the weight stored
     * @param 
     * @return the weight of the neuron
     *
     */
    float
    getWeight();

    /**
     * @brief Encapsulates an operation to get the output value
     * @param 
     * @return the result
     *
     */
    float
    calculate();

  private:
    
    /**
     * Weight of the neuron
     */
    float weight;

  };
  
}

