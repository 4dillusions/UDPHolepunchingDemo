/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "NetworkSystem.h"

namespace Network
{
	struct IpV4Address;
	
	class SocketAddress final
	{
		sockaddr_in* sockAddress;
		
	public:
		SocketAddress();
		SocketAddress(unsigned short int port);
		SocketAddress(unsigned short int port, const char* ip);
		SocketAddress(unsigned short int port, const IpV4Address& ip);
		SocketAddress(const SocketAddress&) = delete;
		SocketAddress(SocketAddress&&) = delete;
		~SocketAddress();
		SocketAddress& operator=(const SocketAddress&) = delete;
		SocketAddress& operator=(SocketAddress&&) = delete;

		[[nodiscard]] sockaddr_in* GetSockAddress() const;
		[[nodiscard]] string GetIp() const;
		[[nodiscard]] string GetPort() const;
		
		static string GetPublicIpFromHostName(const char* hostname);
		static string GetLocalIp();

		[[nodiscard]] string ToString() const;
	};
}
