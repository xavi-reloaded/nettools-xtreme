//
// Created by xavi on 1/18/2018.
//


#include "LogAdapter.h"
#include "functions.h"


void LogAdapter::writeLog(std::string ean) {

    std::string log = getEVCSLog(ean);
    std::cout << log ;
}

void LogAdapter::writeLog2File(std::string ean) {

    std::string log = getEVCSLog(ean);
    std::string logfileFullPath = dirBasename(getSelfPath()) + "\\" + LOGFILE;
    FILE *file;
    file=fopen(logfileFullPath.c_str(),"a+");
    fputs(log.c_str() ,file);
    fflush(file);
}

std::string LogAdapter::getEVCSLog(std::string ean) {
//    id_farmacia;id_pos;ean_disparador;ean_recomendado;datetime
    return LogAdapter::getTimeString() + ";" + LogAdapter::getIdFarmacia() + ";" + LogAdapter::getIdPOS() + ";" + ean + "\n";
}

void LogAdapter::writeErrorLog2File(std::string text) {
    FILE *file;
    std::string logfileFullPath = dirBasename(getSelfPath()) + "\\" + LOGFILE;
    file=fopen(logfileFullPath.c_str(),"a+");
    fputs(LogAdapter::getTimeString().c_str() ,file);
    fputs(";" ,file);
    fputs(text.c_str() ,file);
    fputs("\n" ,file);
    fflush(file);
}

std::string LogAdapter::getTimeString() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    char timeString[MAX_PATH];
    timeinfo = localtime(&rawtime);
    strftime(timeString, 100, "%Y-%m-%d_%H-%M-%S", timeinfo);
    return timeString;
}

std::string LogAdapter::getIdFarmacia() {
    return LogAdapter::configAdapter->getIdFarmacia();
}

std::string LogAdapter::getIdPOS() {
    return LogAdapter::configAdapter->getIdPOS();
}

bool LogAdapter::getIsActive() {
    return LogAdapter::configAdapter->getIsActive();
}
