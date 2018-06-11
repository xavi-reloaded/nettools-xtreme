/*
 * stringhelper.h
 *
 *  Created on: Jul 2, 2017
 *      Author: xavi
 */

#ifndef STRINGHELPER_H_
#define STRINGHELPER_H_

#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#include "ReplaceAll.h"


using namespace std;

const string  emptyString="";
const string  standardSingleQuote="'";
const string  standardDoubleQuote="\"";

string Trim(string str);
bool Contains(string text, string search);
int split(const char* szString, const char* szSep, vector<std::string>* saResult);
vector<string> Split(const string &str, const string &separator, bool shouldAddPlaceHolderAtBeginning=false);
int find(const char* szString, const char* szSep, int iStart);
int strToInt(string basic_string);
string intToStr(int i);



#endif /* STRINGHELPER_H_ */
