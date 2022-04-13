#include <iostream>
#include <windows.h>

extern int field[1000][1000];
int init_field()
{
	int i,b;
	i=b=0;
	printf("Loading...\n");
	while(i<999)
	{
		i++;
		while(b<999)
		{
			field[i][b]=0;
			b++;
		}
		if(i%10==0)
		{
			printf("%c",177);
			Sleep(1);
		}
	}
	printf("\nmapping done\n");
	system("pause");
	system("cls");
	return 0;
}

int game_core()
{
	return 0;
}
