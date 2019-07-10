/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauModelNode.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/28 2019
 * @brief An aiNode Wrapper for animation transformations of a model
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include <nauMatrix4.h>

namespace nauEngineSDK {
struct ModelNode
{
  ModelNode() = default;

  ModelNode(const aiNode& other) {
    m_name = other.mName.C_Str();
    aiMatrix4x4 m = other.mTransformation;
    m_transformation.setValues(m.a1, m.b1, m.c1, m.d1,
                               m.a2, m.b2, m.c2, m.d2,
                               m.a3, m.b3, m.c3, m.d3,
                               m.a4, m.b4, m.c4, m.d4);
    if (other.mParent != nullptr) {
      m_parent = new ModelNode(*other.mParent);
    }
    for (int i = 0; i < other.mNumChildren; ++i) {
      m_children.push_back(new ModelNode(*other.mChildren[i]));
    }
  }

  ~ModelNode() = default;

  /**
   * Name of the model
   */
  String m_name;

  /**
   * Transformation matrix
   */
  Matrix4 m_transformation;

  /**
   * Parent Node
   */
  ModelNode* m_parent = nullptr;

  /**
   * Children nodes
   */
  Vector<ModelNode*> m_children;

};
}

