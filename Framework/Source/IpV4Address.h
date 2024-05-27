/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "NetworkSystem.h"

namespace Network
{
	struct IpV4Address final
	{
		int addr1{ 0 }, addr2{ 0 }, addr3{ 0 }, addr4{ 0 };

		IpV4Address(int addr1, int addr2, int addr3, int addr4);
		explicit IpV4Address(string& ipAddress);

		[[nodiscard]] string ToString() const;
	};
}
