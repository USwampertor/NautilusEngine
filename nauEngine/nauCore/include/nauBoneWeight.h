/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauBoneWeight.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/05 2019
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {
  struct BoneWeight {
    /**
     * The bone's ID that will deform a vertex
     */
    uint32 m_ID;

    /**
     * The weight in the bone. Shouldn't be higher than 1 and will be 1
     * In the case that there is only one bone affecting a vertex
     */
    float m_weight;

  };
}
