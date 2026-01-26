#pragma once
#include <string>
#include <random>
using namespace std;

class Packets {
private:
    string ip_source, ip_destination;
    string protocol;
    int port;
    random_device rd;
    mt19937 gen;

public:
    Packets();
    string Generate_IP();
    string get_ip_source();
    string get_ip_destination();
    int Generate_PORT();
    string Generate_PROTOCOL();
};
