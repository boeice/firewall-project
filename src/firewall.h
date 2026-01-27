#pragma once
#include <string>
#include <map>
using namespace std;

class Firewall {
private:
	map<string, string> ip_rules;
	map<int, string> port_rules;
	map<string, string> protocol_rules;
public:
	Firewall();
	string BLOCKLIST();
};