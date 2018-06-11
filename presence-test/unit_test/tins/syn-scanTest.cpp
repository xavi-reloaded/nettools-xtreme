#include "gtest/gtest.h"
#include "src/tins/syn-scan-network.cpp"

TEST(synscan, init)
{
    start_scan("192.168.31.1");
}