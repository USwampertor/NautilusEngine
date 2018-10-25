/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauTexture.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/22 2018
 * @brief a color and brightness information class
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once
#include <nauStdHeaders.h>

namespace nauEngineSDK {

  /**
   * nauTexture
   * Description:
   *  
   * Sample usage:
   *
   */
  class nauTexture
  {
  public:

    /**
     * default constructor
     */
    nauTexture() = default;

    /**
     * default destructor
     */
    ~nauTexture() {};

    /**
     * @brief Loads a resource from a path
     * @param 
     * @return 
     *
     */
    virtual bool
    loadFromFile();


  };
  
}
