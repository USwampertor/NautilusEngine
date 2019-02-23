/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauShaderResourceView.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

   /**
    * nauShaderResourceView
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT ShaderResourceView
  {
   public:

    /**
     * Default constructor
     */
    ShaderResourceView() = default;
    
    /**
     * virtual destructor
     */
    virtual ~ShaderResourceView() {}

    /**
     * @brief Creates a shader resource view
     * @param void* device
     * @return true if able to create
     *
     */
    virtual bool
    createShaderResourceView(void* pDevice) = 0;

    /**
     * @brief Creates a shader resource view
     * @param void* device
     * @return
     *
     */
    virtual void
    setShaderResourceView(void* pDevice) = 0;

  };
  
}

