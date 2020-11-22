/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "CppUnitTest.h"
#include "Framework/NetworkSystem.h"
#include "Framework/IpV4Address.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Network;

namespace UnitTest
{
	TEST_CLASS(IpV4AddressTests)
	{
	public:		
		TEST_METHOD(CreateAndConvertAddressTest)
		{
			const IpV4Address ip(196, 168, 1, 2);
			Assert::IsTrue(ip.ToString() == string("196.168.1.2"));

			const IpV4Address ip2(string("10.5.12.3"));
			Assert::IsTrue(ip2.addr1 == 10);
			Assert::IsTrue(ip2.addr2 == 5);
			Assert::IsTrue(ip2.addr3 == 12);
			Assert::IsTrue(ip2.addr4 == 3);
		}
	};
}
