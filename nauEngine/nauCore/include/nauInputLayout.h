/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file nauInputLayout.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief 
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
#pragma once

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
    setInputDescriptor();



  };
  
}

