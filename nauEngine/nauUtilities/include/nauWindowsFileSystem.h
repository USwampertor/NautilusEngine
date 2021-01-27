/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauWindowsFileSystem.h
 * @author Marco "Swampy" Millan
 * @date 1/26/2021
 * @brief 
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include "nauPrerequisitesUtil.h"
#include "nauFileSystem.h"

namespace nauEngineSDK {

  class NAU_UTILITY_EXPORT WindowsFileSystem : public FileSystem
  {
  public:

    /**
     * Default constructor
     */
    WindowsFileSystem() = default;

    /**
     * Default destructor
     */
    ~WindowsFileSystem() = default;

    virtual void
    init(void* handler) override;

    virtual bool
    open() override;

    virtual bool
    save() override;

  };

  MS_ALIGN(16)
  extern "C" NAU_UTILITY_EXPORT FileSystem*
    createFileSystemAPI() {
    return new WindowsFileSystem();
  }
  GCC_ALIGN(16)

}


