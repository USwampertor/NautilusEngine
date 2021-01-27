/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauFileSystem.h
 * @author Marco "Swampy" Millan
 * @date 2019/03/29 2019
 * @brief File System management
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauStdHeaders.h"
#include "nauModule.h"

namespace nauEngineSDK {
  class NAU_UTILITY_EXPORT FileSystem : public Module<FileSystem>
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
     * @brief Initializes the module 
     * @param 
     * @return 
     *
     */
    virtual void
    init(void* handler) = 0;

    /**
     * @brief Opens a File that the user can set 
     * @param 
     * @return 
     *
     */
    virtual bool
    open() = 0;

    /**
     * @brief 
     * @param 
     * @return 
     *
     */
    virtual bool
    save() = 0;
  };
  
  extern NAU_UTILITY_EXPORT FileSystem*
    g_FileSystem;

}

