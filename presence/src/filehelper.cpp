
#include "filehelper.h"
#include <fstream>
#include <dirent.h>
#include "stringhelper.h"
#include <set>
#include <iostream>


using namespace std;

bool file2string(string* filein, string* content)
{
	content->erase();
	ifstream ifs(filein->c_str());
	if (!ifs) return false;
	string result;
	int count=0;
	while(getline(ifs, result))
	{
		if (count!=0) content->append("\n");
		content->append(result);
		count++;
	}
	ifs.close();
	return true;
}

void copy(string src, string dest)
{
	ifstream f1(src.c_str(), fstream::binary);
	ofstream f2(dest.c_str(), fstream::trunc|fstream::binary);
	f2 << f1.rdbuf();
}

bool fileExists(string fileName)
{
	ifstream fileStream(fileName.c_str(), ios::in);
	return fileStream.is_open();
}

bool removeFile(string fileName)
{
	if(remove(fileName.c_str()) != 0 )return false;
	return true;
}

string file2string_wrapped(string file)
{
	string content;
	file2string(&file, &content);
	return content;
}
bool getProcessorInfo(string* info)
{
	string file = "/proc/cpuinfo";
	return file2string(&file, info);
}

bool string2file(const char* filePath, string contents)
{
	bool r = false;

	ofstream file(filePath);
	if(file.is_open())
	{
		file.write(contents.c_str(), contents.length());
		r = true;
	}

	return r;
}

vector<string> getFilesInFolderByExtension(string path, string extension)
{
	vector<string> filesVector;
	DIR* directory = opendir(path.c_str());
	set<string> files;
	if(directory == NULL)return filesVector;
	if(directory!=NULL)
	{
		dirent* dirElement;
		extension=ReplaceAll(extension, ".", "");
		while((dirElement = readdir(directory))!=NULL)
		{
			string currentFileName(dirElement->d_name);
			vector<string> fileElement = Split(currentFileName,".");
			if(fileElement.size()>1)
			{
				if(fileElement.at(1)==extension)files.insert(fileElement.at(0));
			}
		}
		closedir(directory);
	}
	set<string>::iterator it;
	for(it=files.begin();it!=files.end();it++)
	{
		filesVector.push_back(*it);
	}
	return filesVector;
}

char* file2buffer(string file, int* dataLength)
{
	char* buffer = NULL;
	*dataLength = 0;

	ifstream fileStream(file.c_str(), ios::in|ios::binary|ios::ate);
	if(fileStream.is_open())
	{
		*dataLength = fileStream.tellg();
		fileStream.seekg (0, ios::beg);
		buffer = new char[*dataLength];
		fileStream.read(buffer, *dataLength);
		fileStream.close();
	}

	return buffer;
}

bool appendString2file(string filePath, string contents)
{
	bool r = false;

	ofstream file;
	file.open(filePath.c_str(), ios_base::app);
	if(file.is_open())
	{
		file.write(contents.c_str(), contents.length());
		file.close();
		r = true;
	}

	return r;
}

