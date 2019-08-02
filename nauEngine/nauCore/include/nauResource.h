/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauResource.h
 * @author Marco "Swampy" Millan
 * @date 2019/06/25 2019
 * @brief Resource Object wrapper for audio, texture, files and other objects
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

namespace nauEngineSDK {

  namespace RESOURCETYPE
  {
  enum E
  {
    NONE          = 0,
    AUDIO         ,
    TEXTURE       ,
    CUBEMAP       ,
    MATERIAL      ,
    MODEL         ,
    SKELETON      ,
    ANIMATOR      ,
    SCENE         ,
    PROJECT       
  };
  }


class NAU_CORE_EXPORT Resource
{
public:
  /**
   * Default constructor
   */
  Resource() = default;

  /**
   * Default destructor
   */
  virtual
  ~Resource() = default;

  /**
   * @brief Virtual function that child will override to load things its way
   * @param String path of the object to load
   * @return true if able to load it, false if not able
   *
   */
  virtual bool 
  load(String path) = 0;

  /**
   * @brief Virtual function that child will override to define the type of the
   *        object
   * @param 
   * @return the RESOURCETYPE the object is 
   *
   */
  virtual RESOURCETYPE::E
  getType() = 0;
};

}
