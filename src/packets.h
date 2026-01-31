#pragma once
#include <string>
#include <random>
using namespace std;

class Packets {
private:
    string ip_source, ip_destination;
    string protocol;
    int port;
    static random_device rd;
    static mt19937 gen;

public:
    Packets();
    string Generate_IP();
    void generate_ip_source();
    string get_ip_source();
    void generate_ip_destination();
    string get_ip_destination();
    void Generate_PORT();
    int Get_PORT();
    void Generate_PROTOCOL();
    string Get_PROTOCOL();
};
