/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauUIAPIDX.cpp
 * @author Marco "Swampy" Millan
 * @date 11/6/2019
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauUIAPIDX.h"

namespace nauEngineSDK {
  bool
  UIAPIDX::init(Device* device) {

    auto dev = reinterpret_cast<ID3D11Device*>(device->get());
    auto context = reinterpret_cast<ID3D11DeviceContext*>(device->getContext());

    //return ImGui_ImplDX11_Init(dev, context);

    return true;
  }

  void
  UIAPIDX::newFrame() {

  }

  void
  UIAPIDX::endFrame() {

  }

  void
  UIAPIDX::render() {

  }
}