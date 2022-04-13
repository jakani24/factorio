#include <iostream>
#include <windows.h>
extern unsigned int sell_ammount[10000];
extern int buildings[100000];
extern int field[1000][1000];
extern unsigned long long int money;
extern unsigned long long int power_max;
extern unsigned long long int power_used;
extern int items[1000];
extern int render;
int load()
{
	FILE*fp;
	int i,b;
	if((fp=fopen("c:\\jakach\\factorio\\savegame\\save.jf","r"))==0)
	{
		printf("couldn't open save file.\n");
		money=2500;
		if((fp=fopen("c:\\jakach\\factorio\\savegame\\save.jf","w"))==0)
		{
			printf("couldn't regenerate save file.\n");
			system("pause");
			exit(0);
		}
	}	
	else
	{
		i=b=0;
		printf("Loading...\n");
		while(i<10000-1)
		{
			fscanf(fp,"%d",&sell_ammount[i]);
			i++;
		}
		i=0;
		while(i<100000-1)
		{
			fscanf(fp,"%d ",&buildings[i]);
			i++;
		}
		i=0;
		while(i<999)
		{
			fscanf(fp,"%d ",&items[i]);
			i++;
		}
		i=0;
		fscanf(fp,"%d %d %d\n",&money,&power_max,&power_used);
		while(i<999)
		{
			i++;
			b=0;
			while(b<999)
			{
				fscanf(fp,"%d",&field[i][b]);
				b++;
			}
			if(i%10==0)
			{
				printf("%c",177);
				//Sleep(1);
			}
		}
		fclose(fp);
		printf("\nmapping done\n");
		Sleep(100);
		system("cls");
		render=true;
	}
	return 0;
}

int save()
{
	FILE*fp;
	int i,b;
	i=b=0;
	system("cls");
	if((fp=fopen("c:\\jakach\\factorio\\savegame\\save.jf","w"))==0)
	{
		printf("couldn't open save file.\n");
		if((fp=fopen("c:\\jakach\\factorio\\savegame\\save.jf","w"))==0)
		{
			printf("couldn't regenerate save file.\n");
			system("pause");
			exit(0);
		}
	}	
	else
	{
		i=b=0;
		printf("Loading...\n");
		while(i<10000-1)
		{
			fprintf(fp,"%d ",sell_ammount[i]);
			i++;
		}
		i=0;
		while(i<100000-1)
		{
			fprintf(fp,"%d ",buildings[i]);
			i++;
		}
		fprintf(fp,"\n");
		i=0;
		while(i<999)
		{
			fprintf(fp,"%d ",items[i]);
			i++;
		}
		fprintf(fp,"\n");
		i=0;
		fprintf(fp,"%d %d %d\n",money,power_max,power_used);
		while(i<999)
		{
			i++;
			b=0;
			while(b<999)
			{
				fprintf(fp,"%d ",field[i][b]); 
				//fprintf(fp,"0 ");
				b++;
			}
			if(i%10==0)
			{
				printf("%c",177);
				//Sleep(1);
			}
			//printf("%d\n",i);
			fprintf(fp,"\n");
		}
		fclose(fp);
		printf("\nsaving done\n");
		Sleep(100);
		system("cls");
	}	
	return 0;
}