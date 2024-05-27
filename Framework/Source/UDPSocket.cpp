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

	void UDPSocket::BindAny(unsigned short int port) const
	{
		SocketAddress anyAddress(port);
		Bind(anyAddress);
	}

	int UDPSocket::SendTo(const char* message, int messageLenght, SocketAddress& toAddress) const
	{
		return sendto(udpSocket, message, messageLenght, 0, reinterpret_cast<sockaddr*>(toAddress.GetSockAddress()), sizeof(sockaddr_in));
	}

	int UDPSocket::SendToAll(const char* message, int messageLenght, SocketAddress& localAddress) const
	{
		const unsigned short int port = std::stoi(localAddress.GetPort());

		//doesn't work on all networks
		/*string ipStr = string(localAddress.GetIp());
		IpV4Address ip(ipStr);
		ip.addr4 = 255;
		SocketAddress address(port, ip);

		return SendTo(message, messageLenght, address);*/

		string ipStr = string(localAddress.GetIp());
		IpV4Address ip(ipStr);
		const int localIpAddr4 = ip.addr4;

		int result{};
		for (int ipAddr4 = 0; ipAddr4 < 255; ipAddr4++)
		{
			ip.addr4 = ipAddr4;
			SocketAddress address(port, ip);
			result = SendTo(message, messageLenght, address);
		}

		return result;
	}

	int UDPSocket::ReceiveFrom(char* messageOut, int messageLenght, SocketAddress& fromAddressOut) const
	{
		socklen_t fromLenght = sizeof(sockaddr_in);
		return recvfrom(udpSocket, messageOut, messageLenght, 0, reinterpret_cast<sockaddr*>(fromAddressOut.GetSockAddress()), &fromLenght);
	}
}
