/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBone.h
 * @author Marco "Swampy" Millan
 * @date 2019/05/23 2019
 * @brief A bone wrapping object for animations
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauVertexWeight.h"

#include <nauMatrix4.h>

namespace nauEngineSDK {
   /**
    * nauBone
    * Description:
    *   A bone object for meshes to control vertex and animations
    * Sample usage:
    *   Without a bone you would be only flesh and goo in the floor
    */
  class Bone
  {
  public:
    /**
     * Default constructor
     */
    Bone() = default;

    /**
     * Default destructor
     */
    ~Bone() = default;

    /**
     * Name of the bone
     */
    String m_name;

    /**
     * the offset of the bone against the hierarchy to have its transformations 
     * in local space of the vertices
     */
    Matrix4 m_offset;

    /**
     * Vertex Weight
     */

  };
  
}

