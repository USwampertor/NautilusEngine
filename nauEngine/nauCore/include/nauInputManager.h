/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputManager.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/23 2019
 * @brief Input Manager
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauModule.h"

namespace nauEngineSDK {
  class InputManager : public Module<InputManager>
  {
  public:
    /**
     * Default constructor
     */
    InputManager() = default;

    /**
     * Default destructor
     */
    ~InputManager() = default;
  };
  
}


