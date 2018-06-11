//
// Created by xavi on 1/18/2018.
//

#ifndef EVCS_LEVELDB_LOGADAPTER_H
#define EVCS_LEVELDB_LOGADAPTER_H

#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <cstdio>
#include <stdlib.h>
#include "config.h"
#include <iostream>


class LogAdapter {

    public:

        static void writeLog(std::string ean);
        static std::string getTimeString();
        static std::string getIdFarmacia();
        static std::string getIdPOS();
        static std::string getEVCSLog(std::string ean);
        static void writeLog2File(std::string ean);
        static void writeErrorLog2File(std::string error);

    static bool getIsActive();

//        static _init s_initializer;
};


#endif //EVCS_LEVELDB_LOGADAPTER_H
