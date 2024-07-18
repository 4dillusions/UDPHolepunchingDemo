UDP Holepunching demo
<img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white">
<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"> 
<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0"><br>
<img src="https://img.shields.io/badge/-C++-blue?logo=cplusplus">
========================================================================================================
[![Alt text](https://img.youtube.com/vi/XKSSozKlYJM/0.jpg)](https://www.youtube.com/watch?v=XKSSozKlYJM)

Its a P2P UDP communication demo uses hole punching technology written in C++. It's working between remote machines behind the NAT or something like this. You need an address/port "share" server with public IP (there are free VPS machines, for example Google VPS) for hole punching.

How can it work?
-----------------
IPv4 is quite a good technology for local network. You can just use IP address directly and it is working perfectly for the communication each other. Unfortunately IPv4 is not a useful for connect remote machine, because the machine count is bigger than all IPv4 addresses. There are a lot of technologies for IP forwarding like NAT etc. Holepunch tecnology can detect which useful IP and port pair for a client behind the NAT or switch or something like this. Two clients connect to the server (dedicated public IP, port) and the server send IP and port information to all clients. After the information sharing two clients can communicate each other without server. 

Clone
------
Clone the entire project including the submodules:<br>
```bash
git clone --recurse-submodules https://github.com/4dillusions/UDPHolepunchingDemo
```

If the project is already cloned and you forgot to fetch the submodules (in UDPHolepunchingDemo folder):<br>
```bash
git submodule update --init --recursive
```

Instal, build and run
---------------------
<img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white">
<ul>
    <li>Install Visual Studio (Community is free)</li>
    <li>Set VS components: Desktop development with C++ (also check the CMake tools)</li>
    <li>Open UDPHolepunchingDemo folder with VS and build all</li>
    <li>Press F5 for run selected project</li>
</ul>

<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"> 
<ul>
    <li>
        Install dev environment: 
        <pre><code class="language-bash">sudo apt update
sudo apt install build-essential cmake</code></pre>
    </li>
    <li>
        Build project:
        <pre><code class="language-bash">cd UDPHolepunchingDemo
mkdir build
cd build
cmake ..
cmake --build .</code></pre>
        Run (server for example):
        <pre><code class="language-bash">./Bin/Server</code></pre>
    </li>
</ul>

<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0">
<ul>
    <li>
        Install dev environment: 
        <pre><code class="language-bash">xcode-select --install
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install cmake</code></pre>
    </li>
    <li>
        Build project:
        <pre><code class="language-bash">cd UDPHolepunchingDemo
mkdir build
cd build
cmake ..
cmake --build .</code></pre>
        Run (server for example):
        <pre><code class="language-bash">./Bin/Server</code></pre>
    </li>
</ul>

How to use it
-------------
<ul>
    <li>Run Server executable on the server what has dedicated public IP</li>
    <li>Run Client executable on two remote client machines separated networks</li>
    <li>Enter server address on clients</li>
    <li>The server send IPs for clients</li>
    <li>Two clients communicate each other</li>
</ul>
