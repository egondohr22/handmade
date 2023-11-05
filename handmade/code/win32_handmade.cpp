#include <Windows.h>

LRESULT CALLBACK MainWindowCallback(
HWND hwnd, 
UINT uMsg, 
WPARAM wParam, 
LPARAM lParam ) {
    switch (uMsg)
    {
        case WM_SIZE: {

        }
        break;

        case WM_DESTROY: {

        }
        break;

        case WM_CLOSE: {

        }
        break;

        case WM_ACTIVATEAPP: {

        }
        break;
        
        default:
            break;
    }
}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    WNDCLASS WindowClass = {};

    WindowClass.style = CS_OWNDC; 
    WindowClass.lpfnWndProc = 0; 
    WindowClass.hInstance = hInstance; 
    // WindowClass.hIcon; 
    WindowClass.lpszClassName = L"HandmadeHeroWindowClass";

    return 0;
}