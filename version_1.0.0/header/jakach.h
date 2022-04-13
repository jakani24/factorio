
#include "jakach.cpp"
//ascii codes for ä,ö and
#ifndef ae
#define ae 132
#endif
#ifndef ue
#define ue 129
#endif
#ifndef oe
#define oe 148
#endif
#ifndef JAKACH_H
#define JAKACH_H
//#endif

void delay(int msc);
int logger_log(const char path[300],const char mesage[300],int a, int b);
void os_time(char* time_, char* date_);
void gotoxy(int x,int y);
int getkey();
void debug(const char message[100]);
void clrscr();
void clearclipboard();
void setclipboard(const char *str);
void numtostr(char*str,int num,int max);

#endif
