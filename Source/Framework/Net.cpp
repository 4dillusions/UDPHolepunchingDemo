/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "Net.h"
#include "NetworkSystem.h"

namespace Network
{
	bool Net::Init()
	{
		#ifdef _WIN64
			WSAData wsData{};

			if (WSAStartup(MAKEWORD(2, 2), &wsData) == NOERROR)
			{
				cout << "OK - initialize network\n";
			}
			else
			{
				cout << "[ERROR] Can't initialize network!\n";
				return false;
			}
		#endif

		return true;
	}

	void Net::Cleanup()
	{
		#ifdef _WIN64
			cout << "Close network\n";
			WSACleanup();
		#endif
	}
}
