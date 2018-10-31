/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauVertexBufferDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/25 2018
 * @brief Direct X 13 specific vertex Buffer
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once
#include <nauGraphicsBuffer.h>

namespace nauEngineSDK {
  class nauGraphicsBufferDX : public nauGraphicsBuffer
  {
  public:
    nauGraphicsBufferDX() = default;
    ~nauGraphicsBufferDX() {};
  };
  
  class nauVertexBufferDX : public nauVertexBuffer
  {
  public:
    nauVertexBufferDX() = default;
    ~nauVertexBufferDX() {};
  };

  class nauIndexBufferDX : public nauIndexBuffer
  {
  public:
    nauIndexBufferDX() = default;
    ~nauIndexBufferDX() {};
  };
  
}

