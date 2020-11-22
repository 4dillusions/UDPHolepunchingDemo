UDP Holepunching demo
===================
Its a P2P UDP communication demo uses hole punching technology written in C++. It's working between remote machines behind the NAT or something like this. You need an address/port "share" server with public IP (there are free VPS machines, for example Google VPS) for hole punching.


How can it work?
--------------
IPv4 is quite a good technology for local network. You can just use IP address directly and it is working perfectly for the communication each other. Unfortunately IPv4 is not a useful for connect remote machine, because the machine count is bigger than all IPv4 addresses. There are a lot of technologies for IP forwarding like NAT etc. Holepunch tecnology can detect which useful IP and port pair for a client behind the NAT or switch or something like this. Two clients connect to the server (public IP, port) and the server send IP and port information to all clients. After the information sharing two clients can communicate each other without server. 

How to use it
-------------
<ul>
<li>Run Server executable on the server what has public IP</li>
<li>Run Client executable on two remote client machines</li>
<li>Wnter server address on clients</li>
<li>The server send IPs for clients</li>
<li>Two clients communicate each other</li>
</ul>
