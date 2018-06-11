/*
 * LevelDBConnector.h
 *
 *  Created on: Jul 10, 2017
 *      Author: xavi
 */

#ifndef LDBCONNECTOR_H_
#define LDBCONNECTOR_H_

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


class LevelDBConfig {

private:

	std::string basepath;
    DB* db;
    Status status;

public:

	LevelDBConfig(std::string database);

    LevelDBConfig();

    virtual ~LevelDBConfig();
	std::string getValue(std::string idx);
    void setValue(std::string idx, std::string value);
};

#endif /* LDBCONNECTOR_H_ */
