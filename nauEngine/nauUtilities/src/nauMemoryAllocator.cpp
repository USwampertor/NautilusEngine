/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauMemoryAllocator.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/05 2019
 * @brief Memory allocator definition of variables
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauPrerequisitesUtil.h"

namespace nauEngineSDK {
  NAU_THREADLOCAL uint64 MemoryCounter::m_allocs = 0;
  NAU_THREADLOCAL uint64 MemoryCounter::m_frees = 0;
}