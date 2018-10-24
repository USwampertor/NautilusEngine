/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMesh.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief Mesh base class for 3d/2d object generation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

namespace nauEngineSDK {

   /**
    * nauMesh
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  class nauMesh
  {
   public:
    /**
     * Default constructor
     */
    nauMesh() = default;

    /**
     * virtual destructor
     */
    virtual ~nauMesh() = 0;
  };
  
}

