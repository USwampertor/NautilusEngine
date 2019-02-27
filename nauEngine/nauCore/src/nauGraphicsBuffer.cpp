/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsBuffer.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/21 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauGraphicsBuffer.h"


namespace nauEngineSDK {

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBuffer.cpp Vertex member definition
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  SIZE_T
  VertexBuffer::size() {
    return m_vertexData.size();
  }

  void
  VertexBuffer::reserve(SIZE_T numObjects) {
    m_vertexData.reserve(numObjects);
  }

  void
  VertexBuffer::add(const Vertex& vertex) {
    m_vertexData.push_back(vertex);
  }

  void
  VertexBuffer::add(Vector<Vertex>& vertices) {
    m_vertexData.insert(m_vertexData.end(), vertices.begin(), vertices.end());
  }

  void
  VertexBuffer::clear() {
    m_vertexData.clear();
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBuffer.cpp Index buffer 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  SIZE_T
  IndexBuffer::size() {
    return m_indexData.size();
  }

  void
  IndexBuffer::reserve(SIZE_T numObjects) {
    m_indexData.reserve(numObjects);
  }

  void
  IndexBuffer::add(const uint32& index) {
    m_indexData.push_back(index);
  }

  void
  IndexBuffer::add(Vector<uint32>& indices) {
    m_indexData.insert(m_indexData.end(), indices.begin(), indices.end());
  }

  void
  IndexBuffer::clear() {
    m_indexData.clear();
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBuffer.cpp Constant Buffer declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  SIZE_T
  ConstantBuffer::size() {
    return m_constantData.size();
  }

  void
  ConstantBuffer::reserve(SIZE_T numObjects) {
    m_constantData.reserve(numObjects);
  }

  void
  ConstantBuffer::add(const Vector<char>& object) {
    m_constantData.push_back(object);
  }

  void
  ConstantBuffer::add(Vector<Vector<char>>& objects) {
    m_constantData.insert(m_constantData.end(), objects.begin(), objects.end());
  }

  void
  ConstantBuffer::clear() {
    m_constantData.clear();
  }

}
