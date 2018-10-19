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
namespace nauEngineSDK {

  class nauGraphicsBuffer
  {
  public:
    nauGraphicsBuffer() = default;
    virtual ~nauGraphicsBuffer() = 0;
  };
  
  class nauVertexBuffer : public nauGraphicsBuffer
  {
    nauVertexBuffer() = default;
  };
  
  class nauIndexBuffer : public nauGraphicsBuffer
  {
    nauIndexBuffer() = default;
  };
  
  class nauConstantBuffer : public nauGraphicsBuffer
  {
  
  };
}
