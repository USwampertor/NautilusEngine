/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCoreFactory.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/14 2019
 * @brief Core Factory for creation of Graphic objects for plugin calling
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauModule.h"

namespace nauEngineSDK {
   /**
    * CoreFactory
    * Description:
    *   Its used to create Objects for Graphics Plugin
    * Sample usage:
    *   Create Sampler creates a PLUGIN-specific sampler
    */
  class CoreFactory : public Module <CoreFactory>
  {
  public:
    /**
     * Default Constructor
     */
    CoreFactory() = default;
  
    /**
     * Default destructor
     */
    ~CoreFactory() = default;

    /**
     * @brief Creates a 
     * @param 
     * @return 
     *
     */

  };
  
}

