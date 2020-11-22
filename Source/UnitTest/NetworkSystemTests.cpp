/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "CppUnitTest.h"
#include "Framework/NetworkSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(NetworkSystemTests)
	{
	public:		
		TEST_METHOD(StringSplitTest)
		{
			const string ip = "127.1.2.3";
			auto splitList = SplitString(ip, '.');
			Assert::AreEqual(std::stoi(splitList[0]), 127);
			Assert::AreEqual(std::stoi(splitList[1]), 1);
			Assert::AreEqual(std::stoi(splitList[2]), 2);
			Assert::AreEqual(std::stoi(splitList[3]), 3);
		}
	};
}
