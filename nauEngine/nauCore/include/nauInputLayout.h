/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauInputLayout.h
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
    * nauInputLayout
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class nauInputLayout
  {
   public:
    
    /**
     * Default constructor
     */
    nauInputLayout() = default;

    /**
     * virtual destructor
     */
    virtual ~nauInputLayout() {};

    /**
     * @brief sets the descriptor of the input
     * @param 
     * @return 
     *
     */
    virtual void
    setInputDescriptor() = 0;

    /**
     * @brief reserves the space inside the descriptor in general
     * @param size_t the size in number of objects
     * @return 
     *
     */
    virtual void
    reserve(SIZE_T numObjects) = 0;

    /**
     * @brief Adds an object to the vector descriptor
     * @param the object to insert
     * @return 
     *
     */
    virtual void
    add(void* input) = 0;

    /**
     * @brief gets the info from a BLOB in general, to set the values
     * @param 
     * @return 
     *
     */
    virtual void
    getfromBLOB(void* pReflection, SIZE_T size) = 0;

    /**
     * @brief clears the Input Descriptor
     * @param 
     * @return 
     *
     */
    virtual void
    clear() = 0;

    /**
     * @brief creates the input buffer with the shader given  
     * @param Device of the API and shader
     * @return 
     *
     */
    virtual void
    createInputBuffer(void* pDevice, void* pShader) = 0;

    /**
     * @brief sets the layout to the immediate context
     * @param the immediate context
     * @return 
     *
     */
    virtual void
    setLayout(void* pImmediateContext) = 0;

  };
  
}

