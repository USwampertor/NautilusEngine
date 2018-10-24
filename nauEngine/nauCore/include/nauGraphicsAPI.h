/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsAPI.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

namespace nauEngineSDK {
  
  
  class nauGraphicsAPI
  {
   public:
    nauGraphicsAPI() = default;
    ~nauGraphicsAPI() {};
    bool initDevice();
    void onRender();
    void setShaders();
  
  };
  
}


