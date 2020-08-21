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

#include "nauAABB.h"
#include "nauBox2d.h"
#include "nauCapsule.h"
#include "nauOOBB.h"
#include "nauPlane.h"
#include "nauPlatformMath.h"
#include "nauSphere.h"
#include "nauTriangle.h"
#include "nauVector3.h"

namespace nauEngineSDK {

  /**
   * A Object to contain functions to get collisions
   * Description:
   * 	
   * Sample usage:
   * 	
   */
  class NAU_UTILITY_EXPORT Physics
  {
   public:
    /**
     * Closest Points and distances
     */

    /**
     * @brief Given a normalized plane, returns the closest point 
     *        between a point and the plane
     * @param const Vector3& point the point reference
     * @param const Plane& plane the plane to get the nearest point
     * @return Vector3 the point reflected on the plane nearest to the point
     *
     */
    inline static
    Vector3 closestPointPlane(const Vector3& point, const Plane& plane) {
      float t = Vector3::dot(plane, point) - plane.d;
      return point - (plane * t);
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static
    float closestPointSegmentSegment(const Vector3& point1_A, const Vector3& point1_B,
                                     const Vector3& point2_A, const Vector3& point2_B) {
      float s;
      float t;
      Vector3 c1;
      Vector3 c2;

      Vector3 distance1 = point1_B - point1_A;
      Vector3 distance2 = point2_B - point2_A;

      Vector3 r = point1_A - point2_A;

      float a = distance1.sqrMagnitude();
      float e = distance2.sqrMagnitude();
      float f = Vector3::dot(distance2, r);

      if (a <= std::numeric_limits<float>::epsilon() && 
          e <= std::numeric_limits<float>::epsilon()) {
        return r.sqrMagnitude();
      }

      if (a <= std::numeric_limits<float>::epsilon()) {
        s = 0.0f;
        t = Math::clamp(f / e, 0.0f, 1.0f);
      }
      else {
        float c = Vector3::dot(distance1, r);
        if (e <= std::numeric_limits<float>::epsilon()) {

          t = 0.0f;
          s = Math::clamp(-c / a, 0.0f, 1.0f);
        }
        else {

          float b = Vector3::dot(distance1, distance2);
          float denom = a * e - b * b;

          if (denom != 0.0f) {
            s = Math::clamp((b*f - c * e) / denom, 0.0f, 1.0f);
          }
          else { s = 0.0f; }

          t = (b*s + f) / e;

          if (t < 0.0f) {
            t = 0.0f;
            s = Math::clamp(-c / a, 0.0f, 1.0f);
          }
          else if (t > 1.0f) {
            t = 1.0f;
            s = Math::clamp((b - c) / a, 0.0f, 1.0f);
          }
        }
      }

      c1 = point1_A + distance1 * s;
      c2 = point2_A + distance1 * t;

      return (c1 - c2).sqrMagnitude();
    }

    inline static
    Vector3 closestPointTriangle(Vector3 point, Triangle triangle) {
      Vector3 ab = triangle.m_b - triangle.m_a;
      Vector3 ac = triangle.m_c - triangle.m_a;
      Vector3 ap = point        - triangle.m_a;

      float distance1 = Vector3::dot(ab, ap);
      float distance2 = Vector3::dot(ac, ap);

      if (distance1 <= 0.0f && distance2 <= 0.0f) { return triangle.m_a; }

      Vector3 bp = point - triangle.m_b;

      float distance3 = Vector3::dot(ab, bp);
      float distance4 = Vector3::dot(ac, bp);
      
      if (distance3 >= 0.0f && distance4 <= distance3) { return triangle.m_b; }

      float vc = distance1 * distance4 - distance3 * distance2;
      if (vc <= 0.0f && distance1 >= 0.0f && distance3 <= 0.0f) {
        float v = distance1 / (distance1 - distance3);
        return triangle.m_a + (ab * v);
      }

      Vector3 cp = point - triangle.m_c;

      float distance5 = Vector3::dot(ab, cp);
      float distance6 = Vector3::dot(ac, cp);

      if (distance6 >= 0.0f && distance5 <= distance6) { return triangle.m_c; }

      float vb = distance5 * distance2 - distance1 * distance6;
      if (vb <= 0.0f && distance2 >= 0.0f && distance6 <= 0.0f) {
        float w = distance2 / (distance2 - distance6);
        return triangle.m_a + (ac * w);
      }

      float va = distance3 * distance6 - distance5 * distance4;
      if (va <= 0.0f && (distance4 - distance3) >= 0.0f && (distance5 - distance6) >= 0.0f) {
        float w = (distance4 - distance3) / ((distance4 - distance3) + (distance5 - distance6));
        return triangle.m_b + (triangle.m_c - triangle.m_b) * w;
      }

      float denom = 1.0f / (va + vb + vc);
      float v = vb * denom;
      float w = vc * denom;

      return triangle.m_a + ab * v + ac * w;

    }


    inline static 
    Vector3 closestPointOOBB(const Vector3& point, const OOBB& oobb) {
      Vector3 distance = point - oobb.center;

      Vector3 closestPoint = oobb.center;

      float currentDistance = Vector3::dot(distance, oobb.m_xAxis);

      if (currentDistance > oobb.widthX) { currentDistance = oobb.widthX; }
      if (currentDistance < -oobb.widthX) { currentDistance = -oobb.widthX; }

      closestPoint += oobb.m_xAxis * currentDistance;

      currentDistance = Vector3::dot(distance, oobb.m_yAxis);

      if (currentDistance > oobb.heightY) { currentDistance = oobb.heightY; }
      if (currentDistance < -oobb.heightY) { currentDistance = -oobb.heightY; }

      closestPoint += oobb.m_yAxis * currentDistance;

      currentDistance = Vector3::dot(distance, oobb.m_zAxis);

      if (currentDistance > oobb.lengthZ) { currentDistance = oobb.lengthZ; }
      if (currentDistance < -oobb.lengthZ) { currentDistance = -oobb.lengthZ; }

      closestPoint += oobb.m_zAxis * currentDistance;

      return closestPoint;
    }

    inline static
    Vector3 closestPointAABB(const Vector3& point, const AABB& aabb) {
      
      Vector3 closestPoint;
      
      for (int i = 0; i < 3; ++i) {
        float v = point[i];
        v = Math::max(v, aabb.m_min[i]);
        v = Math::min(v, aabb.m_max[i]);

        closestPoint[i] = v;
      }

      return closestPoint;
    }
    

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
      float radius = oobb.widthX  * Math::abs(Vector3::dot(plane, oobb.m_xAxis)) +
                     oobb.heightY * Math::abs(Vector3::dot(plane, oobb.m_yAxis)) +
                     oobb.lengthZ * Math::abs(Vector3::dot(plane, oobb.m_zAxis));
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
      Vector3 closestPoint = closestPointOOBB(sphere.m_center, oobb);

      return collisionSpherePoint(sphere, closestPoint);
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
      
      Vector3 closestPoint = closestPointAABB(sphere.m_center, aabb);

      return collisionSpherePoint(sphere, closestPoint);
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

      Vector3 distance = point - sphere.m_center;
      return distance.sqrMagnitude() <= sphere.m_radius * sphere.m_radius;
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionSphereTriangle(const Sphere& sphere, const Triangle& triangle) {
      Vector3 closestPoint = closestPointTriangle(sphere.m_center, triangle);

      return collisionSpherePoint(sphere, closestPoint);
    }

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static bool
    collisionSphereCapsule(const Sphere& sphere, const Capsule& capsule) {
      float sqDistance = sqDistPointSegment(sphere.m_center, capsule.m_A, capsule.m_B);
      float radius = sphere.m_radius + capsule.m_radius;
      return sqDistance <= radius * radius;

    }

    /**
     * @brief Collision between Sphere and Box2D objects
     * @param nauSphere sphere, nauBox2D box
     * @return true if colliding
     *
     */
    inline static bool
    collisionBox2DSphere(const Sphere& sphere, const Box2D& box) {

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

    /**
     * Distances
     */

     /**
      * @brief Given a normalized plane, returns the distance between a plane
      *        and a point in space
      * @param const Vector3& point
      * @param const Plane& plane
      * @return float
      *
      */
    inline static
      float distancePointPlane(const Vector3& point, const Plane& plane) {
      return Vector3::dot(plane, point) - plane.d;
    }



    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    inline static
    float sqDistPointSegment(const Vector3& point, 
                             const Vector3& segment_A, 
                             const Vector3& segment_B) {
    
      Vector3 segment_AB = segment_B - segment_A;
      Vector3 segment_AP = point - segment_A;
      Vector3 segment_BP = point - segment_B;

      float e = Vector3::dot(segment_AP, segment_AB);
      if (e <= 0.0f) { return segment_AB.sqrMagnitude(); }

      float f = segment_AB.sqrMagnitude();

      if (e >= f) { return segment_BP.sqrMagnitude(); }
      return segment_AP.sqrMagnitude() - ((e * e) / f);
    }

  };

  
}
