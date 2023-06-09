#include "integerWriter.h"

void integerWriter::intWrite(int num, int R, int G, int B)
{

        // Set the text color and background color
        SetTextColor(hdc, RGB(R, G, B)); // Black color
        SetBkMode(hdc, TRANSPARENT);    // Transparent background


        // Format the integer into a string
        wchar_t buffer[10];
        swprintf_s(buffer, L"%d", num);

        // Calculate the position for displaying the integer
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        int x = (clientRect.right - clientRect.left) / 2; // Center horizontally
        int y = (clientRect.bottom - clientRect.top) / 2; // Center vertically

        // Draw the integer on the screen
        DrawTextW(hdc, buffer, -1, &clientRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}
// to be implemented
// void integerWriter::intWrite(int num, int R, int G, int B, int left1, int right1, int top1, int bottom1)
// {
//    SetTextColor(hdc, RGB(R, G, B));
//    SetBkMode(hdc, TRANSPARENT);
//   wchar_t buffer[10];
//    swprintf_s(buffer, L"%d", num);
//    RECT clientRect;
//    clientRect.left = left1;
//    clientRect.right = right1;
//    clientRect.top = top1;
//    clientRect.bottom = bottom1;
//    DrawTextW(hdc, buffer, -1, &clientRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
// }

integerWriter::integerWriter(HDC uHdc, HWND uHWnd)
{
    hdc = uHdc;
    hWnd = uHWnd;
}