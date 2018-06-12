#include "gtest/gtest.h"
#include "src/tins/icmp_responses.cpp"




TEST(icmp_responses, init)
{
    const int type = 3;
    const int code = 0;
    NetworkInterface iface;
    iface = NetworkInterface::default_interface();
    string filter = "tcp port 80";
    try {
        ICMPResponder responder(iface.name(), type, code);
        responder.run(filter);
    }
    catch (exception& ex) {
        cout << "Error: " << ex.what() << endl;
    }


}