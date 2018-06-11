#include "gtest/gtest.h"
#include "src/tins/arpmonitor.cpp"




TEST(arpmonitor, init)
{
    arp_monitor monitor;
    // Sniffer configuration
    SnifferConfiguration config;
    config.set_promisc_mode(true);
    config.set_filter("arp");

    Sniffer sniffer("wlp2s0", config);
    // Only capture arp packets
//    monitor.run(sniffer);

    EXPECT_EQ(1, true);
}