#include "packets.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

random_device Packets::rd;
mt19937 Packets::gen(Packets::rd());
Packets::Packets() : port(0) {}

string Packets::Generate_IP() {
    uniform_int_distribution<> dist(1, 254);
    int RandomNumber = dist(gen);
    string ip = "192.168.1." + to_string(RandomNumber);
    return ip;
}

void Packets::generate_ip_source() {
    ip_source = Generate_IP();
}

string Packets::get_ip_source(){
    return ip_source;
}

void Packets::generate_ip_destination() {
    ip_destination = Generate_IP();
}
string Packets::get_ip_destination() {
    return ip_destination;
}


void Packets::Generate_PORT() {
    uniform_int_distribution<> dist(1, 9999);
    int RandomNumber = dist(gen);
    port = RandomNumber;
}

int Packets::Get_PORT() {
    return port;
}

void Packets::Generate_PROTOCOL() {
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
}

string Packets::Get_PROTOCOL() {
    return protocol;
}
