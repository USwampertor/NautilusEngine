/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauWindowsApp.h
 * @author Marco "Swampy" Millan
 * @date 11/13/2019
 * @brief Windows Application from Base Application
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "nauPrerequisitesCore.h"

#include "nauAnimationManager.h"
#include "nauBaseApp.h"
#include "nauDLLoader.h"
#include "nauInputManager.h"
#include "nauLogger.h"
#include "nauRenderManager.h"
#include "nauResourceManager.h"
#include "nauSceneGraph.h"
#include "nauSceneManager.h"
#include "nauUI.h"
#include "nauTimer.h"

#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_GRAFICAS21_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_GRAFICAS21			107
#define IDI_SMALL				108
#define IDC_GRAFICAS21			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif

// Predetermined
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif
#define MAX_LOADSTRING 100


namespace nauEngineSDK {

  class NAU_CORE_EXPORT WindowsApp : public BaseApp
  {
   public:
    /**
     * Default constructor
     */
    WindowsApp() = default;
    
    /**
     * @brief Constructor with given window default winmain parameters for
     *        window generation
     * @param 
     * @param
     * @return 
     *
     */
    WindowsApp(HINSTANCE hInstance, int CommandShow) {
      m_hInst = hInstance;
      m_commandShow = CommandShow;
    }

    /**
     * Default destructor
     */
    ~WindowsApp() = default;
  
    virtual int32
    start() override;
  
    virtual void
    render() override; 
  
    virtual void
    renderUI() override;
  
    virtual bool
    initApp(void* hwnd) override;
  
    virtual bool
    initUI(void* hwnd) override;
  
    virtual void
    shutDown() override;
  
    virtual void
    close() override;
  
    virtual void
    update() override;
  
  
    static INT_PTR CALLBACK 
    About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
    
    BOOL 
    InitInstance();
    
    ATOM
    MyRegisterClass();
  
    static HINSTANCE m_hInst;
    
    static HWND m_hWnd;
  
    static LRESULT CALLBACK 
    WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    static void 
    ImGui_ImplWin32_UpdateMousePos();

    static bool 
    ImGui_ImplWin32_UpdateMouseCursor();

    static LRESULT
    ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    int m_commandShow;
  };
  
}
