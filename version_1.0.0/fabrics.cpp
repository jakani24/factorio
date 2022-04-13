#include <iostream>
#include <windows.h>

extern int buildings[100000];
extern int field[1000][1000];
extern unsigned long long int money;
extern unsigned long long int power_max;
extern unsigned long long int power_used;
extern unsigned long long int store_place;
extern unsigned long long int stored_items;
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
extern int game_running;
extern int render;
extern int items[1000];
int get_console_mouse_cords(int show_gui);
int get_x();
int get_y();
void gotoxy(int x,int y);
int build_loc(int price,int power_us,int ascii,int id);
int build_menu();
void print_item_name(int id);
void print_building_name(int id);
int fabric_core()
{
	
}

int build_building(int building_id)
{
	buildings[building_id]++;
}

int destroy_building(int building_id)
{
	buildings[building_id]--;
}

int fabrics_build_menu()
{
	char s_c[5];
	int i=0,c=0,input;
	system("cls");
	printf("Du hast %d Coins\n",money);
	c=0;
	for(i=999;i<1500;i++)
	{
		if(buildings_exists[i]!=0)
		{
			print_building_name(i-1);
			printf(", kostet %d Coins, braucht %d Energie, produziert %d ",building_costs[i],power_us[i],prodspeed[i]);
			print_item_name(prod[i]-1);
			printf("/s\n");
			if(uses_1[i]!=0&&ammount_1[i]!=0)
			{
				printf("braucht %d ",ammount_1[i]);
				print_item_name(uses_1[i]-1);
			}
			if(uses_2[i]!=0&&ammount_2[i]!=0)
			{
				printf(", %d ",ammount_2[i]);
				print_item_name(uses_2[i]-1);
			}
			if(uses_3[i]!=0&&ammount_3[i]!=0)
			{
				printf(", %d ",ammount_3[i]);
				print_item_name(uses_3[i]-1);
			}
			printf(" [%d]\n",i-999);
			//printf("debug: prod[i]=%d\n",prod[i]);
			c++;
		}
	}
	std::cin>>input;
	if(input<=c)
	{
		build_loc(building_costs[999+input],power_us[999+input],ascii[999+input],999+input);
	}
//system("pause");
}

