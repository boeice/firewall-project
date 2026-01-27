#include "firewall.h"
#include <iostream>
#include <map>
using namespace std;

map<string, string> ip_rules;
ip_rules["192.168.1.1"] = "block";