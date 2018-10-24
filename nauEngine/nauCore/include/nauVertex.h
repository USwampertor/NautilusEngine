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

namespace nauEngineSDK {

   /**
    * nauVertex
    * Description:
    * 	
    * Sample usage:
    * 	
    */
  struct nauVertex
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