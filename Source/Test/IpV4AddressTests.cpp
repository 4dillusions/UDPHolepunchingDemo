/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "catch2/catch.hpp"
#include "Framework/IpV4Address.h"

using namespace Network;

TEST_CASE("IpV4AddressTest", "[Network::IpV4Address]")
{
	SECTION("CreateAndConvertAddressTest")
	{
		const IpV4Address ip(196, 168, 1, 2);
		REQUIRE(ip.ToString() == std::string("196.168.1.2"));

		const IpV4Address ip2(string("10.5.12.3"));
		REQUIRE(ip2.addr1 == 10);
		REQUIRE(ip2.addr2 == 5);
		REQUIRE(ip2.addr3 == 12);
		REQUIRE(ip2.addr4 == 3);
	}	
}
