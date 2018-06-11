#include "gtest/gtest.h"
#include "src/tins/phonescan.cpp"




TEST(phonescan, init)
{
    NetworkInterface iface;
    iface = NetworkInterface::default_interface();
//    iface = NetworkInterface("wlp2s0");

    std::thread insert(receive_probe_requests, iface);
    std::thread remove(delete_devices);

    while(true) {
        sleep(10);
        {
            std::lock_guard<std::mutex> lock(map_mutex);
            std::cout << "\n" << "Number of devices in your area: " << devices.size() << std::endl;
            for(auto const &m : devices) {
                unsigned int duration = current_time_in_seconds() - m.second.seconds();
                std::cout << "[" << m.first << "] last seen " << duration << "s ago" << std::endl;
            }
            std::cout << "\n";
        }
    }


}