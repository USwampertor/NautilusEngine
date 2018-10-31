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

#include "nauPrerequisitesCore.h"

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

    virtual void
    getSize() = 0;

    virtual void
    setSize() = 0;

  private:

    uint32_t m_bufferSize;
    uint32_t m_numObjects;
  };

  class nauVertexBuffer : public nauGraphicsBuffer
  {
   public:

    /**
     * Default constructor
     */
    nauVertexBuffer() = default;


    virtual ~nauVertexBuffer() = 0;

    /**
     * @brief Reserves space in the vertex vector 
     * @param numObjects, the amount of object to allocate
     * @return 
     *
     */
    virtual void 
    reserve() = 0;

    /**
     * @brief Adds an object at the end of the vector
     * @param 
     * @return 
     *
     */
    virtual void 
    add() = 0;

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param 
     * @return 
     *
     */
    virtual void 
    clear() = 0;

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param Args
     * @return 
     *
     */
    virtual void 
    createHardware() = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param 
     * @return 
     *
     */
    virtual void 
    write() = 0;

  };

  
  class nauIndexBuffer : public nauGraphicsBuffer
  {
   public:

    /**
     * Default constructor
     */
    nauIndexBuffer() = default;

    virtual ~nauIndexBuffer() = 0;
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
    virtual void add() = 0;

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
    virtual void createHardware() = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param
     * @return
     *
     */
    virtual void write() = 0;


  private:

    /**
     * Vector of index data
     */
  };
  
  class nauConstantBuffer : public nauGraphicsBuffer
  {
   public:
    nauConstantBuffer() = default;

    /**
     * virtual dstructor
     */
    virtual ~nauConstantBuffer() = 0;

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
    virtual void add() = 0;

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
    virtual void createHardware() = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param
     * @return
     *
     */
    virtual void write() = 0;

  };
}
