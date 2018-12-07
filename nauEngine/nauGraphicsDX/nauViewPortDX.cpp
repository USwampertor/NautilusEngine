/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file nauViewPortDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/06 2018
 * @brief Member implementation
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "nauViewPortDX.h"

namespace nauEngineSDK {
  bool
  nauViewPortDX::createViewPort(float width, float height, float topLeftX, float topLeftY) {
    m_d3dViewPort.TopLeftX = topLeftX;
    m_d3dViewPort.TopLeftY = topLeftY;
    m_d3dViewPort.Width = width;
    m_d3dViewPort.Height = height;
  }

  void
  nauViewPortDX::setViewPort(void* context) {
    reinterpret_cast<ID3D11DeviceContext*>(context)->RSSetViewports(1, &m_d3dViewPort);
  }
}