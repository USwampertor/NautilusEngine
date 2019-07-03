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

#include "nauPrerequisitesCore.h"

#include "nauCoreFactory.h"
#include "nauGraphicsBuffer.h"
#include "nauVertex.h"

namespace nauEngineSDK {

  class MaterialComponent;

   /**
    * nauMesh
    * Description:
    * 	a Mesh component from a model
    * Sample usage:
    * 	
    */
  class NAU_CORE_EXPORT Mesh
  {
   public:
    /**
     * Default constructor
     */
    Mesh() = default;

    Mesh(Device* dev) {
      m_vertexBuffer = dev->createVertexBuffer();
      m_indexBuffer = dev->createIndexBuffer();
    }

    /**
     * virtual destructor
     */
    ~Mesh() = default;

    /**
     * @brief renders the mesh in the given device context
     * @param void* usually a device
     * @return 
     *
     */
    void 
    draw(Device* dev);

  public:

    /**
     * vertex buffer
     */
    VertexBuffer* m_vertexBuffer = nullptr;
    
    /**
     * Index buffer
     */
    IndexBuffer* m_indexBuffer = nullptr;

    /**
     * Material embedded in the mesh
     */
    MaterialComponent* m_material = nullptr;

  };
  
}

