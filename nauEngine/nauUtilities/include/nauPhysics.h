/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCollisions.h
 * @author Marco "Swampy" Millan
 * @date 6/11/2020
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesUtil.h"

#include "nauPlatformMath.h"
#include "nauSphere.h"
#include "nauBox2d.h"
#include "nauAABB.h"
#include "nauOOBB.h"
#include "nauVector3.h"
#include "nauPlane.h"

namespace nauEngineSDK {

  /**
   * A Object to contain functions to get collisions
   * Description:
   * 	
   * Sample usage:
   * 	
   */
  class Physics
  {
    /**
     * Collisions
     */

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionPoint(const Vector3& a, const Vector3& b) { return a == b; }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionSpherePlane(const Sphere& sphere, const Plane& plane) {
      float distance = Vector3::dot(sphere.m_center, plane) - plane.d;
      return Math::abs(distance) <= sphere.m_radius;
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionOOBBPlane(const OOBB& oobb, const Plane& plane) {
      float radius = (oobb.widthX / 2)  * Math::abs(Vector3::dot(plane, oobb.m_xAxis));
                     (oobb.heightY / 2) * Math::abs(Vector3::dot(plane, oobb.m_yAxis));
                     (oobb.lengthZ / 2) * Math::abs(Vector3::dot(plane, oobb.m_zAxis));
      float difference = Vector3::dot(plane, oobb.center) - plane.d;
      return Math::abs(difference) <= radius;
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionOOBBSphere(const OOBB& oobb, const Sphere& sphere) {
      return false;
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionAABBPoint(const AABB& aabb, const Vector3& point) {
      return (point.x >= aabb.m_min.x && point.x <= aabb.m_max.x) &&
             (point.y >= aabb.m_min.y && point.y <= aabb.m_max.y) &&
             (point.z >= aabb.m_min.z && point.z <= aabb.m_max.z); 
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionAABBSphere(const AABB& aabb, const Sphere& sphere) {
      Vector3 boxPoint = { Math::max(aabb.m_min.x, Math::min(sphere.m_center.x, aabb.m_max.x)),
                           Math::max(aabb.m_min.y, Math::min(sphere.m_center.y, aabb.m_max.y)),
                           Math::max(aabb.m_min.z, Math::min(sphere.m_center.z, aabb.m_max.z)),
      };
      return collisionSpherePoint(sphere, boxPoint);
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionAABBPlane(const AABB& aabb, const Plane& plane) {
      Vector3 center = (aabb.m_max + aabb.m_min) * 0.5f;
      Vector3 extent = aabb.m_max - center;

      float radius = extent.x * Math::abs(plane.x) + 
                     extent.y * Math::abs(plane.y) + 
                     extent.z * Math::abs(plane.z);

      float difference = Vector3::dot(plane, center) - plane.d;
      return Math::abs(difference) <= radius;
    }


    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionSpherePoint(const Sphere& sphere, const Vector3& point) {
      float distance = Math::sqrt((point.x - sphere.m_center.x) * (point.x - sphere.m_center.x) +
                                  (point.y - sphere.m_center.y) * (point.y - sphere.m_center.y) +
                                  (point.z - sphere.m_center.z) * (point.z - sphere.m_center.z));
      return distance < sphere.m_radius;
    }


    /**
     * @brief Collision between Sphere and Box2D objects
     * @param nauSphere sphere, nauBox2D box
     * @return true if colliding
     *
     */
    inline static bool
    collisionBoxSphere(const Sphere& sphere, const Box2D& box) {

      Vector2 sphereD;
      sphereD.x = Math::abs(sphere.m_center.x - (box.m_max.x / 2));
      sphereD.y = Math::abs(sphere.m_center.y - (box.m_max.y / 2));

      if (sphereD.x > ((box.m_max - box.m_min).x / 2 + sphere.m_radius)) { return false; }
      if (sphereD.y > ((box.m_max - box.m_min).y / 2 + sphere.m_radius)) { return false; }

      if (sphereD.x <= ((box.m_max - box.m_min).x / 2)) { return true; }
      if (sphereD.y <= ((box.m_max - box.m_min).y / 2)) { return true; }

      float cornerDistance = Math::sqr(sphereD.x - (box.m_max - box.m_min).x / 2) +
        Math::sqr(sphereD.y - (box.m_max - box.m_min).y / 2);

      return cornerDistance <= Math::sqr(sphere.m_radius);
    }


  };

  
}
