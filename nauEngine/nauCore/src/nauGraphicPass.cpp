/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauGraphicPass.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/04/04 2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "nauGraphicPass.h"
namespace nauEngineSDK {

  ///DEFAULT RENDER PASS INFORMATION///
  bool
  GraphicPass::init(Device* pDevice) {
    return true;
  }

  void
  GraphicPass::setPixelShader(Device* pDevice) {

  }

  void
  GraphicPass::setVertexShader(Device* pDevice) {

  }

  void
  GraphicPass::setLayout(Device* pDevice) {

  }

  void
  GraphicPass::setShaderSampler(Device* pDevice) {

  }

  bool
  GraphicPass::loadPixelShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  bool
  GraphicPass::loadVertexShader(Device* pDevice, String fileName, String entry) {
    return true;
  }

  void
  GraphicPass::render() {


  }

  ///GRAPHIC BUFFER ///

}