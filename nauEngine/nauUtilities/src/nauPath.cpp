/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauPath.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief Path object
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauPath.h"


namespace nauEngineSDK {
  String
  Path::extension() {
    String extension;

    return extension;
  }

  String
  Path::getFullPath() {
    return m_url;
  }

  String
  Path::getFileName() {
    String fileName;


    return fileName;
  }

  void
  Path::set(String path) {
    m_url = path;
  }
}