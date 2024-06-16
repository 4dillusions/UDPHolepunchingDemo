/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "catch2/catch.hpp"
#include "NetworkSystem.h"
#include "SocketAddress.h"
#include "IpV4Address.h"
#include "Net.h"

using namespace Network;

TEST_CASE("SocketAddressTests", "[Network::SocketAddress]")
{
	SECTION("CreateAddressTest")
	{
		const SocketAddress Addr1(1234);
		REQUIRE(Addr1.GetIp() == string("0.0.0.0"));
		REQUIRE(Addr1.GetPort() == string("1234"));
		REQUIRE(Addr1.ToString() == string("0.0.0.0:1234"));

		const SocketAddress Addr2(23000, "196.168.12.2");
		REQUIRE(Addr2.GetIp() == string("196.168.12.2"));
		REQUIRE(Addr2.GetPort() == string("23000"));
		REQUIRE(Addr2.ToString() == string("196.168.12.2:23000"));

		const SocketAddress Addr3(23000, IpV4Address(196, 168, 12, 2));
		REQUIRE(Addr3.GetIp() == string("196.168.12.2"));
		REQUIRE(Addr3.GetPort() == string("23000"));
		REQUIRE(Addr3.ToString() == string("196.168.12.2:23000"));
	}

	SECTION("GetHostIpTest")
	{
		Net::Init();
		REQUIRE(SocketAddress::GetPublicIpFromHostName("4dillusions.com") == string("77.111.127.98"));

		const auto LocalIp = SocketAddress::GetLocalIp();
		REQUIRE(LocalIp != string(""));
		REQUIRE(LocalIp != string("127.0.0.1"));
		Net::Cleanup();
	}
}
