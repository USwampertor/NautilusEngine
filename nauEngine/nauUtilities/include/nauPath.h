/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauPath.h
 * @author Marco "Swampy" Millan
 * @date 2019/07/12 2019
 * @brief Path object to contain path string information of path objects
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "nauPrerequisitesUtil.h"


namespace nauEngineSDK {
class Path
{
public:
  /**
   * Default constructor
   */
  Path() = default;

  /**
   * Default destructor
   */
  ~Path() = default;

  String
  extension();

  String
  get();
};

}

