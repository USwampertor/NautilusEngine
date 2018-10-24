/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauModel.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief model object to render
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once

namespace nauEngineSDK {
  /**
   * nauModel
   * Description:
   * 	Its an object made from a set of meshes, textures and whatnot
   * Sample usage:
   *
   */
  class nauModel
  {
   public:

    /**
     * Default constructor
     */
    nauModel() = default;

    /**
     * virtual destructor
     */
    virtual ~nauModel() = 0;
  };

}
