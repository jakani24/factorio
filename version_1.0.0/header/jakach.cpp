#include <windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
//#include "jakach.h"
#ifndef JAKACH_CPP
#define JAKACH_CPP
inline void gotoxy (int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coordinate);
}

inline void clrscr()
{
	system("cls");
}

inline void debug(const char message[100])
{
	MessageBox(NULL,message,"DEBUG",MB_OK);
}

inline void delay(int msc)
{
	Sleep(msc);
}
inline void os_time(char* time_,char* date_)
{
	char buf[40];
	char buf_date[40];
	time_t now = time(NULL);
	struct tm tstruct;
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	strftime(buf_date, sizeof(buf_date), "%Y-%m-%d", &tstruct);
	strncpy(time_,buf,sizeof(buf));        
	strncpy(date_,buf_date,sizeof(buf_date));                                                                                                                                                                        
}
inline int logger_log(const char path[300],const char message[300],int a,int b)
{
	FILE*fp;
	char time[100];
	char date[100];
	char buf[500];
	os_time(time,date);
	strcpy_s(buf,time);
	strcat_s(buf,":");
	strcat_s(buf,date);
	if((fp=fopen(path,"a"))==0)
	{
		if((fp=fopen(path,"w"))==0)
		{
			return 0;
		}
		else
		{
			fclose(fp);
			return 1;
		}
	}
	else
	{
		fprintf(fp,"[%s] %s %d %d\n",buf,message,a,b);
		fclose(fp);
	}
	return 2;
}

inline int getkey()
{
	int a;
	if(kbhit())
	{
		a=getch();
	}
	return a;
}

inline void clearclipboard()
{
	if(!OpenClipboard(NULL))
		return;

	EmptyClipboard();
	CloseClipboard();
}
inline void setclipboard(const char *str)
{
	if(!OpenClipboard(NULL))
		return;

	EmptyClipboard();

	HGLOBAL hClipboardData;
	hClipboardData = GlobalAlloc(GMEM_DDESHARE, strlen(str)+1);

	char *pchData;
	pchData = (char*)GlobalLock(hClipboardData);
	strcpy(pchData, str);

	GlobalUnlock(hClipboardData);

	SetClipboardData(CF_TEXT, hClipboardData);

	CloseClipboard();
}
inline void numtostr(char*str,int num,int max)
{
	//_itoa(num,str,max);
	sprintf( str, "%d", num);
}
#endif