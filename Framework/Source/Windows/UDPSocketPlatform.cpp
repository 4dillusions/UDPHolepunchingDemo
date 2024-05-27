/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "../UDPSocket.h"
#include "../IpV4Address.h"
#include "../SocketAddress.h"

namespace Network
{
	void UDPSocket::SetNonBlocking() const
	{
		u_long arg = 1;
		ioctlsocket(udpSocket, FIONBIO, &arg);
	}

	void UDPSocket::SocketClose(SOCKET socket)
	{
		closesocket(socket);
	}
}

