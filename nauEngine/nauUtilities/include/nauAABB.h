/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauAABB.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/25 2018
 * @brief An Axis Aligned Boundary Box (AABB) wich has two tips that define the 
 * whole space the cube is in
 * SIGGRAPH is really useful for this things
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauMath.h"
#include "nauVector3.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   An Axis Aligned Bounding Box that covers an object 
  * Sample usage:
  * 	Collision detection of static aligned objects
  */
  class AABB
  {
   public:

    /**
     * Default Constructor
     */
    AABB() = default;

    /**
     * @brief Constructor with corners as parameters
     * @param minTip is lower corner, maxTip is higher corner
     * @return 
     * 
     */
    AABB(const Vector3& minTip, const Vector3& maxTip);

    /**
     * @brief Constructor with origin and height width and length of object
     * @param origin of box, height y difference from origin, width x difference 
     * from origin, length z difference from origin
     * @return 
     * 
     */
    AABB(const Vector3& origin, float height, float width, float lenght);
    
    /**
     * Collisions
     */

    /**
     * @brief Collision with same object
     * @param other box to compare collision
     * @return true if is inside first box
     * 
     */
    bool
    collidingAABB(const AABB& other);
    

    /**
     * @brief Simple function to determine if a point is inside Box
     * @param vector3 to check
     * @return true if point is inside object
     * 
     */
    bool
    insideBox(const Vector3& other);
    
    /**
     * Member declaration
     */
   public:

    /**
     * the lower corner component
     */
    Vector3 m_minCorner;

    /**
     * the higher corner component
     */
    Vector3 m_maxCorner;

  };
}


