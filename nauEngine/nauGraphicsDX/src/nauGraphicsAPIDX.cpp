/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicsAPIDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X graphics API implementation of the base core API
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "nauGraphicsAPIDX.h"
using namespace DirectX;

namespace nauEngineSDK {


  bool
  GraphicsAPIDX::init(void* scrHandler) {
    m_device = new DeviceDX();
    if (!initDevice(scrHandler)) {
      Logger::instance().toIDE("Failed to initialize device", LOGGER_LEVEL::ERRORED);
      return false;
    }

    return true;
  }

  bool
  GraphicsAPIDX::initDevice(void* scrHandler) {

    if (!m_device->initializeDevice(scrHandler)) {
      return false;
    }
    
    if (!m_viewPort.createViewPort(static_cast<float>(m_device->m_width),
                                   static_cast<float>(m_device->m_height),
                                   0.0f,
                                   0.0f)) {
      Logger::instance().toIDE("Failed to initialize device", LOGGER_LEVEL::ERRORED);
      exit(828);
    }
    Logger::instance().toIDE("Created Device", LOGGER_LEVEL::SUCCESS);
    m_viewPort.setViewPort(m_device->getContext());
    return true;
  }

  void
  GraphicsAPIDX::render() {
    
  }

  Device*
  GraphicsAPIDX::getDevice() {
    return m_device;
  }

  void
  GraphicsAPIDX::clear() {
    //Vector4 col = { 0.5f,0.5f,0.5f,1.0f };

    //m_renderTarget.clearView(m_device, col);
    //m_depthStencil.clearView(m_device);

  }

  void
  GraphicsAPIDX::swapBuffer() {
    reinterpret_cast<IDXGISwapChain*>(m_device->getSwapChain())->Present(DXGI_SWAP_EFFECT_DISCARD, DXGI_PRESENT_DO_NOT_WAIT);
  }

  Vector2
  GraphicsAPIDX::getWindowSize() {
    return Vector2(getDevice()->m_width, getDevice()->m_height);
  }
}