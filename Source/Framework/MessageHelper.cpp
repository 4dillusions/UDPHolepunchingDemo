/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "MessageHelper.h"
#include "UDPSocket.h"
#include "SocketAddress.h"

namespace Network
{
	void MessageHelper::SendToRemoteMachine(UDPSocket* sock, SocketAddress& address, const string& message)
	{
		if (sock->SendTo(message.c_str(), message.size() + 1, address) == SOCKET_ERROR)
			cout << "UDP socket error in send!\n";
		else
			cout << "Sent message: " << message << " (" << address.ToString() << ")" << "\n";
	}
	
	string MessageHelper::ReceiveFromRemoteMachine(UDPSocket* sock, SocketAddress& address)
	{
		char messageBuffer[MessageBufferSize];
		const int bytesReceived = sock->ReceiveFrom(messageBuffer, MessageBufferSize, address);

		if (bytesReceived == SOCKET_ERROR)
			cout << "socket error\n";
		else
		{
			cout << "Received message: " << messageBuffer << " (" << address.ToString() << ")" << "\n";
			return string(messageBuffer);
		}

		return string();
	}
	
	std::string MessageHelper::ReceiveFromRemoteMachine(UDPSocket* sock)
	{
		SocketAddress remoteAddress{};
		return ReceiveFromRemoteMachine(sock, remoteAddress);
	}
}
