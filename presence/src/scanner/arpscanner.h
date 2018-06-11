
#ifndef ARPSCANNER_H
#define ARPSCANNER_H

#include <iostream>
#include <stdint.h>
#include <set>

class ARPScanner
{
public:
    ARPScanner();
    ~ARPScanner();

    bool init(std::string paramaters);

    std::set<std::string> scanLocalNetwork();

    std::string getLastErrorString();

private:
    std::string m_commandString;
    std::string m_lastErrorString;

};

#endif // ARPSCANNER_H
