/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauConstantBufferMatrix.h
 * @author Marco "Swampy" Millan
 * @date 2019/02/27 2019
 * @brief Constant buffer defined as never changing, changing on size and changing on frame
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include <nauMatrix4.h>
#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

   /**
    * CBNeverChanges
    * Description:
    *   Defines a Matrix that will never change	
    * Sample usage:
    * 	view Matrix doesnt change
    */
  struct NAU_CORE_EXPORT CBNeverChange
  {
  public:
    /**
     * Default constructor
     */
    CBNeverChange() = default;

    /**
     * 
     */
    CBNeverChange(const CBNeverChange& other)
      : m_view(other.m_view) {}

    /**
     * Default destructor
     */
    ~CBNeverChange() = default;


    Matrix4 m_view;
  };

  struct NAU_CORE_EXPORT CBResizeChange
  {
  public:
    /**
     * Default constructor
     */
    CBResizeChange() = default;

    /**
     *
     */
    CBResizeChange(const CBResizeChange& other)
      : m_projection(other.m_projection) {}

    /**
     * Default destructor
     */
    ~CBResizeChange() = default;


    Matrix4 m_projection;
  };

  struct NAU_CORE_EXPORT CBFrameChange
  {
  public:
    /**
     * Default constructor
     */
    CBFrameChange() = default;

    /**
     *
     */
    CBFrameChange(const CBFrameChange& other)
      : m_world(other.m_world),
        m_meshColor(other.m_meshColor) {}

    /**
     * Default destructor
     */
    ~CBFrameChange() = default;


    Matrix4 m_world;
    Vector4 m_meshColor;
  };

}

