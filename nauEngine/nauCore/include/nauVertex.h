/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVertex.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/20 2018
 * @brief Vertex for rendering objects in space: has color position normals and uvs
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


#include <nauVector4.h>

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

   /**
    * nauVertex
    * Description:
    * 	A vertex object
    * Sample usage:
    * 	vertex an be used to store information of the mesh
    */
  struct NAU_CORE_EXPORT nauVertex
  {
    
    /**
     * position of the vertex
     */
    nauVector4 m_position;
    
    /**
     * color of the vertex
     */
    nauVector4 m_color;

    /**
     * normals of the vertex
     */
    nauVector4 m_normal;

    /**
     * U (UV's) component of the vertex
     */
    float m_u;

    /**
     * V (UV's) component of the vertex
     */
    float m_v;

  };

}