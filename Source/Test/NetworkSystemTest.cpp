/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "catch2/catch.hpp"
#include "Framework/NetworkSystem.h"

TEST_CASE("NetworkSystemTest", "[Network::NetworkSystem]")
{
	SECTION("StringSplitTest")
	{
		const string ip = "127.1.2.3";
		auto splitList = SplitString(ip, '.');

		REQUIRE(std::stoi(splitList[0]) == 127);
		REQUIRE(std::stoi(splitList[1]) == 1);
		REQUIRE(std::stoi(splitList[2]) == 2);
		REQUIRE(std::stoi(splitList[3]) == 3);
	}
}
