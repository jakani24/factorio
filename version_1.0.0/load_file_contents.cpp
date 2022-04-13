#include <iostream>
#include "header/jakach.h"
extern char item_names[50000];
extern int items_cnt;
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
int load_item(int id,int *cost,char*name)
{
	FILE*fp;
	char buffer[50];
	char path[500];
	numtostr(buffer,id,40);
	strcpy_s(path,"c:\\jakach\\factorio\\gamefiles\\data\\items\\");
	strcat_s(path,buffer);
	strcat_s(path,".jff");
	if((fp=fopen(path,"r"))==0)
	{
		return 0;
	}
	else
	{
		items_cnt++;
		fscanf(fp,"%20s",&buffer);
		fscanf(fp,"%50s",name);
		fscanf(fp,"%20s",&buffer);
		fscanf(fp,"%d",&id);
		fscanf(fp,"%20s",&buffer);
		fscanf(fp,"%d",cost);
		fclose(fp);
	}
	return 1;
}
int load_building(int id,char*name)
{
	FILE*fp;
	char buffer[50];
	int buf_;
	char path[500];
	numtostr(buffer,id,40);
		//	printf("%d %s\n",id,buffer);
	strcpy_s(path,"c:\\jakach\\factorio\\gamefiles\\data\\buildings\\");
	strcat_s(path,buffer);
	strcat_s(path,".jff");
	if((fp=fopen(path,"r"))==0)
	{
		//printf("%d\n",id);
		return 0;
	}
	else
	{
		//printf("%d %s\n",id,path);
		buildings_exists[id]=1;
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&prod[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&prodspeed[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&power_us[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&building_costs[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%50s",name);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&buf_);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&uses_1[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&uses_2[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&uses_3[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&ammount_1[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&ammount_2[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&ammount_3[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&ascii[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&storage_p[id]);
		fscanf(fp,"%20s",&buffer);	fscanf(fp,"%d",&power_p[id]);
		//printf("[%d][%d][%d]\n",id,buf_,power_p[105]);
		//debug("hello");
		fclose(fp);
	}
	return 1;	
}
void print_item_name(int id)
{
	for(int b=0;b<50;b++)
	{
		std::cout<<item_names[(id*50)+b-1];
	}
}
void print_building_name(int id)
{
	for(int b=0;b<50;b++)
	{
		std::cout<<building_names[(id*50)+b-1];
	}
}
void set_char(int id,char*input)
{
	int b;
	for(b=0;b<50;b++)
	{
		input[b]=item_names[(id*50)+b-1];
	}
	input[b+1]='\0';
}