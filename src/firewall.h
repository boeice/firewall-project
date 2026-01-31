#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;

class Firewall {
private:
	map<string, string> ip_rules;
	map<int, string> port_rules;
	map<string, string> protocol_rules;
	vector<Packets> packetsList;
	vector<string> result; // action and reason
	//pair<string, string> checkResult;
public:
	Firewall();
	void CHECK_PACKETS();
	void PACKETS_LIST();
};