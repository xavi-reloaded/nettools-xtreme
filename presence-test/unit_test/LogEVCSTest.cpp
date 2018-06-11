#include <src/LogAdapter.h>
#include "gtest/gtest.h"



TEST(LogAdapter_test, writeLog___console__ )
{
    LogAdapter::writeLog("patata");
}

TEST(LogAdapter_test, writeLog2File___file__ )
{
    LogAdapter::writeLog2File("patata");
}

TEST(LogAdapter_test, writeErrorLog2File___file__ )
{
    LogAdapter::writeErrorLog2File("this is some error");
}

TEST(LogAdapter_test, getIdFarmacia___console__ )
{
    std::string actual = LogAdapter::getIdFarmacia();
    EXPECT_EQ(actual, "pharmid");
}

TEST(LogAdapter_test, getIdPOS___console__ )
{
    std::string actual = LogAdapter::getIdPOS();
    EXPECT_EQ(actual, "posid");
}

TEST(LogAdapter_test, getEVCSLog___console__ )
{
    std::string actual = LogAdapter::getEVCSLog("ean");
    EXPECT_FALSE(actual.empty());
}


TEST(LogAdapter_test, getActive___console__ )
{
    bool actual = LogAdapter::getIsActive();
    EXPECT_TRUE(actual);
}

