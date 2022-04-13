#include <iostream>
#include "header/jakach.h"
extern long long int money;
extern int items[1000]; 
extern int buildings[100000];
extern unsigned long long int power_max;
extern unsigned long long int power_used;
extern unsigned long long int store_place;
extern unsigned long long int stored_items;
extern unsigned int sell_ammount[10000];
extern int game_running;
int seller(int item_id,const char item_name[50],int item_price,int input);
void buyer(int item_id,const char name[50],int price);
void print_item_name(int id);
extern int item_costs[1000];
extern int items_cnt;
void set_char(int id,char*input);
int sell_menu()
{
	system("cls");
	int input,buf;
	char buffer[100];
	printf("Du hast %d Coins\n",money);
	int i;
	for(i=0;i<items_cnt;i++)
	{
		print_item_name(i);
		printf(" bringt dir %d Coin(s) pro Item [%d]\n",item_costs[i+1],i+1);
	}
	scanf("%d",&input);
	if(input>i)
	{
		return 0;
	}
	set_char(input,buffer);
	seller(input,buffer,item_costs[input],input);
	system("pause");
	system("cls");
	return 0;
}

void auto_sell_sys(int b_id,int power_us,int cost,int item_id)
{
		if(buildings[b_id]!=1)
		{
			if(money>=cost&&power_max>=power_used+power_us)
			{
				money-=cost;
				buildings[b_id]++;
				printf("Wiviele Items sollen pro Sekunde verkauft werden?:\n");
				std::cin>>sell_ammount[item_id];
			}
			else printf("zuwenig Coins oder zuwenig Netzleistung\n");
		}
		else
		{
			printf("Wiviele Items sollen pro Sekunde verkauft werden?:\n");
			std::cin>>sell_ammount[item_id];
		}	
}
void auto_sell_menu()
{
	char i_c[15];
	int input;
	system("cls");
	printf("Autoseller k%cnnen deine Items automatisch verkaufen.\nBeachte: um die Anzahl Items, die pro Sek. verkauft werden zu %cndern\ndr%ccke nochmal die passende Nummer \n",oe,ae,ue);
	int i;
	for(i=0;i<items_cnt;i++)
	{
		printf("Autoverkaufsstation f%cr ",ue);
		print_item_name(i);
		printf(" kostet 7500 Coins, braucht 100 Energie [%d]\n",item_costs[i+1],i+1);
	}
	std::cin>>input;
	auto_sell_sys(input+10499,100,7500,input);
	system("pause");
}
int auto_seller()
{
	int cnt;
	while(true)
	{
		int i;
		sleep(1);
		if(game_running==true)
		{
		//eisenklumpen
			sleep(1);
			i=0;
			for(i=1;i<items_cnt+1;i++)
			{
				if(buildings[i+10499]==1)
				{
					if(items[i]>=sell_ammount[i])
					{
						items[i]-=sell_ammount[i];
						money+=sell_ammount[i]*item_costs[i];
					}
				}
			}
		}
	}
	return 0;
}

int seller(int item_id,const char item_name[50],int item_price,int input)
{
	printf("Du hast %d %s\nWiviel %s m%cchtest du verkaufen?:\n",items[item_id],item_name,item_name,oe);
	scanf("%d",&input);
	if(input>items[item_id])
	{
		while(input>items[item_id])
		{
			printf("Du hast nur %d %sn\nBitte neue Zahl eingeben\n",items[item_id],item_name);
			scanf("%d",&input); 
		}
	}
	else
	{
		items[item_id]-=input;
		money+=input*item_price;
	}
	printf("Verkauf erfolgreich\n");
	return 0;	
}

int buy_items()
{
	system("cls");
	int input;
	char buffer[100];
	printf("Du hast %d Coins\n\n",money);
	int i;
	for(i=0;i<items_cnt;i++)
	{
		print_item_name(i);
		printf(" kostet dich %d Coin(s) pro Item [%d]\n",item_costs[i+1],i+1);
	}
	std::cin>>input;
	if(input>i)
	{
		return 0;
	}
	set_char(input,buffer);
	buyer(input,buffer,item_costs[input]);
	return 0;
}

void buyer(int item_id,const char name[50],int price)
{
	int input;
	printf("Wiviele %s willst du kaufen?:\n",name);
	std::cin>>input;
	if(input<0)
	{
		input=0;
	}
	while(input*price>money or stored_items+input>store_place)
	{
		printf("zuwenig Coins oder zuwenig Item Speicherplatz\n");
		printf("Bitte neue Zahl eingeben");
		std::cin>>input;
	}
		money-=input*price;
		//printf("%d",input);
		//printf("%d\n",items[item_id]);
		items[item_id]+=input;
		//printf("%d\n",items[item_id]);
		printf("Kauf erfolgreich\n");
	system("pause");
}