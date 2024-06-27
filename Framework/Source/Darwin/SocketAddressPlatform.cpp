/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "../Unix/SocketAddressUnixPlatform.h"

namespace Network
{	
	string SocketAddress::GetLocalIp()
	{
		return GetLocalIpUnixPlatform("ifconfig | grep 'inet ' | grep -v 127.0.0.1 | awk '{print $2}'");
	}
}
