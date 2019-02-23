/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauCamera.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/01/31 2019
 * @brief Camera member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauCamera.h"

namespace nauEngineSDK {

  void
  Camera::moveForward(float defaz) {
    m_position.z += defaz;
    m_objective.z += defaz;
    m_dirty = true;
  }

  void
  Camera::moveRight(float defaz) {
    m_position.x += defaz;
    m_objective.x += defaz;
    m_dirty = true;
  }

  void
  Camera::rotate(Vector3 axis, float rads) {

    float cos = Math::cos(rads);
    float sin = Math::sin(rads);
    float min = (1 - Math::cos(rads));

    Matrix3 tmp;

    tmp.m[0][0] = cos + axis.x*axis.x*min;
    tmp.m[1][0] = axis.x*axis.y*min - axis.z;
    tmp.m[2][0] = axis.x*axis.z*min + axis.y*sin;
    tmp.m[0][1] = axis.y*axis.x * min + axis.z * sin;
    tmp.m[1][1] = cos + axis.y*axis.y;
    tmp.m[2][1] = axis.y*axis.z*min - axis.x*sin;
    tmp.m[0][2] = axis.z*axis.x*min - axis.y*sin;
    tmp.m[1][2] = axis.z*axis.y*min + axis.x*sin;
    tmp.m[2][2] = cos + axis.z*axis.z*min;

    Vector3 direction;
    Vector3 dir = m_objective - m_position;

    direction.x = (dir.x*tmp.m[0][0] + dir.y*tmp.m[1][0] + dir.z*tmp.m[2][0]);
    direction.y = (dir.x*tmp.m[0][1] + dir.y*tmp.m[1][1] + dir.z*tmp.m[2][1]);
    direction.z = (dir.x*tmp.m[0][2] + dir.y*tmp.m[1][2] + dir.z*tmp.m[2][2]);

    m_objective += direction;

    m_dirty = true;
  }

  void
  Camera::orbit(Vector3 objective, Vector3 axis, float rads) {

    float cos = Math::cos(rads);
    float sin = Math::sin(rads);
    float min = (1 - Math::cos(rads));

    Matrix3 tmp;

    tmp.m[0][0] = cos + axis.x*axis.x*min;
    tmp.m[1][0] = axis.x*axis.y*min - axis.z;
    tmp.m[2][0] = axis.x*axis.z*min + axis.y*sin;
    tmp.m[0][1] = axis.y*axis.x * min + axis.z * sin;
    tmp.m[1][1] = cos + axis.y*axis.y;
    tmp.m[2][1] = axis.y*axis.z*min - axis.x*sin;
    tmp.m[0][2] = axis.z*axis.x*min - axis.y*sin;
    tmp.m[1][2] = axis.z*axis.y*min + axis.x*sin;
    tmp.m[2][2] = cos + axis.z*axis.z*min;

    m_objective = objective;

    Vector3 direction;
    Vector3 dir = m_position - m_objective;

    direction.x = (dir.x*tmp.m[0][0] + dir.y*tmp.m[1][0] + dir.z*tmp.m[2][0]);
    direction.y = (dir.x*tmp.m[0][1] + dir.y*tmp.m[1][1] + dir.z*tmp.m[2][1]);
    direction.z = (dir.x*tmp.m[0][2] + dir.y*tmp.m[1][2] + dir.z*tmp.m[2][2]);

    m_position += direction;

    m_dirty = true;
  }

  Matrix4
  Camera::getView() {
    if (m_dirty) {
      createView();
    }
    return m_view;
  }

  void
  Camera::createView() {
    Vector3 m_front = (m_objective - m_position).normalized();
    Vector3 m_right = (m_up ^ m_right).normalized();
    Vector3 m_up = m_front ^ m_right;

    m_view.m[0][0] = m_right.x; 
    m_view.m[1][0] = m_up.x; 
    m_view.m[2][0] = m_front.x;
    m_view.m[3][3] = 0.0f;

    m_view.m[0][1] = m_right.y; 
    m_view.m[1][1] = m_up.x; 
    m_view.m[2][1] = m_front.x;
    m_view.m[3][3] = 0.0f;

    m_view.m[0][2] = m_right.z; 
    m_view.m[1][2] = m_up.x; 
    m_view.m[2][2] = m_front.x;
    m_view.m[3][3] = 1.0f;

    m_view.m[0][3] = Vector3::dotScale(m_right, m_position); 
    m_view.m[1][3] = Vector3::dotScale(m_up,    m_position);
    m_view.m[2][3] = Vector3::dotScale(m_front, m_position);
    m_view.m[3][3] = 0.0f;

    m_dirty = false;
  }

  void
  Camera::setPosition(Vector3 position) {
    m_position = position;
    m_dirty = true;
  }
  
  void
  Camera::setPosition(float x, float y, float z) {
    m_position = Vector3(x, y, z);
    m_dirty = true;
  }

  void
  Camera::setObjective(Vector3 position) {
    m_objective = position;
    m_dirty = true;
  }
  
  void
  Camera::setObjective(float x, float y, float z) {
    m_objective = Vector3(x, y, z);
    m_dirty = true;
  }

}