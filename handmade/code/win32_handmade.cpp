#include <Windows.h>

LRESULT CALLBACK MainWindowCallback(
HWND hwnd, 
UINT uMsg, 
WPARAM wParam, 
LPARAM lParam ) {

    LRESULT Result = 0;

    switch (uMsg)
    {
        case WM_SIZE: {
            OutputDebugStringA("WM_SIZE\n");
        }
        break;

        case WM_DESTROY: {
            OutputDebugStringA("WM_DESTROY\n");
        }
        break;

        case WM_CLOSE: {
            OutputDebugStringA("WM_CLOSE\n");
        }
        break;

        case WM_ACTIVATEAPP: {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        }
        break;
        
        default:
            Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
            break;
    }

    return Result;
}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    WNDCLASS WindowClass = {};

    WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW; 
    WindowClass.lpfnWndProc = MainWindowCallback; 
    WindowClass.hInstance = hInstance; 
    WindowClass.lpszClassName = "HandmadeHeroWindowClass";

    if(RegisterClass(&WindowClass)) {
        HWND hwnd = CreateWindowEx( 0, 
                                    WindowClass.lpszClassName, 
                                    "Handmade Hero", 
                                    WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
                                    CW_USEDEFAULT, 
                                    CW_USEDEFAULT, 
                                    CW_USEDEFAULT, 
                                    CW_USEDEFAULT, 
                                    0, 
                                    0, 
                                    WindowClass.hInstance, 
                                    0);
        if(hwnd) {
            MSG Message;
            for(;;) {
                BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
                if(MessageResult > 0) {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                }
                else {
                    break;
                }
            }
        }
        else {

        }
    }
    else {

    }

    return 0;
}