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

