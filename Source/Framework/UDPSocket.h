/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "NetworkSystem.h"

namespace Network
{
	class SocketAddress;

	class UDPSocket final
	{
		SOCKET udpSocket{};

	public:
		UDPSocket();
		explicit UDPSocket(SOCKET udpSocket);
		UDPSocket(const UDPSocket&) = delete;
		UDPSocket(UDPSocket&&) = delete;
		~UDPSocket();
		UDPSocket& operator=(const UDPSocket&) = delete;
		UDPSocket& operator=(UDPSocket&&) = delete;
	
		void Bind(SocketAddress& toAddress) const;
		void BindAny(unsigned short int port = 0) const;
		int SendTo(const char* message, int messageLenght, SocketAddress& toAddress) const;
		int SendToAll(const char* message, int messageLenght, SocketAddress& localAddress) const;
		int ReceiveFrom(char* messageOut, int messageLenght, SocketAddress& fromAddressOut) const;

		void SetNonBlocking() const;
		void SocketClose(SOCKET socket);
	};
}
