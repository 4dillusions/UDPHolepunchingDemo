/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "SocketAddress.h"
#include "IpV4Address.h"

namespace Network
{
	SocketAddress::SocketAddress()
	{
		sockAddress = new sockaddr_in;
	}
	
	SocketAddress::SocketAddress(unsigned short int port) : SocketAddress()
	{
		sockAddress->sin_family = AF_INET;
		sockAddress->sin_port = htons(port);
		sockAddress->sin_addr.s_addr = htonl(INADDR_ANY); //sockAddress->sin_addr.S_un.S_addr = INADDR_ANY;
	}
	
	SocketAddress::SocketAddress(unsigned short int port, const char* ip) : SocketAddress(port)
	{
		inet_pton(AF_INET, ip, &sockAddress->sin_addr);
	}
	
	SocketAddress::SocketAddress(unsigned short int port, const IpV4Address& ip) : SocketAddress(port)
	{
		const int Multiply1 = 256 * 256 * 256;
		const int Multiply2 = 256 * 256;
		
		sockAddress->sin_addr.s_addr = htonl(ip.addr1 * Multiply1 + ip.addr2 * Multiply2 + ip.addr3 * 256 + ip.addr4); //inet_pton(AF_INET, ip.ToString().ToChar(), &sockAddress->sin_addr);
	}
	
	SocketAddress::~SocketAddress()
	{
		delete sockAddress;
	}
	
	sockaddr_in* SocketAddress::GetSockAddress() const
	{
		return sockAddress;
	}

	string SocketAddress::GetIp() const
	{
		const int HostNameLenght = 16;
		char host[HostNameLenght];
		memset(host, 0, HostNameLenght);
		inet_ntop(AF_INET, &sockAddress->sin_addr, host, HostNameLenght);

		int realLen = 0;
		for (char i : host)
		{
			if (i == '\00')
				break;

			realLen++;
		}

		string res(host);
		return res;
	}

	string SocketAddress::GetPort() const
	{
		const auto port = ntohs(sockAddress->sin_port);

		return std::to_string(port);
	}
	
	string SocketAddress::GetPublicIpFromHostName(const char* hostname)
	{
		addrinfo* addressInfo;
		if (getaddrinfo(hostname, nullptr, nullptr, &addressInfo) != 0)
		{
			cout << "[ERROR] Can't get ip from hostname! '" << hostname << "'";
			return string();
		}

		auto* address = reinterpret_cast<struct sockaddr_in*>(addressInfo->ai_addr);
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &address->sin_addr, str, INET_ADDRSTRLEN);

		return string(str);
	}

	string SocketAddress::GetLocalIp()
	{
		#ifdef _WIN64
			char host[256];
			gethostname(host, sizeof host);
			struct hostent* host_entry = gethostbyname(host);
			auto addrList = (host_entry->h_addr_list[1] != nullptr) ? host_entry->h_addr_list[1] : host_entry->h_addr_list[0];
			char* result = inet_ntoa(*reinterpret_cast<struct in_addr*>(addrList));

			return string(result);
		#else
			setenv("LANG", "C", 1);

			FILE* fp = popen("ip -f inet addr show", "r");
			if (fp)
			{
				char* ip = nullptr, * delimiter;
				size_t count;
				while ((getline(&ip, &count, fp) > 0) && ip)
				{
					if ((ip = strstr(ip, "inet ")))
					{
						ip += 5;
						if ((delimiter = strchr(ip, '/')))
						{
							*delimiter = '\0';

							string result(ip);
							if (result != string("127.0.0.1"))
								return result;
						}
					}
				}
			}
			pclose(fp);

			return string();
		#endif
	}
	
	string SocketAddress::ToString() const
	{
		return GetIp() + ":" + GetPort();
	}
}
