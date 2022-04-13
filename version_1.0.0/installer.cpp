#include <windows.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <ios>
#include <cstdio>
int main()
{
	system("title factorio installer");
	printf("Wilkomen beim Factorio Installer\n");
	printf("Bitte warten sie, whaerend Factorio installiert wird.\n");
	system("mkdir c:\\jakach");
	system("mkdir c:\\jakach\\factorio");
	system("mkdir c:\\jakach\\factorio\\savegame");
	system("mkdir c:\\jakach\\factorio\\gamefiles");
	system("move data c:\\jakach\\factorio\\gamefiles");
	rename("factorio.exe", "c:\\jakach\\factorio\\factorio.exe");
	printf("Fertig\n");
	system("pause");
	exit(0);
	return 0;
}