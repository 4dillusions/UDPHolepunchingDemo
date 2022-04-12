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
#include "Framework/UDPSocket.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Network;

namespace UnitTest
{
	TEST_CLASS(UDPSocketTests)
	{
		// ReSharper disable CppMemberFunctionMayBeStatic
		void SendReceiveMessage(bool isToAll)
		// ReSharper restore CppMemberFunctionMayBeStatic
		{
			Net::Init();

			const int port = 24000;
			SocketAddress localAddress(port, IpV4Address(127, 0, 0, 1));
			const int MessageByteBufferSize = 1024;
			char messageByteBuffer[MessageByteBufferSize];
			const string Message(isToAll ? "Hello broadcast" : "Hello!");

			const auto receiverSocket = new UDPSocket;
			receiverSocket->SetNonBlocking();
			receiverSocket->BindAny(port);

			const auto senderSocket = new UDPSocket;
			senderSocket->BindAny();

			if (isToAll)
			{
				string localIP = SocketAddress::GetLocalIp();
				SocketAddress localPublicAddress(port, IpV4Address(localIP));
				senderSocket->SendToAll(Message.c_str(),  static_cast<int>(Message.length()), localPublicAddress);
			}
			else
				senderSocket->SendTo(Message.c_str(), static_cast<int>(Message.length()), localAddress);

			memset(messageByteBuffer, 0, MessageByteBufferSize);
			SocketAddress senderAddress{};
			receiverSocket->ReceiveFrom(messageByteBuffer, MessageByteBufferSize, senderAddress);

			Assert::IsTrue(string(messageByteBuffer) == Message);

			delete receiverSocket;
			delete senderSocket;

			Net::Cleanup();
		}
		
	public:		
		TEST_METHOD(SendReceiveMessageTest)
		{
			SendReceiveMessage(false);
		}

		TEST_METHOD(SendAllReceiveMessageTest)
		{
			SendReceiveMessage(true);
		}
	};
}
