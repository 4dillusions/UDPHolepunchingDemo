/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "../SocketAddress.h"
#include "../IpV4Address.h"

namespace Network
{	
	string SocketAddress::GetLocalIp()
	{
		char host[256];
		gethostname(host, sizeof host);
		struct hostent* host_entry = gethostbyname(host);
		auto addrList = (host_entry->h_addr_list[1] != nullptr) ? host_entry->h_addr_list[1] : host_entry->h_addr_list[0];
		char* result = inet_ntoa(*reinterpret_cast<struct in_addr*>(addrList));

		return string(result);
	}
}
