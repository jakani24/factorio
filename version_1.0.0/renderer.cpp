#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "header/jakach.h"
int player_pos_get_y();
int player_pos_get_x();
int getascii(int x,int y);
extern int field[1000][1000];
extern int game_running;
extern int render;
extern int ascii[100000];
int renderer()
{
	int i,b,x,y;
	while(true)
	{
		Sleep(50);
		if(render==true)
		{
			render=false;
			system("cls");
			//gotoxy(0,0);
			i=0;
			while(i<999)
			{
				i++;
				b=0;
				while(b<999)
				{
					if(field[i][b]!=0)
					{
						gotoxy(i,b);
						printf("%c",getascii(i,b));
					}
					b++;
				}
			}
			y=player_pos_get_y();
			x=player_pos_get_x();
			gotoxy(x,y);
			printf("%c",2);
		}
	}
}

int getascii(int x,int y)
{
	return ascii[field[x][y]];
}