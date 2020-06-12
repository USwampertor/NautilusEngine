/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCapsule.h
 * @author Marco "Swampy" Millan
 * @date 6/11/2020
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


#include "nauPrerequisitesUtil.h"


namespace nauEngineSDK {

  /**
   * 
   * Description:
   * 	
   * Sample usage:
   * 	
   */
  class Capsule
  {
  public:
    /**
     * Default Constructor
     */
    Capsule() = default;


    /**
     * Default destructor
     */
    ~Capsule() = default;


    bool
    collidingSphere(const Capsule& other) {

    }

  };

}