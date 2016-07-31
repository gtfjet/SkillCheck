
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

void main() {
	double theta;
	int r, g, b, x, y, d, count=0;
	COLORREF c;
    HDC hdc    = GetDC(NULL); //entire screen
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP bm = CreateCompatibleBitmap(hdc, 1920, 1080);
	SelectObject(hdcMem, bm);
	while(1) {
		BitBlt(hdcMem, 896, 534, 130, 130, hdc, 896, 534, SRCCOPY);
		for(theta=0; theta<360; theta++) {
            x = 961+round(62*cos(theta*PI/180));
            y = 599+round(62*sin(theta*PI/180));
			c = GetPixel(hdcMem, x, y);
			//SetPixelV(hdc,x,y,RGB(0,255,0)); 
			r = GetRValue(c);
			g = GetGValue(c);
			b = GetBValue(c);
			d = fabs(r-249) + fabs(g-165) + fabs(b-157);
			if(d<50) {
				keybd_event(VK_SPACE, 0, KEYEVENTF_EXTENDEDKEY, 0);
				keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
				count++;
				printf("%i,%i\n",count,d);
			}
		}
	}
}
