/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsBuffer.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/18 2018
 * @brief Container for all graphic buffers: Vertex, index, Constant
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include <nauStdHeaders.h>

namespace nauEngineSDK {
  /**
   * nauGraphics
   * Description:
   * 	the ABSTRACT father of the vertex, index and constant buffer for 
   *   rendering information. The object is implemented by the plugins
   * Sample usage:
   * 	Graphics buffer can be a DirectX buffer or OpenGL
   */
  class nauGraphicsBuffer
  {
   public:

     /**
      * default constructor
      */
    nauGraphicsBuffer() = default;

    /**
     * virtual destructor
     */
    virtual ~nauGraphicsBuffer() = 0;
  };

  template<typename TVERTEX, typename... Args>
  class nauVertexBuffer : public nauGraphicsBuffer
  {
   public:

    /**
     * Default constructor
     */
    nauVertexBuffer() = default;

    /**
     * @brief Reserves space in the vertex vector 
     * @param numObjects, the amount of object to allocate
     * @return 
     *
     */
    virtual void reserve(size_t numObjects) = 0;

    /**
     * @brief Adds an object at the end of the vector
     * @param 
     * @return 
     *
     */
    virtual void add(const TVERTEX& vertex) = 0;

    /**
     * @brief Adds a vector of objects at the end of the vector
     * @param vertices the vector of objects
     * @return 
     *
     */
    virtual void add(Vector<TVERTEX&> vertices) = 0;

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param 
     * @return 
     *
     */
    virtual void clear() = 0;

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param Args
     * @return 
     *
     */
    virtual void createHardware(Args... args) = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param 
     * @return 
     *
     */
    virtual void write(Args... args) = 0;

  private:

    /**
     * Vector of vertex data
     */
    Vector<TVERTEX> m_vertexData;
  };

  template<typename TINDEX, typename... Args>
  class nauIndexBuffer : public nauGraphicsBuffer
  {
   public:

    /**
     * Default constructor
     */
    nauIndexBuffer() = default;

    /**
  * @brief Reserves space in the vertex vector
  * @param numObjects, the amount of object to allocate
  * @return
  *
  */
    virtual void reserve(size_t numObjects) = 0;

    /**
     * @brief Adds an object at the end of the vector
     * @param
     * @return
     *
     */
    virtual void add(const TINDEX& vertex) = 0;

    /**
     * @brief Adds a vector of objects at the end of the vector
     * @param vertices the vector of objects
     * @return
     *
     */
    virtual void add(Vector<TINDEX&> vertices) = 0;

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param
     * @return
     *
     */
    virtual void clear() = 0;

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param Args
     * @return
     *
     */
    virtual void createHardware(Args... args) = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param
     * @return
     *
     */
    virtual void write(Args... args) = 0;


  private:

    /**
     * Vector of index data
     */
    Vector<TINDEX> m_indexData;

  };
  
  template<typename TCONSTANT, typename... Args>
  class nauConstantBuffer : public nauGraphicsBuffer
  {
   public:
    nauConstantBuffer() = default;

    /**
     * @brief Reserves space in the vertex vector
     * @param numObjects, the amount of object to allocate
     * @return
     *
     */
    virtual void reserve(size_t numObjects) = 0;

    /**
     * @brief Adds an object at the end of the vector
     * @param
     * @return
     *
     */
    virtual void add(const TCONSTANT& vertex) = 0;

    /**
     * @brief Adds a vector of objects at the end of the vector
     * @param vertices the vector of objects
     * @return
     *
     */
    virtual void add(Vector<TCONSTANT&> vertices) = 0;

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param
     * @return
     *
     */
    virtual void clear() = 0;

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param Args
     * @return
     *
     */
    virtual void createHardware(Args... args) = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param
     * @return
     *
     */
    virtual void write(Args... args) = 0;

   private:
    
    /**
     * Constant data buffer
     */
    Vector<TCONSTANT> m_constantData;

  };
}
