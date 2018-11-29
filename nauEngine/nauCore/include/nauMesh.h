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

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "nauPrerequisitesCore.h"

#include "nauGraphicsBuffer.h"
#include "nauTexture.h"
#include "nauVertex.h"


namespace nauEngineSDK {

   /**
    * nauMesh
    * Description:
    * 	a Mesh component from a model
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT nauMesh
  {
   public:
    /**
     * Default constructor
     */
    nauMesh() = default;

    /**
     * virtual destructor
     */
    virtual ~nauMesh() {}

    /**
     * @brief renders the mesh in the given device context
     * @param void* usually a device context
     * @return 
     *
     */
    virtual void 
    render(void* pDeviceContext) = 0;

  public:

    /**
     * vertex buffer
     */
    nauVertexBuffer* m_vertexBuffer;
    
    /**
     * Index buffer
     */
    nauIndexBuffer* m_indexBuffer;

    /**
     * Texture of mesh
     * This is temporal, it should have a material instead
     */
    nauTexture* m_texture;

  };
  
}

