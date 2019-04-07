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
#include "nauShader.h"
#include "nauDevice.h"

namespace nauEngineSDK {
   /**
    * nauInputLayout
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class InputLayout
  {
   public:
    
    /**
     * Default constructor
     */
    InputLayout() = default;

    /**
     * virtual destructor
     */
    virtual ~InputLayout() = default;

    /**
     * @brief sets the descriptor of the input
     * @param 
     * @return 
     *
     */
    virtual void
    setInputDescriptor() = 0;

    //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
    virtual void
    setVertex() = 0;

    //TODO: DELETE THIS FUNCTION TO USE THE BLOB ONE
    virtual void
    setColor() = 0;

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
     * @brief gets the info from a reflected BLOB in general, to set the values in the layout
     * @param the BLOB with all the info, the size of the object
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
    createInputBuffer(Device* pDevice, Shader* pShader) = 0;

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

