/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauFileSystem.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/29 2019
 * @brief File System management
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauStdHeaders.h"


namespace nauEngineSDK {
  class FileSystem
  {
  public:

    /**
     * Default constructor
     */
    FileSystem() =  default;

    /**
     * Default destructor
     */
    ~FileSystem() = default;

    /**
     * @brief returns the working path where it is right now
     * @param 
     * @return the path in a String object
     *
     */
    String
    getAbsolutePath();

    /**
     * @brief returns the working path where it is right now
     * @param 
     * @return 
     *
     */
    String
    getRelativePath();



  };
  
}

