#include <iostream>
#include "header/jakach.h"
int build_loc(int price,int power_us,int ascii,int id);
extern unsigned long long int money;
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
void print_item_name(int id);
void print_building_name(int id);
int mines_menu()
{
	char s_c[5];
	int c=0,input;
	system("cls");
	printf("Du hast %d Coins\n",money);
	printf("Kleine Eisenmine, kostet 450 Coins, braucht 250 Energie, generiert 1 Eisenklumpen/s [1]\n");
	printf("Grosse Eisenmine, kostet 1500 Coins, braucht 600 Energie, generiert 4 Eisenklumpen/s [2]\n");
	printf("Kleiner Kupferstollen, kostet 700 Coins, braucht 300 Energie, generiert 1 Kupfeklumpen/s [3]\n");
	printf("Kleine Kohlemine, kostet 300 Coins, braucht 250 Energie, generiert 1 Kohlest%cck/s [4]\n",ue);
	printf("Kleine Siliziummine, kostet 300 Coins, braucht 250 Energie, generiert 1 Silizium/s [5]\n");
	printf("Mittlere Siliziummine, kostet 400 Coins, braucht 400 Energie, generiert 2 Silizium/s [6]\n");
	printf("Grosse Siliziummine, kostet 600 Coins, braucht 600 Energie, generiert 4 Silizium/s [7]\n");
	printf("Kleine Alumine, kostet 150 Coins, braucht 200 Energie, generiert 1 Aluminium/s [8]\n");
	printf("Mittlere Alumine, kostet 200 Coins, braucht 250 Energie, generiert 2 Aluminium/s [9]\n");
	printf("Grosse Alumine, kostet 300 Coins, braucht 500 Energie, generiert 5 Aluminium/s [10]\n");
	printf("Kleine Uranmine, kostet 600 Coins, braucht 500 Energie, generiert 1 Uran/s [11]\n");
	printf("Grosse Uranmine, kostet 1500 Coins, braucht 900 Energie, generiert 3 Uran/s [12]\n");
	printf("\n\n");
	for(int i=9999;i<10400;i++)
	{
		if(buildings_exists[i]!=0)
		{
			print_building_name(i-1);
			printf(", kostet %d Coins, braucht %d Energie, generiert %d ",building_costs[i],power_us[i],prodspeed[i]);
			print_item_name(prod[i]-1);
			printf("/s [%d]\n",i-9999);
			c++;
		}
	}
	
	std::cin>>input;
	if(input<=c)
	{
		build_loc(building_costs[input+9999],power_us[input+9999],ascii[input+9999],input+9999);
	}
	return 0;
}