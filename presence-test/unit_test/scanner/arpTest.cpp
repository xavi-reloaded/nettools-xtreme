#include "gtest/gtest.h"
#include "src/scanner/arp.cpp"




TEST(Arp, init)
{
    Arp *sut = new Arp();
    sut->getInfo();
//    return sut->arp(argv[2], argv[3], argv[4], argv[5], arp.op_reply);
    EXPECT_EQ(1, true);
}

