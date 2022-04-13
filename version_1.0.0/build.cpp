#include <iostream>
#include "header/jakach.h"
#include <windows.h>
extern int field[1000][1000];
extern int buildings[100000];	
extern unsigned long long int money;
extern unsigned long long int power_max;
extern unsigned long long int power_used;
extern int building_costs[100000];
int buy_items();
void auto_sell_menu();
int fabrics_build_menu();
int get_console_mouse_cords(int show_gui);
int get_x();
int get_y();
int mines_menu();
int power_build_menu();
int logistics_build_menu();
int sell_menu();
int show_inv();
int input_buffer_clear();
int save();
int delete_menu();
extern int render;
int build_menu()
{
	int input,y,x;
	char i_c[5];
	gotoxy(0,0);
	system("cls");
	printf("Fabriken[1]\n");
	printf("Lager[2]\n");
	printf("Energieproduktion[3],\n");
	printf("Minen[4]\n");
	printf("Geb%cude L%cschen[5]\n",ae,oe);
	printf("Automatisch Item verkaufsstationen[6]\n");
	printf("Items Verkaufen[7]\n");
	printf("Items anzeigen[8]\n");
	printf("Items kaufen[9]\n");
	printf("\nZur%cck zum Spiel[97]\n",ue);
	printf("Speichern[98]\n");
	printf("Speicher & beenden[99]\n");
	scanf("%3s",&i_c);
	if((strcmp(i_c,"1"))==0)
	{
		fabrics_build_menu();
	}
	else if((strcmp(i_c,"2"))==0)
	{
		logistics_build_menu();
	}
	else if((strcmp(i_c,"3"))==0)
	{
		power_build_menu();
	}
	else if((strcmp(i_c,"4"))==0)
	{
		mines_menu();
	}
	else if((strcmp(i_c,"5"))==0)
	{
		delete_menu();
	}
	else if((strcmp(i_c,"6"))==0)
	{
		auto_sell_menu();
	}
	else if((strcmp(i_c,"7"))==0)
	{
		sell_menu();	
	}
	else if((strcmp(i_c,"8"))==0)
	{
		show_inv();
	}
	else if((strcmp(i_c,"9"))==0)
	{
		buy_items();
	}
	else if((strcmp(i_c,"98"))==0)
	{
		save();
	}
	else if((strcmp(i_c,"99"))==0)
	{
		save();
		exit(0);
	}
	return 0;
}

int delete_menu()
{
	clearclipboard();
	int x,y,id;
	system("cls");
	gotoxy(0,0);
	render=true;
	Sleep(150);
	gotoxy(0,0);
	get_console_mouse_cords(true);
	x=get_x();
	y=get_y();
	if(x<950&&y<950)
	{
		id=field[x][y];
		field[x][y]=0;
		if(id!=0&&id<15000)
		{
			buildings[id]--;
			money+=building_costs[id]/2;
		}
	}
	else
	{
		printf("maximum build limit: 950*950\n");
		system("pause");
	}
	input_buffer_clear();
	return 0;
}

int build_loc(int price,int power_us,int ascii,int id)
{
	char s_c[5];
	int x,y;
	if(money>=price)
	{
		if(power_used+power_us<=power_max or power_us==0)
		{
			printf("Wie willst du dein Geb%cude bauen?\nPer Koordinaten[1]\nPer Mausklick[2]\n",ae);
			scanf("%2s",&s_c);
			if((strcmp(s_c,"2"))==0)
			{
				system("cls");
				render=true;
				Sleep(150);
				gotoxy(0,0);
				get_console_mouse_cords(true);
				x=get_x();
				y=get_y();
			}
			else if((strcmp(s_c,"1"))==0)
			{
				printf("Koordinate: X:\n");
				scanf("%d",&x);
				printf("Koordinate: Y:\n");
				scanf("%d",&y);
			}
			if(field[x][y]==0)
			{
				if(y<950&&y>2&&x<950&&x>2)
				{
					field[x][y]=id;
					money-=price;
					buildings[id]+=1;
					printf("Geb%cude wurde gebaut\n",ae);
				}
				else
				{
					printf("Maximale/Minimale Koordinaten sind: 2-950\n");
				}
			}
			else
			{
				printf("Dort steht bereits etwas\n");
			}
		}
		else
		{
			printf("Nicht genug Netzleistung\n");
		}
	}
	else
	{
		printf("Nicht genug Geld\n");
	}
	system("pause");	
	return 0;
}