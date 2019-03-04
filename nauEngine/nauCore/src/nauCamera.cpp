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

    //We check if the objet is not in the same position as the camera
    //if it is, we just tell him its looking forward
    if (!Vector3::isSame(m_position, m_objective)) { m_objective.z = m_position.z + 1.0f; }
    m_view = Matrix4::viewLookAt(m_position, m_objective, m_up);
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