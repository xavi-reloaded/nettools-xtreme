/*
 * LevelDBConnector.h
 *
 *  Created on: Jul 10, 2017
 *      Author: xavi
 */

#ifndef LDBCONFIG_H_
#define LDBCONFIG_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "../functions.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "../../../include/leveldb/db.h"

using namespace leveldb;


class LevelDBConnector {

private:

	std::string basepath;
    DB* db;
    Status status;

public:

	LevelDBConnector();
	virtual ~LevelDBConnector();
	std::string getValue(std::string idx);
    void setValue(std::string idx, std::string value);
};

#endif /* LDBCONFIG_H_ */
