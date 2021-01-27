/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauPath.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief Path object to contain path string information of path objects
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesUtil.h"


namespace nauEngineSDK {
class NAU_UTILITY_EXPORT Path
{
public:
  /**
   * Default constructor
   */
  Path() = default;

  /**
   * @brief Constructor with String parameter
   */
  Path(String url) : m_url(url) {}

  /**
   * Default destructor
   */
  ~Path() = default;

  /**
   * @brief Returns the extension of the path
   * @param 
   * @return the string after the last "."
   *
   */
  String
  extension();

  /**
   * @brief Returns the full path
   * @param 
   * @return the full path of the file
   *
   */
  String
  getFullPath();

  /**
   * @brief Returns the File Name only
   * @param 
   * @return The file name
   *
   */
  String
  getFileName();

  /**
   * @brief Sets the path
   * @param String path the path
   * @return 
   *
   */
  void
  set(String path);

private:
  String m_url;
};

}

