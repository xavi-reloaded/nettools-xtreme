#include "gtest/gtest.h"
#include "src/scanner/arpscanner.cpp"


ARPScanner *sut = new ARPScanner();
const std::string DEFAULT_ARPSCAN_PARAMETERS = "--localnet";

TEST(arpscanner, init)
{
    bool actual = sut->init(DEFAULT_ARPSCAN_PARAMETERS);
    EXPECT_EQ(actual, true);
}


TEST(arpscanner, scanLocalNetwork)
{
    sut->init(DEFAULT_ARPSCAN_PARAMETERS);
    std::set<std::string> actual = sut->scanLocalNetwork();
    std::cout << sut->getLastErrorString() << "\n";
    EXPECT_EQ(actual.size()>2,true);
}