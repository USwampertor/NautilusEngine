/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauMeshDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/12/07 2018
 * @brief Mesh implemented in DirectX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"
#include <nauMesh.h>

namespace nauEngineSDK {
   /**
    * nauMeshDX
    * Description:
    * 	mesh implementation in DirectX context
    * Sample usage:
    * 	you can make a nice model with them
    */
  class nauMeshDX : public nauMesh
  {
  public:

    /**
     * Default constructor
     */
    nauMeshDX() = default;

    /**
     * Default destructor
     */
    ~nauMeshDX() {}

    void
    render(void* pDeviceContext);

  };
  
}

