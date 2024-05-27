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

		FILE* fp = popen("ip -f inet addr show", "r");
		if (fp)
		{
			char* ip = nullptr, * delimiter;
			size_t count;
			while ((getline(&ip, &count, fp) > 0) && ip)
			{
				if ((ip = strstr(ip, "inet ")))
				{
					ip += 5;
					if ((delimiter = strchr(ip, '/')))
					{
						*delimiter = '\0';

						string result(ip);
						if (result != string("127.0.0.1"))
							return result;
					}
				}
			}
		}
		pclose(fp);
		
		return string();
	}
}
