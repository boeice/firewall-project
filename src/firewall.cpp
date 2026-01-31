#include "packets.h" 
#include "firewall.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

Firewall::Firewall() {
	ip_rules = {
	 {"192.168.1.1", "LOG"},
	 {"127.0.0.1", "DROP"},
	 {"0.0.0.0", "REJECT"},
	 {"192.168.1.9", "LOG"},
	 {"8.8.8.8", "REJECT"},
	 {"192.168.1.13", "REJECT"},
	 {"192.168.1.17", "BLOCK"}
	};
	port_rules = {
	 {21, "BLOCK"},
	 {23, "REJECT"},
	 {25, "DROP"},
	 {445, "BLOCK"},
	 {3389, "REJECT"},
	};
	protocol_rules = {
	 {"ICMP", "BLOCK"},
	 {"UDP", "DROP"},
	 {"HTTP", "REJECT"},
	 {"Telnet", "BLOCK"},
	 {"SMB", "REJECT"},
	};
}
void Firewall::PACKETS_LIST(Packets& p) {
	packetsList.push_back(p);
}
void Firewall::CHECK_PACKETS(Packets& p) {
	for (int i = 0; i < packetsList.size(); i++)
	{
		bool found = false;
		if (ip_rules.find(packetsList[i].get_ip_source()) != ip_rules.end()) {
			result.push_back(ip_rules[packetsList[i].get_ip_source()]);
			found = true;
		}
		else if (ip_rules.find(packetsList[i].get_ip_destination()) != ip_rules.end()) {
			result.push_back(ip_rules[packetsList[i].get_ip_destination()]);
			found = true;
		}
		else if (port_rules.find(packetsList[i].Get_PORT()) != port_rules.end()) {
			result.push_back(port_rules[packetsList[i].Get_PORT()]);
			found = true;
		}
		else if (protocol_rules.find(packetsList[i].Get_PROTOCOL()) != protocol_rules.end()) {
			result.push_back(protocol_rules[packetsList[i].Get_PROTOCOL()]);
			found = true;
		}
		if (!found) result.push_back("ALLOW");
	}
}
	void Firewall::PRINT_PACKETS() {
		for (int i = 0; i < packetsList.size(); i++) {
			cout << "Packet " << i + 1 << ": "
				<< packetsList[i].get_ip_source() << " -> "
				<< packetsList[i].get_ip_destination()
				<< " | Port: " << packetsList[i].Get_PORT()
				<< " | Protocol: " << packetsList[i].Get_PROTOCOL()
				<< " | Action: " << result[i]
				<< "\n";
		}
	}
