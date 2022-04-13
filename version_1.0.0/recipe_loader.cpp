#include "header/jakach.h"
#include <iostream>

void read_main_file()
{
	FILE*fp;
	FILE*data;
	char filename[255];
	if((fp=fopen("c:\\jakach\\factorio\\game_files\\data\\main.jf","r"))==0)
	{
		if((fp=fopen("c:\\jakach\\factorio\\game_files\\data\\main.jf","w"))==0)
		{
			debug("critical error: Die Hauptdatei konnte nicht wiederhergestellt werden![error]\n");
			getch();
			exit(12);
		}
	}
	else
	{
		while(feof(fp)!=EOF)
		{
			fscanf(fp,"%250s",&filename);
			if((data=fopen(filename,"r"))==0)
			{
				logger_log("c:\\jakach\\factorio\\logs\\log.txt","couldnt open datafile.",0,0);
			}
			else
			{
				
			}
		}
	}
}