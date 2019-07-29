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

#include <assimp/config.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <nauMatrix4.h>

namespace nauEngineSDK {
/**
 * nauBone
 * Description:
 *   A bone object for meshes to control vertex and animations
 * Sample usage:
 *   Without a bone you would be only flesh and goo in the floor
 */
struct Bone
{
  Bone() = default;

  ~Bone() = default;

  Bone(const aiBone& other) {
    m_name = other.mName.C_Str();
    m_weights.resize(other.mNumWeights);
    aiMatrix4x4 m = other.mOffsetMatrix;
    m_offset.setValues(m.a1, m.b1, m.c1, m.d1,
                       m.a2, m.b2, m.c2, m.d2,
                       m.a3, m.b3, m.c3, m.d3,
                       m.a4, m.b4, m.c4, m.d4);
  }


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
   * ID of the bone in the tree
   */
  int m_ID;

  /**
   * Vertex Weight
   */
  Vector<VertexWeight*> m_weights;

  /**
   * The parent of the bone
   */
  Bone* m_parent = nullptr;

  /**
   * List of children
   */
  Vector<Bone*> m_children;
};
  
}

