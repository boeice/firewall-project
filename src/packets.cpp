#include "packets.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

class Packets {
private:
	string ip;
	string protocol;
	int port;
	random_device rd;
	mt19937 gen;
public:
	Packets () : gen(rd()) {};
	string Generate_IP() {	
		uniform_int_distribution<> dist(1, 254);
		int RandomNumber = dist(gen);
		ip = "192.168.1." + to_string(RandomNumber);
		return ip;
	}
	int Generate_PORT() {
		uniform_int_distribution<> dist(1, 9999);
		int RandomNumber = dist(gen);
		port = RandomNumber;
		return port;
	}
	string Generate_PROTOCOL() {	
		uniform_int_distribution<> dist(1, 7);
		int RandomNumber = dist(gen);
		if (RandomNumber == 1) {
			protocol = "HTTP";
			port = 80;
			return protocol;
		}
		else if (RandomNumber == 2) {
			protocol = "HTTPS";
			port = 443;
			return protocol;
		}
		else if (RandomNumber == 3) {
			protocol = "FTP";
			port = 21;
			return protocol;
		}
		else if (RandomNumber == 4) {
			protocol = "SSH";
			port = 22;
			return protocol;
		}
		else if (RandomNumber == 5) {
			protocol = "Telnet";
			port = 23;
			return protocol;
		}
		else if (RandomNumber == 6) {
			protocol = "SMTP";
			port = 25;
			return protocol;
		}
		else if (RandomNumber == 7) {
			protocol = "DNS";
			port = 53;
			return protocol;
		}
		else {
			protocol = "ICMP";
			port = 0;
			return protocol;
		}
	}
};