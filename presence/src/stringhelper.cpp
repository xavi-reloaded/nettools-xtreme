
#include "stringhelper.h"
#include <iostream>

bool Contains(string text, string search)
{
	int position = text.find(search);
	if(position!=string::npos)return true;
	return false;
}

/*! Removes spaces from beginning and end of a string
 * \param str string to be trimmed
 * \returns trimmed string
 */

// trim from start
static inline std::string& TrimLeft(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace))));
	return s;
}

// trim from end
static inline std::string& TrimRight(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}

// trim from both ends
string Trim(string str)
{
	return TrimLeft(TrimRight(str));
}
int find(const char* szString, const char* szSep, int iStart)
{
	int r = -1;
	int i = iStart;
	string csStr, csTmp;

	csStr = szString;
	while( (i = csStr.find(szSep[0], i)) > -1 )
	{
		csTmp = csStr.substr(i, strlen(szSep));
		if(csTmp.compare(szSep) == 0)
		{
			r = i;
			break;
		}
		else i++;
	}

	return r;
}


int split(const char* szString, const char* szSep, vector<std::string>* saResult)
{
	int i;
	string csCopy;

	saResult->clear();

	csCopy = szString;
	while( (i = find(csCopy.c_str(), szSep, 0)) > -1 )
	{
		saResult->push_back(csCopy.substr(0, i));
		csCopy = csCopy.substr(i + strlen(szSep));
	}
	saResult->push_back(csCopy);

	return saResult->size();
}


vector<string> Split(const string &str, const string &separator, bool shouldAddPlaceHolderAtBeginning)
{
	vector<string> results;
	string temporaryString;
	if(str.empty())return results;
	if(separator.empty())
	{
		results.push_back(str);
		return results;
	}
	int found = str.find(separator);
	if(found==0 && shouldAddPlaceHolderAtBeginning)
	{
		results.push_back("");
	}
	temporaryString=str;
	while(found != string::npos)
	{
		if(found > 0)results.push_back(temporaryString.substr(0,found));
		temporaryString = temporaryString.substr(found+separator.size());
		if(shouldAddPlaceHolderAtBeginning)
		{
			if(found+separator.size()==str.size())results.push_back("");
		}
		found = temporaryString.find(separator);
	}

	if(temporaryString.length() > 0)
	{
		results.push_back(temporaryString);
	}

	if(results.size()==0)results.push_back(str);
	return results;
}


int strToInt(string str) {
	if (str=="") return 0;
	int x;
	sscanf(str.c_str(), "%d", &x);
	return x;
}

string intToStr(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}



