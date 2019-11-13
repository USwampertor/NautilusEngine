/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file main.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief Graphics testing with different graphic API
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

//#include <d3d11.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <nauGraphicsAPI.h>

#include "nauTestApp.h"

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

using namespace nauEngineSDK;
using std::vector;

//Global variables
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING] = L"myWindow";
WCHAR szWindowClass[MAX_LOADSTRING] = L"myWindowClass";

HWND g_hWnd;
//Forward declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//TestApp m_app;

#pragma region DEPRECATED

typedef void* (*G_FACTORY)();

void*
loadDLL(String path, String functionName) {
  
  String processor;

#ifdef NAU_ARCH_TYPE == NAU_ARCHITECTURE_x86_32
  processor = "x86";
#else
  processor = "x64";
#endif // NAU_ARCH_TYPE




  char dirPath[MAX_PATH];
  GetCurrentDirectoryA(MAX_PATH, dirPath);
  
  String folderPath(dirPath);

#if NAU_DEBUG_MODE
  path.append("d");
#endif // NAU_DEBUG_MODE

#if NAU_PLATFORM == NAU_PLATFORM_WIN32
  path.append(".dll");
#elif NAU_PLATFORM == NAU_PLATFORM_LINUX
  path.append(".so");
#else
  exit(004);
#endif

  folderPath = folderPath.append("\\").append(processor).append("\\").append(path);

  HINSTANCE myDll = LoadLibraryExA(folderPath.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
  if (!myDll) {
    DWORD err = GetLastError();

    String errorString = "Could not find dll at given path: ";

    return nullptr;
  }
  std::cout << "Loading " << path << "..." << std::endl;
  
  G_FACTORY t_api = (G_FACTORY)GetProcAddress(myDll, functionName.c_str());
  if (!t_api) {
    std::cout << "could not find specified function" << std::endl;

    std::cout << "Press any key to continue...";

    FreeLibrary(myDll);
    return nullptr;
  }
  std::cout << "Press any key to continue...";
  return t_api();

  //FreeLibrary(myDll);
}

#pragma endregion DEPRECATED


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPWSTR    lpCmdLine,
  _In_ int       nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  
  //GraphicsAPI* m_api;

  MyRegisterClass(hInstance);

  String pathDXAPI = "nauGraphicsDX";
  String pathGAAPI = "nauGAInput";

  //g_graphicsAPI = reinterpret_cast<GraphicsAPI*>(loadDLL(pathDXAPI, "createPluginAPI"));
  //g_inputManager = reinterpret_cast<InputManager*>(loadDLL(pathGAAPI, "createPluginAPI"));

  BaseApp::startUp<TestApp>();
  //Initialize app
  if (!InitInstance(hInstance, nCmdShow)) {
    return FALSE;
  }
  if (!BaseApp::instance().initApp(g_hWnd)) {
    return FALSE;
  }

  HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(1));

  MSG msg;

  //Main Loop
  while (GetMessage(&msg, nullptr, 0, 0))
  {
    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    BaseApp::instance().update();
    

    BaseApp::instance().render();
  }

  return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
  WNDCLASSEXW wcex;

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIconW(hInstance, MAKEINTRESOURCE(IDI_GRAFICAS21));
  wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GRAFICAS21);
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIconW(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

  return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  hInst = hInstance;

  g_hWnd = CreateWindowExW(0, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, nullptr, nullptr, hInstance, nullptr);

  if (!g_hWnd)
  {
    return FALSE;
  }

  ShowWindow(g_hWnd, nCmdShow);
  UpdateWindow(g_hWnd);

  return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message)
  {
  case WM_COMMAND:
  {
    int wmId = LOWORD(wParam);
    switch (wmId)
    {
    case IDM_ABOUT:
      DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
      break;
    case IDM_EXIT:
      DestroyWindow(hWnd);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
  }
  break;
  case WM_PAINT:
  {
    PAINTSTRUCT ps;
    EndPaint(hWnd, &ps);
  }
  break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
  UNREFERENCED_PARAMETER(lParam);
  switch (message)
  {
  case WM_INITDIALOG:
    return (INT_PTR)TRUE;

  case WM_COMMAND:
    if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
    {
      EndDialog(hDlg, LOWORD(wParam));
      return (INT_PTR)TRUE;
    }
    break;
  }
  return (INT_PTR)FALSE;
}