/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauUIAPIDX.h
 * @author Marco "Swampy" Millan
 * @date 11/6/2019
 * @brief Class implementation in DX
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesDX.h"

#include <nauUIAPI.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>

namespace nauEngineSDK {

  /**
   * UIAPIDX
   * Description:
   * 	Implementation of the UIAPI class to return instances of DX11 ImGui
   * Sample usage:
   * 	
   */
class NAU_DIRECTX_EXPORT UIAPIDX : public UIAPI
{
public:
  /**
   * 
   */
  UIAPIDX() = default;

  /**
   * 
   */
  ~UIAPIDX() = default;

  virtual bool
  init(Device* device) override;

  virtual void
  newFrame() override;

  virtual void
  endFrame() override;

  virtual void
  render() override;

};

}

