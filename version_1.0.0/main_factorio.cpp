#include <iostream>
#include <thread>
#include <windows.h>
//#include <winsock.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int interactions();
int player_movement();
int game_core();
int auto_seller();
int load();
int renderer();
int tile_index();
int input_worker_loop();
int item_production();
int power_calc();
int logistics_calc();
int load_item(int id,int *cost,char*name);
int load_building(int id,char*name);
void gotoxy(int x,int y);
extern int game_running;
extern int item_costs[1000];
extern char item_names[50000];
extern char building_names[600000];
extern int render;
void show_inv_();
extern int items_cnt;
#define debug
int main(int argc, char** argv)
{
	system("title factorio: loading...");
	system("mkdir c:\\jakach");
	system("mkdir c:\\jakach\\factorio");
	system("mkdir c:\\jakach\\factorio\\savegame");
	system("mkdir c:\\jakach\\factorio\\gamefiles");
	system("mkdir c:\\jakach\\factorio\\gamefiles\\data");	
	system("cls");
	printf("processid:%d",GetCurrentProcessId());
	Sleep(10);
	system("cls");
	load();
	int i=0,f=0;
	while(i!=1000)
	{
		i++;
		load_item(i,&item_costs[i],&item_names[f]);
		f+=50;
	}
	i=f=0;
	int c;
	printf("Loading Items & Buildings\n");
	while(i!=15000)
	{
		i++;
		c=i;
		load_building(i,&building_names[f]);
		//printf("%d\n",i);
		if(c%150==0)
		{
			printf("%c",177);
		}
		f+=50;
	}
//	for(int i=0;i<49999;i++)
//	{
//		printf("%c",building_names[i]);
//	}
//	system("pause");
	system("title factorio: starting threads");
	//fullscreen
	#ifndef debug
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	#endif
	//\fullscreen
	std::thread threadObj2 (interactions);
	std::thread threadObj3 (player_movement);
	std::thread threadObj4 (input_worker_loop);
	std::thread threadObj5 (renderer);
	std::thread threadObj6 (item_production);
	std::thread threadObj7 (power_calc);
	std::thread threadObj8 (logistics_calc);
	std::thread threadObj9 (auto_seller);
	render=true;
	game_running=true;
	sleep(2);
	gotoxy(0,0);
	printf(" ");
	//threadObj1.join ();
	threadObj2.join ();
	threadObj3.join ();
	threadObj4.join ();
	threadObj5.join ();
	threadObj6.join ();
	threadObj7.join ();
	threadObj8.join ();
	threadObj9.join ();
	return 0;
}
