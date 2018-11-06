#include "nauDataStream.h"

namespace nauEngineSDK {
  
  STREAMTYPE
  nauFileStream::isType() {
    return STREAMTYPE::FILE;
  }

  STREAMTYPE
  nauMemStream::isType() {
    return STREAMTYPE::MEMORY;
  }


}