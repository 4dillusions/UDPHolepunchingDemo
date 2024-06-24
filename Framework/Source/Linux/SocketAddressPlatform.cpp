/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "../SocketAddress.h"
#include "../IpV4Address.h"

namespace Network
{	
	string SocketAddress::GetLocalIp()
	{
		setenv("LANG", "C", 1);

		FILE* fp = popen("ip -f inet addr show | grep -w 'inet' | grep -v '127.0.0.1' | awk '{print $2}' | cut -d/ -f1 | head -n 1", "r");
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
