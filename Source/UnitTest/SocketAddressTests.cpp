/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "CppUnitTest.h"
#include "Framework/NetworkSystem.h"
#include "Framework/SocketAddress.h"
#include "Framework/IpV4Address.h"
#include "Framework/Net.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Network;

namespace UnitTest
{
	TEST_CLASS(SocketAddressTests)
	{
	public:		
		TEST_METHOD(CreateAddressTest)
		{
			const SocketAddress Addr1(1234);
			Assert::IsTrue(Addr1.GetIp() == string("0.0.0.0"));
			Assert::IsTrue(Addr1.GetPort() == string("1234"));
			Assert::IsTrue(Addr1.ToString() == string("0.0.0.0:1234"));

			const SocketAddress Addr2(23000, "196.168.12.2");
			Assert::IsTrue(Addr2.GetIp() == string("196.168.12.2"));
			Assert::IsTrue(Addr2.GetPort() == string("23000"));
			Assert::IsTrue(Addr2.ToString() == string("196.168.12.2:23000"));

			const SocketAddress Addr3(23000, IpV4Address(196, 168, 12, 2));
			Assert::IsTrue(Addr3.GetIp() == string("196.168.12.2"));
			Assert::IsTrue(Addr3.GetPort() == string("23000"));
			Assert::IsTrue(Addr3.ToString() == string("196.168.12.2:23000"));
		}

		TEST_METHOD(GetHostIpTest)
		{
			Net::Init();
			Assert::IsTrue(SocketAddress::GetPublicIpFromHostName("relay4.slayradio.org") == string("89.45.232.7"));

			const auto LocalIp = SocketAddress::GetLocalIp();
			Assert::IsTrue(LocalIp != string(""));
			Assert::IsTrue(LocalIp != string("127.0.0.1"));
			Net::Cleanup();
		}
	};
}
