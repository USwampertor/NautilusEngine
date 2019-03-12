/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file main.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/24 2018
 * @brief Graphics testing with different graphic apis
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include <d3d11.h>
#include <vector>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <nauGraphicsAPI.h>

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

using namespace nauEngineSDK;
using std::vector;
#define MAX_LOADSTRING 100

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


typedef void* (*G_API)();

void* 
loadDLL(String path) {
  
  std::cout << path << std::endl;

  char dirPath[MAX_PATH];
  GetCurrentDirectoryA(MAX_PATH, dirPath);
  String folderPath(dirPath);

  folderPath = folderPath.append("\\").append(path);

  HINSTANCE myDll = LoadLibraryExA(folderPath.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
  if (!myDll) {
    DWORD err = GetLastError();
    std::cout << "Could not find dll at given path: " << path << std::endl;
    std::cout << err << std::endl;
    std::cout << "Press any key to continue...";
    return 0;
  }
  std::cout << "Loading " << path << "..." << std::endl;
  
  G_API t_api = (G_API)GetProcAddress(myDll, "createGraphicsAPI");
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



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPWSTR    lpCmdLine,
  _In_ int       nCmdShow)
{
  //Graphics_API GFX_API;
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  
  //DLL Loading
  GraphicsAPI* m_api;
  //

  // Global chains
//  LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//  LoadStringW(hInstance, IDC_GRAFICAS21, szWindowClass, MAX_LOADSTRING);

  MyRegisterClass(hInstance);

  String path = "nauGraphicsDXd.dll";
  
  m_api = reinterpret_cast<GraphicsAPI*>(loadDLL(path));
  if (m_api == nullptr) {
    std::cout << "Couldn't get DLL";
  }

  //Initialize app
  if (!InitInstance(hInstance, nCmdShow)) {
    return FALSE;
  }
  if (!m_api->initDevice(g_hWnd)) {
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
    m_api->onRender();
  }

  return (int)msg.wParam;
}



/**
 * @brief Registers the class
 * @param Handler instance
 * @return 
 *
 */
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

/**
 * @brief Initializes the object of the handler
 * @param 
 * @return 
 *
 */
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  hInst = hInstance; // Almacenar identificador de instancia en una variable global

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

/**
 * @brief Proccesses the info from the window
 * @param window handler, message
 * @return 
 *
 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message)
  {
  case WM_COMMAND:
  {
    int wmId = LOWORD(wParam);
    // Analizar las selecciones de menú:
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
    //HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: Agregar cualquier código de dibujo que use hDC aquí...
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

// Controlador de mensajes del cuadro Acerca de.
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