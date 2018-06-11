#include <tins/tins.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <chrono>

using namespace Tins;

const unsigned int TIMEOUT = 300;

std::map<std::string, Timestamp> devices;
std::mutex map_mutex;

std::string vendor_string(HWAddress<6> macaddr) {
	return macaddr.to_string();
}

void process(Packet p) {
	Timestamp t = p.timestamp();
	if (p.pdu()->find_pdu<Dot11ProbeRequest>(PDU::DOT11_PROBE_REQ)) {
		Dot11ProbeRequest request = p.pdu()->rfind_pdu<Dot11ProbeRequest>(PDU::DOT11_PROBE_REQ);
		std::string src_addr = vendor_string(request.addr2());
		{
			std::lock_guard<std::mutex> lock(map_mutex);
			if (devices.count(src_addr) == 0)
				std::cout << "New device [" << src_addr << "] found at " << t.seconds() << std::endl;
			devices[src_addr] = t;
		}
	}
	else if (p.pdu()->find_pdu<Dot11Data>(PDU::DOT11_DATA)) {
		Dot11Data frame = p.pdu()->rfind_pdu<Dot11Data>(PDU::DOT11_DATA);
		std::string src_addr = vendor_string(frame.addr2());
		{
			std::lock_guard<std::mutex> lock(map_mutex);
			if (devices.count(src_addr) == 1)
				devices[src_addr] = t;
		}
	}
}

void receive_probe_requests(NetworkInterface iface) {
	SnifferConfiguration config;
	config.set_rfmon(true);
//	config.set_filter("type mgt subtype probe-req || type data subtype null");
	Sniffer sniffer(iface.name(), config);
	while(true) process(sniffer.next_packet());
}

std::chrono::system_clock::rep current_time_in_seconds(){
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::seconds>(now).count();
}

void delete_devices() {
	while(true) {
		sleep(10);
		{
			std::lock_guard<std::mutex> lock(map_mutex);
			for(auto const &m : devices) {
				unsigned int duration = current_time_in_seconds() - m.second.seconds();
				if (duration > TIMEOUT) {
					std::cout << "Device [" << m.first << "] deleted after " << duration << "s of inactivity" << std::endl;
					devices.erase(m.first);
				}
			}
		}
	}
}