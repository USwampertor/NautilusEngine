/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauSphere.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/24 2018
 * @brief a 3d Sphere primitive with radius and position
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   A 3d Sphere primitive that can be used
  * Sample usage:
  *   Sphere(4, nauVector3(0,0,0)) generates a sphere with radius 4 at 0,0,0
  */
  class NAU_UTILITY_EXPORT Sphere {
   public:

    /**
     * Default Constructor
     */
    Sphere() = default;

    /**
     * @brief Constructor with parameters position and float
     * @param position of the object, float radius of the object
     * @return 
     * 
     */
    Sphere(const Vector3& position, float size);

    /**
     * @brief Checks if Two spheres are equal with a difference of x
     * @param sphere to compare, float threshold|error difference
     * @return true if object is equal at certain error
     * 
     */
    bool
    isEqual(const Sphere& sphere, float threshold) const;
    
    /**
     * Collisions
     */
    
    /**
     * @brief Collision between two spheres
     * @param the other sphere to check the collision
     * @return true if object is getting inside the other
     * 
     */
    bool
    collidingSphere(const Sphere& other);
   
    /**
     * Member declaration
     */

   public:
    
    /**
     * radius component
     */
    float m_radius;
    
    /**
     * position of Sphere
     */
    Vector3 m_center;
  };
}
