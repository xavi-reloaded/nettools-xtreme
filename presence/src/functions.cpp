
#include "functions.h"
#include <stdio.h>
#include "config.h"
#include "filehelper.h"


#include<iostream>
#include<fstream>
#include<cstdlib>
#include <time.h>
#include <string.h>
#include<chrono>
#include<thread>

using namespace std;



void write_log(const char* capture)
{
	// write to file
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	char timeString[MAX_PATH];
	timeinfo = localtime(&rawtime);
	strftime(timeString, 100, "%Y-%m-%d_%H-%M-%S", timeinfo);

	FILE *file;
	file=fopen(LOGFILE,"a+");
	fputs(timeString ,file);
	fputs(" " ,file);
	fputs(capture ,file);
	fputs("\n" ,file);
	fflush(file);
}


string dirBasename(string path){
	if(path.empty())
		return string("");
	
	if(path.find("\\") == string::npos)
		return path;
	
	if(path.substr(path.length() - 1) == "\\")
		path = path.substr(0, path.length() - 1);
	
	size_t pos = path.find_last_of("\\");
	if(pos != string::npos)
		path = path.substr(0, pos);
	
	if(path.substr(path.length() - 1) == "\\")
		path = path.substr(0, path.length() - 1);
	
	return path;
}
