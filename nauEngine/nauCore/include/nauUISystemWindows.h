/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauUISystemWindows.h
 * @author Marco "Swampy" Millan
 * @date 11/5/2019
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"
#include "nauUISystem.h"

#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

namespace nauEngineSDK {
class NAU_CORE_EXPORT UISystemWindows : public UISystem
{
public:
  UISystemWindows() = default;

  ~UISystemWindows() = default;

  virtual bool
  init(void* hwnd) override;

  virtual void
  newFrame() override;

  virtual void
  endFrame() override;

  virtual void
  render() override;

  virtual void
  endRender() override;

  virtual void
  finishUI() override;

};

}

