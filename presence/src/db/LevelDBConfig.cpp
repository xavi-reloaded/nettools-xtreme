#include "LevelDBConfig.h"

using namespace leveldb;

LevelDBConfig::LevelDBConfig(std::string database) {

    this->basepath = dirBasename("/media/xavi/XAVINGUER/workspace/__test/__wifi_presence/lan001/presence-test");
    std::cout << this->basepath  << std::endl;
    Options options;
    options.create_if_missing = true;

    this->status = DB::Open(options, this->basepath + "/" + database, &this->db);
    if (false == this->status.ok())
    {
        cerr << endl << "Unable to open/create test database " << this->basepath <<  "\\" << database << endl;
        cerr << this->status.ToString() << endl;
    }
}

LevelDBConfig::~LevelDBConfig() {
    delete this->db;
}

std::string  LevelDBConfig::getValue(std::string idx)
{
    ReadOptions readOptions;
    std::string value;
    this->db->Get(readOptions, idx.c_str(), &value);
	return value;
}

void LevelDBConfig::setValue(std::string idx, std::string value)
{
    WriteOptions writeOptions;
    this->db->Put(writeOptions, idx, value);
}



