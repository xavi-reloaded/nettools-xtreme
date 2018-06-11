
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>

#include <stdlib.h>
#include <stdexcept>
#include <sstream>

using namespace std;

string getSelfPath();
string dirBasename(string);
void write_log(const char* capture);

#endif /* _FUNCTIONS_H */
