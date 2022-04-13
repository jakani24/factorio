#include <iostream>
#include "header/jakach.h"
extern unsigned long long int power_max;
extern unsigned long long int power_used;
extern unsigned long long int stored_items;
extern unsigned long long int money;
extern int game_running;
extern int items[1000];
extern int buildings[100000];
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
int kokw_buf;
void print_building_name(int id);
int build_loc(int price,int power_us,int ascii,int id);

int power_calc()
{
	int kokw,buf,i,pmb;
	kokw=0;
	while(true)
	{
		while(game_running==true)
		{
			pmb=0;
			for(i=0;i<15000;i++)
			{
				pmb+=power_p[i]*buildings[i];
			}
			power_max=pmb;
			power_used=0;
			for(i=0;i<15000;i++)
			{
				power_used+=power_us[i]*buildings[i];
			}
			Sleep(800);
		}
	}
}

int power_build_menu()
{
	char s_c[5];
	int c=0,input;
	system("cls");
	printf("Du hast %d Coins\n",money);
	c=0;
//	printf("\n\n");
	for(int i=99;i<450;i++)
	{
		if(buildings_exists[i])
		{
			c++;
			print_building_name(i-1);
			printf(", kostet %d, generiert %d Energie [%d]\n",building_costs[i],power_p[i],i-99);	
		}
	}
	std::cin>>input;
	if(input<=c)
	{
		build_loc(building_costs[input+99],0,ascii[input+99],input+99);
	}
	return 0;
}