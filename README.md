\# Firewall Packet Filtering System



Simple C++ firewall simulation.  

Generates random packets, runs them through rules, decides their fate.



\## What it does



\- Generates random packets (IP / Port / Protocol)

\- Checks them against firewall rules

\- Applies one action per packet:  

&nbsp; \*\*ALLOW | BLOCK | DROP | REJECT | LOG\*\*

\- Prints the final decision clearly



\## Rules Logic



Rules are checked in this order:



1\. Source IP

2\. Destination IP

3\. Port

4\. Protocol



If nothing matches → \*\*ALLOW\*\*



\## Rules



\### IP Rules

\- `192.168.1.1` → LOG

\- `127.0.0.1` → DROP

\- `192.168.1.17` → BLOCK



\### Port Rules

\- `21` (FTP) → BLOCK

\- `23` (Telnet) → REJECT

\- `25` (SMTP) → DROP



\### Protocol Rules

\- `ICMP` → BLOCK

\- `HTTP` → REJECT

\- `Telnet` → BLOCK



\## How to Run

```bash

g++ main.cpp packets.cpp firewall.cpp -o firewall

./firewall

```



\## Project Structure



\- \*\*packets.h / packets.cpp\*\*  

&nbsp; Packet generation (IP, port, protocol)



\- \*\*firewall.h / firewall.cpp\*\*  

&nbsp; Rule checking and decision logic



\- \*\*main.cpp\*\*  

&nbsp; Program entry point



\## Sample Output

```

Packet 1: 192.168.1.45 -> 192.168.1.128 | Port: 80 | Protocol: HTTP | Action: REJECT

Packet 2: 192.168.1.89 -> 192.168.1.200 | Port: 443 | Protocol: HTTPS | Action: ALLOW

```



\## Tech



\- C++

\- STL (vector, map)

\- Random generation



\## Author



Sam



\## License



MIT

