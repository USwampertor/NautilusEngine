/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauWeight.h
 * @author Marco "Swampy" Millan
 * @date 2019/05/23 2019
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesCore.h"


namespace nauEngineSDK {
struct VertexWeight
{
  VertexWeight(uint32 id, float weight) 
    : m_ID(id), 
      m_weight(weight) {}

  uint32 m_ID;
  float m_weight;
};  
}

