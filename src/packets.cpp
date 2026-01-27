#include "packets.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

Packets::Packets() : gen(rd()) {}

string Packets::Generate_IP() {
    uniform_int_distribution<> dist(1, 254);
    int RandomNumber = dist(gen);
    string ip = "192.168.1." + to_string(RandomNumber);
    return ip;
}

string Packets::get_ip_source() {
    ip_source = Generate_IP();
    return ip_source;
}

string Packets::get_ip_destination() {
    ip_destination = Generate_IP();
    return ip_destination;
}


int Packets::Generate_PORT() {
    uniform_int_distribution<> dist(1, 9999);
    int RandomNumber = dist(gen);
    port = RandomNumber;
    return port;
}

string Packets::Generate_PROTOCOL() {
    uniform_int_distribution<> dist(1, 7);
    int RandomNumber = dist(gen);
    if (RandomNumber == 1) { protocol = "HTTP"; port = 80; }
    else if (RandomNumber == 2) { protocol = "HTTPS"; port = 443; }
    else if (RandomNumber == 3) { protocol = "FTP"; port = 21; }
    else if (RandomNumber == 4) { protocol = "SSH"; port = 22; }
    else if (RandomNumber == 5) { protocol = "Telnet"; port = 23; }
    else if (RandomNumber == 6) { protocol = "SMTP"; port = 25; }
    else if (RandomNumber == 7) { protocol = "DNS"; port = 53; }
    else { protocol = "ICMP"; port = 0; }
    return protocol;
}
