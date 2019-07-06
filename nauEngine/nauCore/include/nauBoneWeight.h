/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBoneWeight.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/05 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  struct BoneWeight {
    /**
     * The bone's ID that will deform a vertex
     */
    int m_ID;

    /**
     * The weight in the 
     */
    float m_weight;

  };
}
