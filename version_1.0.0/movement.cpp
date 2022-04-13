#include <iostream>
#include <windows.h>
#include "header/jakach.h"
int input_buffer_get();
int input_buffer_set(int a);
int input_buffer_clear();
int player_pos_set(int x,int y);
extern int field[1000][1000];
extern int game_running;
class Player
{
	public:
		int x;
		int y;
		int buf;
};
Player player;
int player_movement()
{
	sleep(1);
	system("title factorio v1.0.0");
	player.y=10;
	player.x=10;
	gotoxy(player.x,player.y);
	printf("%c",2);
	while(true)
	{
		while(game_running==true)
		{
			player.buf=input_buffer_get();
			if(player.y<=0 or player.x<=0 or player.y > 950 or player.x > 950)
			{
				gotoxy(player.x,player.y);
				printf(" ");
				player.y=1;
				player.x=1;
				gotoxy(player.x,player.y);
				printf("%c",2);
			}
			player_pos_set(player.x,player.y);
			switch(player.buf)
			{
				case 97:
					gotoxy(player.x,player.y);
					printf(" ");
					player.x--;
					if(field[player.x][player.y]==0)
					{
						if(player.x>=1&&player.y>=1&&player.x<=950&&player.y<=950)
						{
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
						else
						{
							player.x++;
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
					}
					else
					{
						player.x++;
						gotoxy(player.x,player.y);
						printf("%c",2);
					}
					input_buffer_clear();
				break;
				case 100:
					gotoxy(player.x,player.y);
					printf(" ");
					player.x++;
					if(field[player.x][player.y]==0)
					{
						if(player.x>=1&&player.y>=1&&player.x<=950&&player.y<=950)
						{
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
						else
						{
							player.x--;
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
					}
					else
					{
						player.x--;
						gotoxy(player.x,player.y);
						printf("%c",2);
					}
					input_buffer_clear();
				break;
				case 119:
					gotoxy(player.x,player.y);
					printf(" ");
					player.y--;
					if(field[player.x][player.y]==0)
					{
						if(player.x>=1&&player.y>=1&&player.x<=950&&player.y<=950)
						{
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
						else
						{
							player.y++;
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
					}
					else
					{
						player.y++;
						gotoxy(player.x,player.y);
						printf("%c",2);
					}
					input_buffer_clear();
				break;
				case 115:
					gotoxy(player.x,player.y);
					printf(" ");
					player.y++;
					if(field[player.x][player.y]==0)
					{
						if(player.x>=1&&player.y>=1&&player.x<=950&&player.y<=950)
						{
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
						else
						{
							player.y--;
							gotoxy(player.x,player.y);
							printf("%c",2);
						}
					}
					else
					{
						player.y--;
						gotoxy(player.x,player.y);
						printf("%c",2);
					}
					input_buffer_clear();
				break;
			}
		}
		sleep(1);
	}
}
