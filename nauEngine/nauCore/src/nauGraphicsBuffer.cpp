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
  nauVertexBuffer::size() {
    return m_vertexData.size();
  }

  void
  nauVertexBuffer::reserve(SIZE_T numObjects) {
    m_vertexData.reserve(numObjects);
  }

  void
  nauVertexBuffer::add(const Vertex& vertex) {
    m_vertexData.push_back(vertex);
  }

  void
  nauVertexBuffer::add(Vector<Vertex>& vertices) {
    m_vertexData.insert(m_vertexData.end(), vertices.begin(), vertices.end());
  }

  void
  nauVertexBuffer::clear() {
    m_vertexData.clear();
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBuffer.cpp Index buffer 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  SIZE_T
  nauIndexBuffer::size() {
    return m_indexData.size();
  }

  void
  nauIndexBuffer::reserve(SIZE_T numObjects) {
    m_indexData.reserve(numObjects);
  }

  void
  nauIndexBuffer::add(const uint32& index) {
    m_indexData.push_back(index);
  }

  void
  nauIndexBuffer::add(Vector<uint32>& indices) {
    m_indexData.insert(m_indexData.end(), indices.begin(), indices.end());
  }

  void
  nauIndexBuffer::clear() {
    m_indexData.clear();
  }

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * nauGraphicsBuffer.cpp Constant Buffer declaration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

  SIZE_T
  nauConstantBuffer::size() {
    return m_constantData.size();
  }

  void
  nauConstantBuffer::reserve(SIZE_T numObjects) {
    m_constantData.reserve(numObjects);
  }

  void
  nauConstantBuffer::add(const Vector<char>& object) {
    m_constantData.push_back(object);
  }

  void
  nauConstantBuffer::add(Vector<Vector<char>>& objects) {
    m_constantData.insert(m_constantData.end(), objects.begin(), objects.end());
  }

  void
  nauConstantBuffer::clear() {
    m_constantData.clear();
  }

}
