/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauVertex.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/20 2018
 * @brief Vertex for rendering objects in space: has color position normals and uvs
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include <nauVector2.h>
#include <nauMatrix4.h>

#include <DirectXMath.h>

#include "nauPrerequisitesCore.h"
#include "nauBoneWeight.h"
#include "nauBone.h"

namespace nauEngineSDK {

/**
 * nauVertex
 * Description:
 * 	A vertex object
 * Sample usage:
 * 	vertex an be used to store information of the mesh
 */
struct Vertex
{
  Vertex() {
    m_position  = Vector4::ONEW;
    m_color     = Vector4::ZERO;
    m_normal    = Vector4::ONEW;
    m_uv        = Vector2::ZERO;
    m_tangent   = Vector3::ZERO;
    m_binormal  = Vector3::ZERO;
    m_IDs[0] = m_IDs[1] = m_IDs[2] = m_IDs[3] = -1;
  }


  Vertex(Vector4 position, Vector4 color, Vector4 normal, Vector2 uv)
    : m_position(position),
      m_color(color),
      m_normal(normal),
      m_uv(uv) {}

  /**
   * position of the vertex
   */
  Vector4 m_position;
  
  /**
   * color of the vertex
   */
  Vector4 m_color;

  /**
   * normals of the vertex
   */
  Vector4 m_normal;

  /**
   * U (UV's) component of the vertex
   */
  Vector2 m_uv;

  /**
   * Tangent
   */
  Vector3 m_tangent;

  /**
   * Bi normal Component
   */
  Vector3 m_binormal;

  /**
   * Bone IDs reference
   */
  int32 m_IDs[4];

  /**
   * Bone Weights
   */
  float m_weights[4];



};

}