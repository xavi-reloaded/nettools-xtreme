/*
 * ReplaceAll.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: xavi
 */

#include "ReplaceAll.h"

string ReplaceAll(string input,string searchString,string replaceString)
{
    int pos = 0 ;
    int lengthAntigua = input.length();
    int incremento = 0;
    pos = input.find(searchString, pos);
    do
    {
        if (pos!=-1) {
            input.replace(pos, searchString.length(), replaceString);
            incremento = input.length() - lengthAntigua;
            pos = input.find(searchString, pos + incremento + searchString.length());
        }
    }
    while (pos!=-1);
    return input;
}
