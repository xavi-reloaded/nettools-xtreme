//
// Created by xavi on 11/02/2017.
//

#include <src/JsonAdapter.h>
#include <src/stringhelper.h>
#include "SKUImpactController.h"

SKUImpactController::SKUImpactController() {
    this->database = "evcs-conf";
    this->levelDBConfig = new LevelDBConfig(this->database);
}

SKUImpactController::~SKUImpactController() {
    delete this->levelDBConfig;
}

bool SKUImpactController::isImpactDayExceed(std::string ean) {
    std::string retrieve = ean+"^"+this->currentDay();
    std::string impacts = this->levelDBConfig->getValue(retrieve);
    int number = strToInt(impacts);
    bool exceeded = number >= this->getMaxDayImpact();
    number=number+1;
    this->levelDBConfig->setValue(retrieve,intToStr(number));
    return exceeded;
}

int SKUImpactController::getMaxDayImpact() {
    const char* filePath = "..\\configfile.json";
    JsonAdapter jsonAdapter = JsonAdapter(filePath);
    std::string actual = jsonAdapter.get(const_cast<char *>("max_product_daily_repetitions"));
    if (actual=="") return 50;
    return strToInt(actual);
}

std::string SKUImpactController::currentDay() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    char timeString[MAX_PATH];
    timeinfo = localtime(&rawtime);
    strftime(timeString, 100, "%Y-%m-%d", timeinfo);
    return timeString;
}
