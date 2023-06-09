#include "integerWriter.h"

void integerWriter::intWrite(int num, int R, int G, int B)
{

        // Set the text color and background color
        SetTextColor(hdc, RGB(R, G, B)); // Black color
        SetBkMode(hdc, TRANSPARENT);    // Transparent background

        // Define the integer to be printed
        int number = 42;

        // Format the integer into a string
        wchar_t buffer[10];
        swprintf_s(buffer, L"%d", number);

        // Calculate the position for displaying the integer
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        int x = (clientRect.right - clientRect.left) / 2; // Center horizontally
        int y = (clientRect.bottom - clientRect.top) / 2; // Center vertically

        // Draw the integer on the screen
        DrawTextW(hdc, buffer, -1, &clientRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}

integerWriter::integerWriter(HDC uHdc, HWND uHWnd)
{
    hdc = uHdc;
    hWnd = uHWnd;
}