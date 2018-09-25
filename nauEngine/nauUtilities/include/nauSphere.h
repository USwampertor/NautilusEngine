/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauSphere.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/24 2018
 * @brief
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  class nauSphere
  {
   public:
    nauSphere() = default;
    nauSphere(const nauVector3& position, float size);

    bool
    isEqual(const nauSphere& sphere, float threshold) const;
    /**
     * Collisions
     */
    bool
    collidingSphere(const nauSphere& other);
   public:
    float m_radius;
    nauVector3 m_center;
  };

 

  /**
   * @brief 
   * @param 
   * @return 
   * 
   */
}
