/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "UDPSocket.h"
#include "IpV4Address.h"
#include "SocketAddress.h"

namespace Network
{
	UDPSocket::UDPSocket()
	{
		udpSocket = socket(AF_INET, SOCK_DGRAM, 0);

		if (udpSocket == INVALID_SOCKET)
			cout << "[ERROR] Can't create UDPSocket!\n";
		else
			cout << "OK - create UDPSocket\n";
	}

	UDPSocket::UDPSocket(SOCKET udpSocket) : udpSocket{ udpSocket }
	{ }

	UDPSocket::~UDPSocket()
	{
		SocketClose(udpSocket);
	}

	void UDPSocket::Bind(SocketAddress& toAddress) const
	{
		if (bind(udpSocket, reinterpret_cast<sockaddr*>(toAddress.GetSockAddress()), sizeof(sockaddr_in)) == SOCKET_ERROR)
			cout << "[ERROR] Can't bind UDP socket!\n";
		else
			cout << "OK - bind UDP socket\n";
	}

	int UDPSocket::SendTo(const char* message, int messageLenght, SocketAddress& toAddress) const
	{
		return sendto(udpSocket, message, messageLenght, 0, reinterpret_cast<sockaddr*>(toAddress.GetSockAddress()), sizeof(sockaddr_in));
	}

	int UDPSocket::SendToAll(const char* message, int messageLenght, SocketAddress& localAddress) const
	{
		const unsigned short int port = std::stoi(localAddress.GetPort());
		string ipStr = string(localAddress.GetIp());
		IpV4Address ip(ipStr);
		const int localIpAddr4 = ip.addr4;

		for (int ipAddr4 = 0; ipAddr4 < 255; ipAddr4++)
		{
			ip.addr4 = ipAddr4;

			if (ipAddr4 != localIpAddr4)
			{
				SocketAddress address(port, ip);
				SendTo(message, messageLenght, address);
			}
		}

		return 0;
	}

	int UDPSocket::ReceiveFrom(char* messageOut, int messageLenght, SocketAddress& fromAddressOut) const
	{
		socklen_t fromLenght = sizeof(sockaddr_in);
		return recvfrom(udpSocket, messageOut, messageLenght, 0, reinterpret_cast<sockaddr*>(fromAddressOut.GetSockAddress()), &fromLenght);
	}

	void UDPSocket::SetNonBlocking() const
	{
		#ifdef _WIN64
			u_long arg = 1;
			ioctlsocket(udpSocket, FIONBIO, &arg);
		#else
			int flags = fcntl(udpSocket, F_GETFL, 0);
			flags = flags | O_NONBLOCK;
			fcntl(udpSocket, F_SETFL, flags);
		#endif
	}

	// ReSharper disable CppMemberFunctionMayBeStatic
	void UDPSocket::SocketClose(SOCKET socket)
	// ReSharper restore CppMemberFunctionMayBeStatic
	{
		#ifdef _WIN64
			closesocket(socket);
		#else
			close(socket);
		#endif
	}
}
