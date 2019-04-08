/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauGraphicsBuffer.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/18 2018
 * @brief Container for all graphic buffers: Vertex, index, Constant
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesCore.h"
#include "nauVertex.h"

namespace nauEngineSDK {
  /**
   * nauGraphics
   * Description:
   * 	the ABSTRACT father of the vertex, index and constant buffer for 
   *   rendering information. The object is implemented by the plug ins
   * Sample usage:
   * 	Graphics buffer can be a DirectX buffer or OpenGL
   */
  class NAU_CORE_EXPORT GraphicsBuffer
  {
   public:

    /**
     * default constructor
     */
    GraphicsBuffer() = default;

    /**
     * virtual destructor
     */
    virtual ~GraphicsBuffer() {}

  };

  class NAU_CORE_EXPORT VertexBuffer : public GraphicsBuffer
  {
   public:

    /**
     * Default constructor
     */
    VertexBuffer() = default;

    /**
     * Virtual destructor
     */
    virtual ~VertexBuffer() {}

    /**
     * @brief returns the size of the vector of vertex
     * @param 
     * @return 
     *
     */
    SIZE_T
    size();


    /**
     * @brief Reserves space in the vertex vector 
     * @param numObjects, the amount of object to allocate
     * @return 
     *
     */
    void 
    reserve(SIZE_T numObjects);

    /**
     * @brief Adds an object at the end of the vector
     * @param 
     * @return 
     *
     */
    void 
    add(const Vertex& vertex);

    /**
     * @brief Adds a vector to the vector of objects inside
     * @param vector of vertices
     * @return
     *
     */
    void
    add(Vector<Vertex>& vertices);

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param 
     * @return 
     *
     */
    void 
    clear();

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param device and usage
     * @return 
     *
     */
    virtual void 
    createHardware(void* pDevice, uint32 usage) = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param 
     * @return 
     *
     */
    virtual void 
    write(void* pDevice, void* pData, SIZE_T numBytes) = 0;

    /**
     * Sets the device Context with the buffer
     */
    virtual void
    set(void* pDevice) = 0;

   public:
    
    /**
     * vertex vector
     */
    Vector<Vertex> m_vertexData;

  };

  class NAU_CORE_EXPORT IndexBuffer : public GraphicsBuffer
  {
   public:

    /**
     * Default constructor
     */
    IndexBuffer() = default;

    /**
     * virtual destructor
     */
    virtual ~IndexBuffer() {}

    /**
     * @brief returns the size of the vector
     * @param 
     * @return the size in bytes 
     *
     */
    SIZE_T
    size();

    /**
     * @brief Reserves space in the vertex vector
     * @param numObjects, the amount of object to allocate
     * @return
     *
     */
    void 
    reserve(SIZE_T numObjects);

    /**
     * @brief Adds an object at the end of the vector
     * @param
     * @return
     *
     */
    void
    add(const uint32& index);

    /**
     * @brief Adds a vector to the vector of objects inside
     * @param vector of INDEXES
     * @return 
     *
     */
    void 
    add(Vector<uint32>& indices);

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param
     * @return
     *
     */
    void 
    clear();

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param device and usage of the hardware
     * @return
     *
     */
    virtual void 
    createHardware(void* pDevice, uint32 usage) = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param device
     * @return
     *
     */
    virtual void 
    write(void* pDevice, void* pData, SIZE_T numBytes) = 0;

    /**
     * Sets the device Context with the buffer
     */
    virtual void
    set(void* pDevice) = 0;

   public:

    /**
     * index data
     */
    Vector<uint32> m_indexData;

  };
  
  class NAU_CORE_EXPORT ConstantBuffer : public GraphicsBuffer
  {
   public:

    /**
     * default constructor
     */
    ConstantBuffer() = default;

    /**
     * virtual destructor
     */
    virtual ~ConstantBuffer() {}

    /**
     * @brief returns the size of the vector of vertex
     * @param
     * @return the size of the buffer
     *
     */
    SIZE_T
    size();

    /**
     * @brief Reserves space in the vertex vector
     * @param numObjects, the amount of object to allocate
     * @return
     *
     */
    void 
    reserve(SIZE_T numObjects);

    /**
     * @brief Adds an object at the end of the vector
     * @param
     * @return
     *
     */
    void 
    add(const Vector<char>& object);

    /**
     * @brief Adds an object at the end of the vector
     * @param the buffer of information
     * @return
     *
     */
    void 
    add(char* buffer, SIZE_T sizeofBuffer);

    /**
     * @brief Cleans the vector of all objects inside of it
     * @param
     * @return
     *
     */
    void 
    clear();

    /**
     * @brief Creates a buffer in the device with the vector data
     * @param device to use the object and usage
     * @return
     *
     */
    virtual void 
    createHardware(void* pDevice, uint32 usage) = 0;

    /**
     * @brief Sets the buffer data into the device context
     * @param
     * @return
     *
     */
    virtual void 
    write(void* pDevice, void* pData, SIZE_T numBytes) = 0;

    /**
     * Sets the device Context with the buffer
     */
    virtual void
    setVertexShader(void* pDevice, uint32 slot = 0, uint32 numBuffer = 1) = 0;

    /**
     * Sets the device Context with the buffer
     */
    virtual void
    setPixelShader(void* pDevice, uint32 slot = 0, uint32 numBuffer = 1) = 0;

    /**
     * Updates the subresource
     */
    virtual bool
    updateSubResource(void* pContext,
                      uint32 subresource = 0, 
                      uint32 row = 0, 
                      uint32 depth = 0) = 0;

    /**
     * constant data
     */
    Vector<char> m_constantData;
  };
}
