#include "firewall.h"
#include <iostream>
#include <string>
#include <map>
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
string Firewall::BLOCKLIST() {

}