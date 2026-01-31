#include <iostream>
#include "firewall.h"
#include "packets.h"
using namespace std;

int main() {
    cout << "################# --WELCOME-- #################\n";
    cout << "      ############# GLITCH ##############   \n";
    cout << "            ######### 3U ##########    \n";
    cout << "                     ###  \n";

    cout << "\n---------------------------------------------\n";
    cout << "\n      ---------------------------------       \n";
    cout << "\n         Firewall Project is starting...\n\n";

    Packets p1, p2, p3, p4, p5;
    Firewall f;
    p1.generate_ip_source();
    p1.generate_ip_destination();
    p1.Generate_PORT();
    p1.Generate_PROTOCOL();
    f.PACKETS_LIST(p1);
    f.CHECK_PACKETS(p1);

    p2.generate_ip_source();
    p2.generate_ip_destination();
    p2.Generate_PORT();
    p2.Generate_PROTOCOL();
    f.PACKETS_LIST(p2);
    f.CHECK_PACKETS(p2);

    p3.generate_ip_source();
    p3.generate_ip_destination();
    p3.Generate_PORT();
    p3.Generate_PROTOCOL();
    f.PACKETS_LIST(p3);
    f.CHECK_PACKETS(p3);

    p4.generate_ip_source();
    p4.generate_ip_destination();
    p4.Generate_PORT();
    p4.Generate_PROTOCOL();
    f.PACKETS_LIST(p4);
    f.CHECK_PACKETS(p4);

    p5.generate_ip_source();
    p5.generate_ip_destination();
    p5.Generate_PORT();
    p5.Generate_PROTOCOL();
    f.PACKETS_LIST(p5);
    f.CHECK_PACKETS(p5);

    f.PRINT_PACKETS();

    return 0;
}