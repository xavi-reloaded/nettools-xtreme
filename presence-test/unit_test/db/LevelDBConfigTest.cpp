#include <src/db/LevelDBConfig.h>
#include "gtest/gtest.h"


TEST(leveldbconfig_test, init_with_fake_value)
{
    std::string database = "evcs-conf";
    LevelDBConfig *sut = new LevelDBConfig(database);
    sut->setValue("patata","is very nice");
    std::string actual = sut->getValue("patata");
    EXPECT_EQ(actual, "is very nice");
}