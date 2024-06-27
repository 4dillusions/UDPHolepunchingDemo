/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "catch2/catch.hpp"
#include "Framework/NetworkSystem.h"
#include "Framework/SocketAddress.h"
#include "Framework/IpV4Address.h"
#include "Framework/Net.h"
#include "Framework/UDPSocket.h"

using namespace Network;

void SendReceiveMessage(bool isToAll)
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

	REQUIRE(string(messageByteBuffer) == Message);

	delete receiverSocket;
	delete senderSocket;

	Net::Cleanup();
}

TEST_CASE("UDPSocketTest", "[Network::UDPSocket]")
{
	SECTION("SendReceiveMessageTest")
	{
		SendReceiveMessage(false);
	}

	SECTION("SendAllReceiveMessageTest")
	{
		SendReceiveMessage(true);
	}
}
