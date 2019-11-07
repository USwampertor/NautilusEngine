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
class NAU_CORE_EXPORT UISystemWindows : public UISystem, public Module<UISystemWindows>
{
public:
  UISystemWindows() = default;

  ~UISystemWindows() = default;

  bool
  init(void* hwnd);

  void
  newFrame();

  void
  endFrame();

  void
  render();

  void
  endRender();

};

}

