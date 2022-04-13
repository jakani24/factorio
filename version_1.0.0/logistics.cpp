#include <iostream>
#include "header/jakach.h"
#include <windows.h>

extern int buildings[100000];
extern int items[1000];
extern unsigned int sell_ammount[10000];
extern unsigned long long int store_place;
extern unsigned long long int stored_items;
extern unsigned long long int money;
extern unsigned long long int power_max;
extern unsigned long long int power_used;
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
extern int item_use[1000];
extern int item_calc[1000];
int build_loc(int price,int power_us,int ascii,int id);
void print_item_name(int id);
extern int items_cnt;
void print_building_name(int id);
void print_item_name(int id);
int logistic_centers()
{
	return 0;
}

int store_to_silo(int item_id,int cnt)
{
	if(stored_items+cnt>store_place)
	{
		return 1;
	}
	else
	{
		items[item_id]+=cnt;
	}
	return 0;
}

int take_from_silo(int item_id,int cnt)
{
	items[item_id]-=cnt;
	return 0;
}

int show_inv()
{
	printf("Coins: %d\n",money);
	printf("Netzleistung: %d\n",power_max);
	printf("Netbelastung: %d\n",power_used);
	printf("Item Speicherplatz: %d\n",store_place);
	printf("Item Speicherplatz belegt: %d\n",stored_items);
	printf("[Items]\n");
	int i;
	i=0;
	for(i=0;i<items_cnt;i++)
	{
		print_item_name(i);
		printf(": %d\n",items[i+1]);
	}
	system("pause");
	return 0;
}

int logistics_calc()
{
	int buf;
	while(true)
	{
		store_place=0;
		//store_place=buildings[500]+buildings[501];
		stored_items=0;
		for(int i=0;i<15000;i++)
		{
			if(buildings_exists[i]!=0)
			{
				store_place+=buildings[i]*storage_p[i];
			}
		}
		for(int i=0;i<950;i++)
		{
			stored_items+=items[i];
		}
		sleep(1);
	}
	return 0;
}

int logistics_build_menu()
{
	char s_c[5];
	int c=0,input;
	system("cls");
	printf("Du hast %d Coins\n",money);
	for(int i=499;i<900;i++)
	{
		if(buildings_exists[i]!=0)
		{
			print_building_name(i-1);
			printf(", kostet %d Coins, braucht %d Energie, hat Platz f%cr %d Items [%d]\n",building_costs[i],power_us[i],ue,storage_p[i],i-499);
			c++;
		}
	}
	std::cin>>input;
	if(input<=c)
	{
		build_loc(building_costs[input+499],power_us[input+499],ascii[input+499],input+499);
	}
	return 0;
}

void calc_use_prod()
{
//	for(int i=999;i<1400;i++)
//	{
//		for(int b=0;b<999;b++)
//		{
//			item_use[i]+=use_1[i]
//		}
//	}
//	for(int i=9999;i<10400;i++)
}
