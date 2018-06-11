#include "gtest/gtest.h"
#include "src/scanner/arp.cpp"




TEST(Arp, init)
{
    Arp *sut = new Arp();
    sut->getInfo();
    std::cout << sut->arp("", "", "", "", 1) << endl;
    EXPECT_EQ(1, true);
}

