/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauBox2d.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief 2D Box primitive object
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "nauMath.h"
#include "nauPrerequisitesUtil.h"
#include "nauVector2.h"

namespace nauEngineSDK {
  /**
  * Description:
  *   A 2d Box Primitive Object
  * Sample usage:
  * 	2dBox for a sprite
  */
  class NAU_UTILITY_EXPORT Box2D
  {
   public:

    /**
     * Default constructor
     */
    Box2D() = default;

    /**
     * @brief Constructor with limits of box2d
     * @param vector2 min and vector2 max
     * @return 
     * 
     */
    Box2D(const Vector2& min, const Vector2& max);

    /**
     * @brief Constructor with
     * @param origin min position and height width and length
     * @return 
     * 
     */
    Box2D(const Vector2& origin, float height, float width);
    
    /**
     * Default Destructor
     */
    ~Box2D() = default;

    /**
     * Collisions
     */
    
    /**
     * @brief checks if theres a collision between 2 box2d
     * @param nauBox2d the other box
     * @return true if its colliding
     * 
     */
    bool
    collidingBox2d(const Box2D& other);

    /**
     * @brief checks if one of the points is inside the box
     * @param nauVector2 the other point
     * @return true if the point is inside the box
     * 
     */
    bool
    insideBox2d(const Vector2& other);


    /**
     * Member declaration
     */
   public:

    /**
     * lower corner component
     */
    Vector2 m_min;

    /**
     * higher corner component
     */
    Vector2 m_max;
  };
}


