//
// Created by xavi on 11/26/2017.
//

#ifndef EVCS_LEVELDB_SKUIMPACTCONTROLLER_H
#define EVCS_LEVELDB_SKUIMPACTCONTROLLER_H


#include <string>
#include "LevelDBConfig.h"

class SKUImpactController {

private:
    std::string database;

public:
    SKUImpactController();
    virtual ~SKUImpactController();
    bool isImpactDayExceed(std::string);
    LevelDBConfig *levelDBConfig;
    std::string currentDay();
    int getMaxDayImpact();
};


#endif //EVCS_LEVELDB_SKUIMPACTCONTROLLER_H
