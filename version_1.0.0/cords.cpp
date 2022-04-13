#include <iostream>
#include <windows.h>
#include <conio.h>
#include "header/jakach.h"
HWND hWnd = GetConsoleWindow();
POINT pos={0,0};
int x,y,clicked;
int get_console_mouse_cords(int show_gui)
{
	Sleep(100);
	if(show_gui==true)
	{
		gotoxy(0,0);
		printf("Rechtsklicke eine Position, bei dieser wird dein Geb%cude gebaut/abgerissen\n(Dr%ccke auf den Text in der ersten Zeile, um den Vorgang abzubrechen)\n",ae,ue);
	}
		//if((getch())==32)
		clicked=0;
		while(clicked==0)
		{
			clicked=GetKeyState(VK_RBUTTON) & 0x8000;
		}
		if (clicked)
		{
			GetCursorPos(&pos);
			ScreenToClient(hWnd, &pos);
			RECT rcClient = {0};
			GetClientRect(hWnd, &rcClient);
			PtInRect(&rcClient, pos);
			CONSOLE_SCREEN_BUFFER_INFO info = {0};
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
			const SMALL_RECT& smRect = info.srWindow;
			
			// calculate row and column corresponding to mouse position
			// (note this takes accounts of console buffer scrolling)
			x = smRect.Left + (pos.x * (smRect.Right  - smRect.Left)) / (rcClient.right  - rcClient.left);
			y = smRect.Top  + (pos.y * (smRect.Bottom - smRect.Top )) / (rcClient.bottom - rcClient.top );
		}
	return 0;
}
int get_x()
{
	return x;	
}
int get_y()
{
	return y;
}