/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauBox2d.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief 2D Box primitive object
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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
  class nauBox2d
  {
   public:

    /**
     * Default constructor
     */
    nauBox2d() = default;

    /**
     * @brief Constructor with limits of box2d
     * @param vector2 min and vector2 max
     * @return 
     * 
     */
    nauBox2d(const nauVector2& min, const nauVector2& max);

    /**
     * @brief Constructor with
     * @param origin min position and height width and length
     * @return 
     * 
     */
    nauBox2d(const nauVector2& origin, float height, float width);
    
    /**
     * Default Destructor
     */
    ~nauBox2d() = default;

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
    collidingBox2d(const nauBox2d& other);

    /**
     * @brief checks if one of the points is inside the box
     * @param nauVector2 the other point
     * @return true if the point is inside the box
     * 
     */
    bool
    insideBox2d(const nauVector2& other);


    /**
     * Member declaration
     */
   public:

    /**
     * lower corner component
     */
    nauVector2 m_min;

    /**
     * higher corner component
     */
    nauVector2 m_max;
  };
}


