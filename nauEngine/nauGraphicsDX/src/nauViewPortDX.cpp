/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauViewPortDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/06 2018
 * @brief Member implementation
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauViewPortDX.h"

namespace nauEngineSDK {
  bool
  ViewPortDX::createViewPort(float width, float height, float topLeftX, float topLeftY) {
    m_d3dViewPort.TopLeftX = topLeftX;
    m_d3dViewPort.TopLeftY = topLeftY;
    m_d3dViewPort.Width = width;
    m_d3dViewPort.Height = height;
    m_d3dViewPort.MinDepth = 0.0f;
    m_d3dViewPort.MaxDepth = 1.0f;
    return true;
  }

  void
  ViewPortDX::setViewPort(void* context) {
    reinterpret_cast<ID3D11DeviceContext*>(context)->RSSetViewports(1, &m_d3dViewPort);
  }
}