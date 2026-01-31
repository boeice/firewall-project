#include "firewall.h"
#include "packets.h" // i add it currently
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
void Firewall::PACKETS_LIST() {
	Packets p;
	packetsList.push_back(p);
}
void Firewall::CHECK_PACKETS() {
	//pair<string, string> checkResult;
	for (int i = 0; i < packetsList.size(); i++)
	{
		bool found = false;
		if (ip_rules.find(packetsList[i].get_ip_source()) != ip_rules.end()) {
			result.push_back(ip_rules[packetsList[i].get_ip_source()]);
			found = true;
			break;
		}
		else if (ip_rules.find(packetsList[i].get_ip_destination()) != ip_rules.end()) {
			result.push_back(ip_rules[packetsList[i].get_ip_destination()]);
			found = true;
			break;
		}
		else if (port_rules.find(packetsList[i].Generate_PORT()) != port_rules.end()) {
			result.push_back(port_rules[packetsList[i].Generate_PORT()]);
			found = true;
			break;
		}
		else if (protocol_rules.find(packetsList[i].Generate_PROTOCOL()) != protocol_rules.end()) {
			result.push_back(protocol_rules[packetsList[i].Generate_PROTOCOL()]);
			found = true;
			break;
		}
		if (!found) result.push_back("ALLOW");
	}
}