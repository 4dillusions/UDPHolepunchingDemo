/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "../UDPSocket.h"
#include "../IpV4Address.h"
#include "../SocketAddress.h"

namespace Network
{
	void UDPSocket::SetNonBlocking() const
	{
		int flags = fcntl(udpSocket, F_GETFL, 0);
		flags = flags | O_NONBLOCK;
		fcntl(udpSocket, F_SETFL, flags);
	}

	void UDPSocket::SocketClose(SOCKET socket)
	{
		close(socket);
	}
}
