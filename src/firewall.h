#include "packets.h"
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
	vector<string> result;
public:
	Firewall();
	void PACKETS_LIST(Packets& p);
	void CHECK_PACKETS(Packets& p);
	void PRINT_PACKETS();
};