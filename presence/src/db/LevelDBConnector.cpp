#include "LevelDBConnector.h"

using namespace leveldb;

LevelDBConnector::LevelDBConnector() {
	this->basepath = dirBasename(getSelfPath());
    Options options;
    //options.create_if_missing = true;
    std::string database = "evcs.db";

    this->status = DB::Open(options, this->basepath + "\\" + database, &this->db);
    if (false == this->status.ok())
    {
        cerr << endl << "Unable to open/create test database " << this->basepath <<  "\\" << database << endl;
        cerr << this->status.ToString() << endl;
    }
}

LevelDBConnector::~LevelDBConnector() {
    delete this->db;
}

std::string  LevelDBConnector::getValue(std::string idx)
{
    ReadOptions readOptions;
    std::string value;
    if (false == this->status.ok())
    {
        return "";
    }
    this->db->Get(readOptions, idx.c_str(), &value);
	return value;
}

void LevelDBConnector::setValue(std::string idx, std::string value)
{
    WriteOptions writeOptions;
    this->db->Put(writeOptions, idx, value);
}


