/*
 * filehelper.h
 *
 *  Created on: Jul 3, 2017
 *      Author: xavi
 */

#ifndef FILEHELPER_H_
#define FILEHELPER_H_

#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

bool file2string(string* file, string* content);
string file2string_wrapped(string file);
void copy(string src, string dest);
bool fileExists(string strFilename);
bool removeFile(string fileName);
bool getProcessorInfo(string* info);
bool string2file(const char* filePath, string contents);
vector<string> getFilesInFolderByExtension(string path, string extension);
char* file2buffer(string file, int* dataLength);
bool appendString2file(string filePath, string contents);

#endif /* FILEHELPER_H_ */
