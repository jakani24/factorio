#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
int input_buffer_store(int a);
int input_buffer_get();
int input_buffer_clear();
int save();
int show_inv();
int game_running;
int build_menu();
int delete_menu();
extern int render;
int interactions()
{
	int input;
	while(true)
	{
		while(game_running==true)
		{
			Sleep(10);
			if(kbhit())
			{
				input=getch();
				input_buffer_store(input);
			}
		}
		sleep(1);
	}
	return 0;
}

int input_worker_loop()
{
	int input;
	while(true)
	{
		Sleep(20);
		input=input_buffer_get();
		switch(input)
		{
			case 27:
				game_running=false;
				system("cls");
				save();
				exit(0);
			break;
			case 98:
				game_running=false;
				build_menu();
				input_buffer_clear();
				system("cls");
				game_running=true;
				render=true;
			break;
			case 8:
				game_running=false;
				system("cls");
				delete_menu();
				input_buffer_clear();
				system("cls");
				game_running=true;
				render=true;
			break;
			case 83:
				game_running=false;
				system("cls");
				save();
				input_buffer_clear();
				game_running=true;
				render=true;
			break;
			case 114:
				render=true;
				input_buffer_clear();
			break;
			case 101:
				game_running=false;
				system("cls");
				show_inv();
				input_buffer_clear();
				render=true;
				game_running=true;
			break;
		}
	}
	return 0;
}