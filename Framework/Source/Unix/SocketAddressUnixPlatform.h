/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "../SocketAddress.h"
#include "../IpV4Address.h"

namespace Network
{	
    string GetLocalIpUnixPlatform(const char* command)
    {
        setenv("LANG", "C", 1);

		FILE* fp = popen(command, "r");
		if (fp)
		{
			char* ip = nullptr;
			size_t count;
			getline(&ip, &count, fp);
			string result(ip);

			if (!result.empty() && result.back() == '\n')
				result.pop_back();

			return result;
		}
		pclose(fp);

		return string();
    }
}
