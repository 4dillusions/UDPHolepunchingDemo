/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "IpV4Address.h"

using namespace std;

namespace Network
{
	IpV4Address::IpV4Address(int addr1, int addr2, int addr3, int addr4) : addr1{ addr1 }, addr2{ addr2 }, addr3{ addr3 }, addr4{ addr4 }
	{ }
	
	IpV4Address::IpV4Address(string& ipAddress)
	{
		auto address = SplitString(ipAddress, '.');
		addr1 = addr2 = addr3 = addr4 = 0;

		if (address.size() == 4)
		{
			addr1 = std::stoi(address[0]);
			addr2 = std::stoi(address[1]);
			addr3 = std::stoi(address[2]);
			addr4 = std::stoi(address[3]);
		}
	}
	
	string IpV4Address::ToString() const
	{
		string result;
		
		result += std::to_string(addr1) + ".";
		result += std::to_string(addr2) + ".";
		result += std::to_string(addr3) + ".";
		result += std::to_string(addr4);
		
		return result;
	}
}
