#include <iostream>
#include <windows.h>
#include "header/jakach.h"
int error_timeout=5;
extern int buildings[100000];
extern int field[1000][1000];
extern unsigned long long int money;
extern unsigned long long int power_max;
extern unsigned long long int power_used;
extern unsigned long long int store_place;
extern unsigned long long int stored_items;
extern int game_running;
extern int render;
extern int items[1000];
int get_console_mouse_cords(int show_gui);
int get_x();
int get_y();
void gotoxy(int x,int y);
int build_loc(int price,int power_us,int ascii,int id);
int build_menu();
extern int items_max_produced[1000],items_max_used[1000];
extern char building_names[600000];
extern int prod[100000];
extern int prodspeed[100000];
extern int power_us[100000];
extern int building_costs[100000];
extern int uses_1[100000];
extern int uses_2[100000];
extern int uses_3[100000];
extern int ammount_1[100000];
extern int ammount_2[100000];
extern int ammount_3[100000];
extern int ascii[100000];
extern int storage_p[100000];
extern int power_p[100000];
extern int buildings_exists[100000];
int item_production()
{
	int i,ok,uses_1_,uses_2_,uses_3_;
	while(true)
	{
		sleep(1);
		while(game_running==true)
		{
			sleep(1);
			error_timeout--;
			for(i=0;i<15000;i++)
			{
				ok=true;
				if(buildings_exists[i]!=0)
				{
					items[0]=0;
					if(power_used<=power_max&&stored_items<store_place)
					{
						uses_1_=uses_1[i];
						if(items[uses_1_]<ammount_1[i]*buildings[i])
						{
							ok=false;
						}
						uses_2_=uses_2[i];
						if(items[uses_2_]<ammount_2[i]*buildings[i])
						{
							ok=false;
						}
						uses_3_=uses_3[i];
						if(items[uses_3_]<ammount_3[i]*buildings[i])
						{
							ok=false;
						}
						if(ok==true)
						{
							items[prod[i]]+=prodspeed[i]*buildings[i];
							items[uses_1[i]]-=ammount_1[i]*buildings[i];
							items[uses_2[i]]-=ammount_2[i]*buildings[i];
							items[uses_3[i]]-=ammount_3[i]*buildings[i];
						}
					}
					else if(power_used>power_max&&error_timeout<=0)
					{
						error_timeout=5;
						game_running=false;
						system("cls");
						gotoxy(0,0);
						printf("ERROR: Du brauchst zuviel Energie, upgrade dein Netzwerk/deine Energieerzeugung.\nAlle deine Verbraucher wurden heruntergefahren!\n");
						system("pause");
						build_menu();
						game_running=true;
						render=true;
					}
					else if(stored_items>store_place)
					{
						game_running=false;
						system("cls");
						gotoxy(0,0);
						//printf("%d %d\n",stored_items,store_place);
						printf("ERROR: Du brauchst zuviel Itemplatz, upgrade deine Logistik.\nAlle deine Hersteller wurden heruntergefahren!\n");
						system("pause");
						build_menu();
						game_running=true;
						render=true;
					}
				}
			}
		}
	}
}

