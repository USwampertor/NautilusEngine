/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file h
 * @author Marco "Swampy" Millan
 * @date 2018/10/17 2018
 * @brief Random number generator classes, father and children:
 *  Ziggurat, Montecarlo and BoxMueller
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once
#include "nauMath.h"
#include <time.h>
#include "nauPrerequisitesUtil.h"
namespace nauEngineSDK {


  /**
   * nauRandom
   * Description:
   * 	Random father class
   * Sample usage:
   * 	list<nauRandom*> lets you have a list of all different children
   */
  class nauRandom
  {
   public:
    
    /**
     * Default constructor
     */
    nauRandom() = default;

    /**
     * Seed defining constructor
     */
    nauRandom(float nSeed) : m_seed(nSeed) {}

    /**
     * @brief Initializes the seed based in the current time
     * overrides the seed if the class was constructed with one
     * @param 
     * @return 
     *
     */
    void
    initialize() { m_seed = static_cast<float>(time(0)); }

    /**
     * @brief calculate a new random and sets it as the next seed
     * This is the virtual function so each child does its own calculation
     * @param 
     * @return the calculated random number
     *
     */
    virtual float
    next() = 0;

   public:
    /**
     * The seed to generate random numbers
     */
    float m_seed;

  };


  /**
   * nauRandomZ
   * Description:
   * 	Ziggurat algorithm random number generator
   * Sample usage:
   * 	
   */
  class nauRandomZ : public nauRandom
  {
   public:
  
    /**
     * Default Constructor
     */
    nauRandomZ() = default;
  
    /**
     * @brief Constructor with a seed generated by the user, a mean or a deviation
     * @param seed the seed to start, deviation = 1 as default, mean = 0 as default
     * @return a created RandomZ object
     *
     */
    nauRandomZ(float seed, float deviation = 1.0f, float mean = 0.0f) 
      : nauRandom(seed),
        m_deviation(deviation),
        m_mean(mean) {}
    
    /**
     * @brief calculate a new random and sets it as the next seed
     * @param
     * @return the calculated random number
     *
     */
    float 
    next();

   public:
 
    /**
     * the deviation of the Gaussian distribution
     */
    float m_deviation;

    /**
     * The mean of the Gaussian distribution
     */
    float m_mean;
  };
  
  class nauRandomMC : public nauRandom
  {
   public:

    /**
     * Default constructor
     */
    nauRandomMC() = default;

    /**
     * Seeded constructor
     */
    nauRandomMC(float seed) : nauRandom(seed) {}

    /**
     * @brief calculate a new random and sets it as the next seed
     * @param
     * @return the calculated random number
     *
     */
    float
    next();

  };

  class nauRandomBM : public nauRandom
  {
   public:

    /**
     * Default constructor
     */
    nauRandomBM() = default;

    /**
     * Seeded constructor
     */
    nauRandomBM(float seed) : nauRandom(seed) {}

    /**
     * @brief calculate a new random and sets it as the next seed
     * @param
     * @return the calculated random number
     *
     */
    float
    next();

    /**
     * @brief Overridden function to initialize the two random floats with time
     * @param 
     * @return 
     *
     */
    void
    initialize();

   public:

     /**
      * one of the two randoms generated normally within the equation
      */
     float m_z1;

     /**
      * one of the two randoms generated normally within the equation
      */
     float m_z2;

     /**
      * checks if there is already another random generated and sends it instead
      * of generating some new pair of values
      */
     bool m_inquery;
  };
  
}
